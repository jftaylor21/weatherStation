#include <FreqCount.h>
#include <Wire.h>
#include <hh10d.hpp>

#include <SparkFunMPL3115A2.h>
#include <mpl3115a2.hpp>

const int HH10D_OFFSET(7732);
const int HH10D_SENSITIVITY(402);

const float ELEVATION_IN_METERS(62.7);

void setup() {
  Serial.begin(9600);
  
  HH10D::initialize();
  
  MPL3115A2Sensor::initialize(ELEVATION_IN_METERS);
}

void loop() {
  Serial.print("Humidity: ");
  Serial.print(HH10D::getHumidity(HH10D_SENSITIVITY, HH10D_OFFSET));
  Serial.println("%");

  Serial.print("Temperature: ");
  Serial.print(MPL3115A2Sensor::getTemperatureF());
  Serial.println(" (F)");

  Serial.print("Barometric Pressure: ");
  Serial.print(MPL3115A2Sensor::getPressureHg());
  Serial.println(" (inHg)");

  Serial.println();
}
