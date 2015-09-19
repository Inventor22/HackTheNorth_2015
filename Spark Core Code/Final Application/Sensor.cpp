#include "Sensor.h"

Sensor::Sensor(int _pin, int _maxLoadMeasurable) : pin(_pin), maxLoadMeasurable(_maxLoadMeasurable) {
  this->readingSum = 0;
  this->averageReading = 0;
  this->readingIndex = 0;
  this->lastAverage = 0;
  this->changeDetected = false;
}

void Sensor::readSensor() {
  readingSum -= reading[readingIndex];
  reading[readingIndex] = analogRead(pin);

  readingSum += reading[readingIndex++];

  if (readingIndex >= numReadings) {
    readingIndex = 0;
  }

  averageReading = readingSum / numReadings;

  if (abs(averageReading - lastAverage) > changeDetectedThreshold) {
    lastAverage = averageReading;
    changeDetected = true;
  } else {
    changeDetected = false;
  }
}

int Sensor::getRawReading() {
  return averageReading;
}

int Sensor::getMassInGrams() {
  return map(averageReading, 1023, 0, 0, maxLoadMeasurable);
}
