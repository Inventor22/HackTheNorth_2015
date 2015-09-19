
#include "Sensor.h"
#include "MeasurableContainer.h"

const int boardLed = D7; // This is the LED that is already on your device.
const int updatePeriod = 1000;

const int NUM_CONTAINERS = 6;
const float MAX_GRAMS_SENSOR_HALF_INCH = 453.592 * 2;
const float MAX_GRAMS_SENSOR_4_MM = 1000;

char sensorUpdateStr[256];

uint32_t tNow = 0;
uint32_t tPrev = 0;

Sensor sensor[6] = {
  Sensor(0, MAX_GRAMS_SENSOR_HALF_INCH),
  Sensor(1, MAX_GRAMS_SENSOR_HALF_INCH),
  Sensor(2, MAX_GRAMS_SENSOR_HALF_INCH),
  Sensor(3, MAX_GRAMS_SENSOR_4_MM),
  Sensor(4, MAX_GRAMS_SENSOR_4_MM),
  Sensor(5, MAX_GRAMS_SENSOR_4_MM),
};

MeasurableContainer container[6] = {
  MeasurableContainer(0, D0, sensor[0]),
  MeasurableContainer(1, D1, sensor[1]),
  MeasurableContainer(2, D2, sensor[2]),
  MeasurableContainer(3, D3, sensor[3]),
  MeasurableContainer(4, D4, sensor[4]),
  MeasurableContainer(5, D5, sensor[5]),
};

void setup() {
  pinMode(boardLed, OUTPUT); // Our on-board LED is output as well
  tPrev = millis();
}

void loop() {
  tNow = millis();

  if (tNow - tPrev > updatePeriod) {
    for (int i = 0; i < NUM_CONTAINERS; i++) {
      //sensor[i].readSensor();
    }
  }

  if (changeDetected()) {
    for (int i = 0; i < NUM_CONTAINERS; i++) {
      char level[20] = "hello";
      /*char level[20] = container[i].getLevel().c_str();*/
      String a= container[i].getLevel().c_str();

      //sprintf(sensorUpdateStr, "{\"id\": %i, \"level\": %s}", container[i].getId(), level);
      Spark.publish("sensorUpdate",sensorUpdateStr,60,PRIVATE);
    }
  }
}

bool changeDetected() {
  for (int i = 0; i < NUM_CONTAINERS; i++) {
    if (sensor[i].changeDetected) {
      return true;
    }
  }
  return false;
}
