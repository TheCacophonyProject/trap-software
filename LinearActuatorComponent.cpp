// For controlling a linear actuator

#include "Arduino.h"
#include "LinearActuatorComponent.h"
#include "PinComponent.h"
#include "Config.h"

#define NOT_MOVING      0
#define MOVING_FORWARD  1
#define MOVING_BACK     2

LinearActuatorComponent::LinearActuatorComponent(uint16_t* actuatorState, PinComponent* extendedSw, PinComponent* retractedSw, int forwardPin, int backPin) {
  _state = actuatorState;
  _extendedSw = extendedSw;
  _retractedSw = retractedSw;
  _forwardPin = forwardPin;
  _backPin = backPin;
}

void LinearActuatorComponent::init() {
  pinMode(_forwardPin, OUTPUT);
  pinMode(_backPin, OUTPUT);
  digitalWrite(_forwardPin, LOW);
  digitalWrite(_backPin, HIGH);
  
  _extendedSw->init();
  _retractedSw->init();
  
}

void LinearActuatorComponent::update() {
  switch(*_state) {
    case NOT_MOVING:
      break;
    case MOVING_FORWARD:
      if (digitalRead(_extendedSw->_pin) == LOW) {
        *_state = NOT_MOVING;
      }
      break;
    case MOVING_BACK:
      if (digitalRead(_retractedSw->_pin) == LOW) {
        *_state = NOT_MOVING;
      }
      break;
    default:
      break;
  }

  updateHBridge();
  _extendedSw->update();
  _retractedSw->update();
  #if DEBUG_SERIAL
  Serial.print("Actuator state: ");
  Serial.println(*_state);
  #endif
}

void LinearActuatorComponent::updateHBridge() {
  switch(*_state) {
    case NOT_MOVING:
      digitalWrite(_forwardPin, LOW);
      digitalWrite(_backPin, LOW);
      break;
    case MOVING_FORWARD:
      digitalWrite(_forwardPin, HIGH);
      digitalWrite(_backPin, LOW);
      break;
    case MOVING_BACK:
      digitalWrite(_forwardPin, LOW);
      digitalWrite(_backPin, HIGH);
      break;
     default:
      digitalWrite(_forwardPin, LOW);
      digitalWrite(_backPin, LOW);
      break;
  }
}

