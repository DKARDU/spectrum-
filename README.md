<a href="https://youtu.be/QWxicTpqoOg">
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/MP3.jpg" />
</a></br></br>
Today we will make a 32 band LED Audio Music Spectrum Analyzer at Home using Arduino, it can shows frequency spectrum and play muisc at the same time.
Note</br>
The max7219LED must be connected in front of the 100k resistor, otherwise the noise of the speaker will be very high.
</br></br>

<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/Circuit%20diagram.jpg" /></br>
Which you will need following parts:</br></br>
The following parts were used in this project:</br>
Arduino Nano, https://amzn.to/3hB8Pwf</br>
Two 100K resistors, https://amzn.to/2OSGlBW</br>
Three 4.7K resistors, https://amzn.to/2OSGlBW</br>
Two 104 capacitances (104 = 100000pF = 100nF = 0.10μF), </br>
4 in 1 Max7219 dot matrix led,  https://amzn.to/3jcCL2G</br>
PJ-320D 3.5MM audio socket, </br>
Jumper wires, https://amzn.to/3jCHhZd</br>
Breadboard, https://amzn.to/33yEavN</br>
3W PAM8403 Class D Audio Amplifier and Two speakers, </br>
The version of Arduino IDE used is 1.8.12
</br></br>

Production

1.	Install Library file: Open "Tools"-"Library Manager" in the Arduino development software, then search for arduinoFFT, MD_MAX72xx and Adafruit_GFX, then install them.
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/01.jpg" /></br>
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/02.jpg" /></br>
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/03.jpg" /></br>
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/04.jpg" /></br>
2. Install Library file: Open "Sketch"- "Include Library"-"Add .ZIP Library……" in the Arduino development software, then add Max72Panel.zip
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/05.jpg" /></br>
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/06.jpg" /></br>
3.	Select the development board as Arduino Nano, this is choose the right.
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/07.jpg" /></br>

4.	Select the processor as ATmega328P(Old Bootloader), this is to choose the right.
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/08.jpg" /></br>

5.	Then select the port, this port should be the same as what you see in the device manager, so that you can burn the code into the development board.
<img src="http://dkardu.oss-cn-hongkong.aliyuncs.com/32band/09.jpg" /></br>
