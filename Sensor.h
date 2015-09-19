#ifndef SENSOR_H
#define SENSOR_H

#include "application.h"

class Sensor {
  public:
    Sensor(int _pin, int _maxLoadMeasurable);
    void readSensor();
    int getRawReading();
    int getMassInGrams();

  public:
    bool changeDetected;

  private:
    static const int numReadings = 10;
    static const int changeDetectedThreshold = 100;
    const int maxLoadMeasurable;
    const int pin;

    int readingIndex;
    int reading[numReadings];
    int readingSum;
    int averageReading;
    int lastAverage;
};

#endif
