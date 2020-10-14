#include <arduinoFFT.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>
#define SAMPLES 64
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES  4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10
#define  xres 32
#define  yres 8
int MY_ARRAY[] = {0, 1, 3, 7, 15, 31, 63, 127, 255};
double vReal[SAMPLES];
double vImag[SAMPLES];
char data_avgs[xres];
int yvalue;
int displaycolumn , displayvalue;
int peaks[xres];
int pinCS = 10;
MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
arduinoFFT FFT = arduinoFFT();
void setup() {
  ADCSRA = 0b11100101;
  ADMUX = 0b00000000;
  mx.begin();
  delay(50);
}
void loop() {

    
    for (int i = 0; i < SAMPLES; i++)
    {
      while (!(ADCSRA & 0x10));
      ADCSRA = 0b11110101 ;
      int value = ADC - 512 ;
      vReal[i] = value / 8;
      vImag[i] = 0;
    }
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
    int step = (SAMPLES / 2) / xres;
    int c = 0;
    for (int i = 0; i < (SAMPLES / 2); i += step)
    {
      data_avgs[c] = 0;
      for (int k = 0 ; k < step ; k++) {
        data_avgs[c] = data_avgs[c] + vReal[i + k];
      }
      data_avgs[c] = data_avgs[c] / step;
      c++;
    }

    for (int i = 0; i < xres; i++)
    {
      data_avgs[i] = constrain(data_avgs[i], 0, 40);
      data_avgs[i] = map(data_avgs[i], 0, 40, 0, yres);
      yvalue = data_avgs[i];

      peaks[i] = peaks[i] - 1;
      if (yvalue > peaks[i])
        peaks[i] = yvalue ;
      yvalue = peaks[i];
      displayvalue = MY_ARRAY[yvalue];
      displaycolumn = 31 - i;
      mx.setColumn(displaycolumn, displayvalue);
    }
  }
