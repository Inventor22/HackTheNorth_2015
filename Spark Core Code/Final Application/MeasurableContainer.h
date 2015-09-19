#ifndef MEASURABLECONTAINER_H
#define MEASURABLECONTAINER_H

#include "Sensor.h"
#include "application.h"

class MeasurableContainer {
  public:
    MeasurableContainer (int containerId, int ledPin, Sensor& _sensor);

    void init();
    void setContentsName(String name);
    void getContentsName();
    int getId();
    String getLevel();
    String getContents();
    void setLed(bool state);
    void update();

    Sensor& sensor;
    int minMass;
    int maxMass;
    String level;

  private:
    String contents;
    int id;
    int ledPin;
};

#endif
