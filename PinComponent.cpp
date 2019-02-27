
#include "Arduino.h"
#include "PinComponent.h"
#include "Config.h"

PinComponent::PinComponent() {}
 
PinComponent::PinComponent(uint16_t* val, int pin, int mode, boolean digital) {
  _val = val;
  _pin = pin;
  _mode = mode;
  _digital = digital;
}

void PinComponent::init() {
  #if DEBUG_SERIAL
  Serial.print("Init Pin: ");
  Serial.println(_pin);
  #endif
  pinMode(_pin, _mode);
  if (_mode == OUTPUT) {
    digitalWrite(_pin, LOW);
  }
}

void PinComponent::update() {
  
  
  if (_digital && _mode == OUTPUT) {
    digitalWrite(_pin, constrain(*_val, 0, 1));
  } 
  else if (_digital && (_mode == INPUT_PULLUP || _mode == INPUT)) {
    *_val = digitalRead(_pin);
  } 
  else if (!_digital && _mode == OUTPUT) {
    analogWrite(_pin, constrain(*_val, 0, 1023));
  } 
  else if (!_digital && (_mode == INPUT_PULLUP || _mode == INPUT)) {
    *_val = analogRead(_pin);
  }
  #if DEBUG_SERIAL
  Serial.print("Update Pin: ");
  Serial.print(_pin);
  Serial.print(" with val: ");
  Serial.println(*_val);
  #endif
}


