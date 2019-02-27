#ifndef ServoComponent_h
#define ServoComponent_h

#include <Servo.h>

class ServoComponent {
  public:
    ServoComponent(uint16_t* val, int pin);
    void init();
    void update();

  private:
    uint16_t*  _val;
    int _pin;
    Servo _servo;
};

#endif

