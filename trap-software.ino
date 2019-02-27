
#include <ModbusRtu.h>
#include "ServoComponent.h"
#include "PinComponent.h"
#include "LinearActuatorComponent.h"
#include "Config.h"

// data array for modbus network sharing
uint16_t au16data[11] = { DEVICE_TYPE_ID, DEVICE_VERSION, 0, 0, 2, 0, 0, 0, 0, 0, 0 };

#define SERVO_COUNT 2
ServoComponent servos[SERVO_COUNT] {
  ServoComponent(&au16data[SERVO_1_ADDRESS], SERVO_1_PIN),
  ServoComponent(&au16data[SERVO_2_ADDRESS], SERVO_2_PIN)
};

#define PIN_COUNT 4
PinComponent pins[PIN_COUNT] {
  PinComponent(&au16data[PIR_1_ADDRESS], PIR_1_PIN, INPUT, true),
  PinComponent(&au16data[PIR_2_ADDRESS], PIR_2_PIN, INPUT, true),
  PinComponent(&au16data[ENABLE_6V_ADDRESS], ENABLE_6V_PIN, OUTPUT, true),
  PinComponent(&au16data[ENABLE_12V_ADDRESS], ENABLE_12V_PIN, OUTPUT, true)
};

PinComponent ex(&au16data[ACTUATOR_EXTENDED_ADDRESS], ACTUATOR_EXTENDED_PIN, INPUT_PULLUP, true);
PinComponent rt(&au16data[ACTUATOR_RETRACTED_ADDRESS], ACTUATOR_RETRACTED_PIN, INPUT_PULLUP, true);

LinearActuatorComponent linearActuator(
  &au16data[ACTUATOR_STATE_ADDRESS],
  &ex,
  &rt,
  ACTUATOR_FORWARD_PIN,
  ACTUATOR_BACK_PIN
  );

/**
 *  Modbus object declaration
 *  u8id : node id = 0 for master, = 1..247 for slave
 *  u8serno : serial port (use 0 for Serial)
 *  u8txenpin : 0 for RS-232 and USB-FTDI 
 *               or any pin number > 1 for RS-485
 */
Modbus rs485Slave(SLAVE_ID,0,RX_SEND_PIN); // this is slave @1 and RS-485

void setup() {
  #if DEBUG_SERIAL
  Serial.begin(38400);
  #else 
  rs485Slave.begin(BAUD_RATE);
  #endif
  
  for (int i = 0; i < PIN_COUNT; i++) {
    pins[i].init();
  }
  for (int i = 0; i < SERVO_COUNT; i++) {
    servos[i].init();
  }
  linearActuator.init();
}

void loop() {
  #if DEBUG_SERIAL
  delay(1000);
  #else
  rs485Slave.poll( au16data, 16 );
  #endif
  for (int i = 0; i < PIN_COUNT; i++) {
    pins[i].update();
  }
  for (int i = 0; i < SERVO_COUNT; i++) {
    servos[i].update();
  }
  linearActuator.update();
}




