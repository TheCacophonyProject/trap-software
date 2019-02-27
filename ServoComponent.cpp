
#include "Arduino.h"
#include "ServoComponent.h"
#include <Servo.h>
#include "Config.h"


ServoComponent::ServoComponent(uint16_t* val, int pin) {
  _val = val;
  _pin = pin;
}

void ServoComponent::update() {
  #if DEBUG_SERIAL
  Serial.print("Update servo on pin: ");
  Serial.print(_pin);
  Serial.print(" at address: ");
  Serial.println(*_val);
  #endif
  _servo.write(constrain(*_val, 0, 180));
}

void ServoComponent::init() {
  #if DEBUG_SERIAL
  Serial.println("Init servo");
  #endif
  _servo.attach(_pin);
}

