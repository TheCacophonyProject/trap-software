#ifndef LinearActuatorComponent_h
#define LinearActuatorComponent_h

#include "PinComponent.h"

class LinearActuatorComponent {
  public:
    LinearActuatorComponent(uint16_t* actuatorState, PinComponent* extendedSw, PinComponent* retractedSw, int forwardPin, int backPin);
    //LinearActuatorComponent(PinComponent*);
    void init();
    void update();

  private:
    void updateHBridge();
    uint16_t* _state;
    PinComponent* _extendedSw;
    PinComponent* _retractedSw;
    int _forwardPin;
    int _backPin;
};

#endif

