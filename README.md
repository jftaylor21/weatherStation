# weatherStation
Polls temperature, humidity, and pressure sensors from Arduino and posts data 
to ThingSpeak channel: https://thingspeak.com/channels/61394

Arduino Dependencies:

1. Wire: Comes with Arduino IDE

2. FreqCount: https://github.com/PaulStoffregen/FreqCount

3. Sparkfun's MPL3115A2 library: https://github.com/sparkfun/MPL3115A2_Breakout

4. HH10D: https://github.com/jftaylor21/hh10d

5. mpl3115a2: https://github.com/jftaylor21/mpl3115a2

C++ Dependencies:

1. QT (minimum version 5.1): http://www.qt.io/

Instructions:

1. Open arduino/weatherStation/weatherStation.ino in Arduino IDE.

2. Build project and load onto Arduino.

3. Add wiring instructions for Arduino sensors here.

4. Open weatherstation.pro in QT Creator IDE.

5. Build weatherstation.pro.

6. Copy weatherstation-example.ini to weatherstation.ini.

7. Edit weatherstation.ini and configure serial port and ThingSpeak channel API
key.

8. Start WeatherStation2ThingSpeak.exe.

9. If data is successfully read from serial port, you will see console output
with temperature, pressure, and humidity.

10. If data is written successfully, you will see new data appear on ThingSpeak
every 30 seconds.
