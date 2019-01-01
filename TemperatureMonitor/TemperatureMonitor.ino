#include "Wire.h"
#include <Adafruit_BMP085.h>

void getTemperatureData();

const int BAUD_RATE = 9600;       // Fixed Baud Rate
const int GREEN_LED = 8;          // Green LED Pin
const int RED_LED   = 9;          // Red   LED Pin
const long INTERVAL = 1000;       // Time for each iteration


const int pin1 = 0;
const int pin2 = 1;


int ledState = LOW;               // Should LEDs blink or not, LOW = No power, HIGH = 5v
unsigned long previousMillis = 0; // Time Passed Since Start  

Adafruit_BMP085 bmp;              // BMP180 Sensor Object

void setup() {
  if(!bmp.begin()){
    Serial.println("Could not find a valid BMP085/BMP180 sensor");
    while(1){}
  }
  
  Serial.begin(BAUD_RATE);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED,   OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis(); 
  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }    
    getTemperatureData();
  }m 
}

void getTemperatureData()
{
  float pressure           = bmp.readPressure();                 // Reading the Pressure From Sensor in Millibars
  float seaLevelPressure   = bmp.readSealevelPressure();         // Reading the Calculated Pressure From Sensor in Pascals
  float calculatedAltitude = bmp.readAltitude(seaLevelPressure); // Reading the Calucalted Altitude Based on Pressure in meters
  float temperature        = bmp.readTemperature();              // Reading the Temperature Value From Sensor in Celsius

  float upper_temperature_threshold = 25.0; // Example Value of the Upper Temperature Value
  float lower_temperature_threshold = 20.0; // Example Value of the Lower Temperature Value
  
  Serial.println(temperature);
  if(temperature < lower_temperature_threshold || temperature > upper_temperature_threshold)
  {
    digitalWrite(RED_LED, ledState);   // If temperature is out of Threshold, Blink Red LED
    digitalWrite(GREEN_LED, LOW);      // And Turn Off Green LED if it Was Blinking Before
  }
  else
  {
    digitalWrite(GREEN_LED, ledState); // If Temperature is Within the Thresholds, Blink Green LED
    digitalWrite(RED_LED, LOW);        // And Turn Off Red LED if it Was Blinking Before
  }
}
