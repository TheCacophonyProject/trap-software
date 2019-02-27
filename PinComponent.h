#ifndef PinComponent_h
#define PinComponent_h

class PinComponent {
  public:
    PinComponent();
    PinComponent(uint16_t* val, int pin, int mode, boolean digital);
    void init();
    void update();
    int _pin;
    
  private:
    uint16_t*  _val;
    int _mode;
    boolean _digital;
};

#endif

