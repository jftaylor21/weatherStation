#include <FreqCount.h>
#include <Wire.h>
#include <hh10d.hpp>

#include <SparkFunMPL3115A2.h>
#include <mpl3115a2.hpp>

#include <ThingSpeak.h>

#include <SPI.h>
#include <Ethernet.h>
EthernetClient ethernetClient;

#include "weatherStationConstants.h"

void setup() {
  Serial.begin(9600);
  
  HH10D::initialize();
  
  MPL3115A2Sensor::initialize(ELEVATION_IN_METERS);

  Ethernet.begin(MAC_ADDRESS);

  ThingSpeak.begin(ethernetClient);
}

void loop() {
  float tempF(MPL3115A2Sensor::getTemperatureF());
  float pressureHg(MPL3115A2Sensor::getPressureHg());
  float humidity(HH10D::getHumidity(HH10D_SENSITIVITY, HH10D_OFFSET));
  
  Serial.print("T = ");
  Serial.println(tempF);
  Serial.print("P = ");
  Serial.println(pressureHg);
  Serial.print("H = ");
  Serial.println(humidity);

  ThingSpeak.setField(1, tempF);
  ThingSpeak.setField(2, pressureHg);
  ThingSpeak.setField(3, humidity);
  ThingSpeak.writeFields(THINGSPEAK_CHANNEL, THINGSPEAK_API_KEY);

  Ethernet.maintain();
  delay(LOOP_DELAY);
}
