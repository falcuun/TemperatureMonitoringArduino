### TemperatureMonitoringArduino
This Arduino Sketch reads the output given by BMP180 temperature sensor.
After reading the data, it calculates the raw temperature value and converts it to Celsius;
It also reads the raw Pressure value in millibars and based on the pressure levels it calculates the 
current altitude of the Sensor itself. 
Beginning altitude value is set by the user, for more correct measurements. 
  
  After all data is collected, it is then forwarded to Serial port, via Serial.print() for further processing. 
  
  It also has LED Blinking function if the temperature crosses either of the thresholds (H/L)
  
### Wiring
    - VIN - 3.3V pin
    - GND - GND pin
    - SDA - pin A4
    - SCL - pin A5


### Run

	To run this Sketch, you will need Arduino IDE and an available USB Port on your PC.
    	* Open Arduino IDE and copy the code inside the editor
    	* Plug in the Arduino with USB-cable and in Arduino IDE Select COM Port where Arduino is Plugged
    	* Hit Upload Button.
   
   You can also use Visual Studio Code with Arduino Extension. Process of selecting the port is same
   And to upload it just hit CTR + ALT + U on your keyboard. 

### Reading the Data
To read the values of the temperateure and pressure, you will need a Serial monitor
Arduino IDE and VS Code have build in Monitors, or you can download one from:
[HERE](https://github.com/falcuun/SimpleArduinoMonitor)  

 
