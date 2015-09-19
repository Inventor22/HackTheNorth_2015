#include "MeasurableContainer.h"

MeasurableContainer::MeasurableContainer (int containerId, int ledPin, Sensor& _sensor) :  sensor(_sensor) {
  this->contents = "Empty";
  this->id = containerId;
  this->ledPin = ledPin;
}

void MeasurableContainer::init() {
  pinMode(this->ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

void MeasurableContainer::setContentsName(String name) {
  this->contents = name;
}

int MeasurableContainer::getId() {
  return this->id;
}

String MeasurableContainer::getLevel() {
  return this->level;
}


String MeasurableContainer::getContents() {
  return this->contents;
}

void MeasurableContainer::setLed(bool state) {
  digitalWrite(ledPin, state);
}

void MeasurableContainer::update() {
  this->sensor.readSensor();

  if (this->sensor.changeDetected) {
    switch(map(this->sensor.getRawReading(), this->minMass, this->maxMass, 0, 3)) {
      case 0:
        level = "Empty"; break;
      case 1:
        level = "Low"; break;
      case 2:
        level = "Half full"; break;
      case 3:
        level = "Full"; break;
      default:
        break;
    }
  }
}
