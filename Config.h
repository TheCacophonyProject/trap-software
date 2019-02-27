#define DEBUG_SERIAL false

// Device config
#define DEVICE_TYPE_ID 1  // 1 is for a trap
#define DEVICE_VERSION 1  // Version 1 the trap software

// Trap pin config
#define PIR_1_PIN               2
#define PIR_2_PIN               3
#define RX_SEND_PIN             4
#define ACTUATOR_EXTENDED_PIN   7
#define ACTUATOR_RETRACTED_PIN  8
#define SERVO_1_PIN             10
#define SERVO_2_PIN             11
#define ACTUATOR_BACK_PIN       12
#define ACTUATOR_FORWARD_PIN    13
#define ENABLE_6V_PIN           A2       
#define ENABLE_12V_PIN          A3       



// RS-485 config
#define SLAVE_ID  1
#define BAUD_RATE 9600
#define TXEN      4 // assign the Arduino pin that must be connected to RE-DE RS485 transceiver
// RS-485 data array config
#define PIR_1_ADDRESS               2
#define PIR_2_ADDRESS               3
#define ACTUATOR_STATE_ADDRESS      4
#define ACTUATOR_EXTENDED_ADDRESS   5
#define ACTUATOR_RETRACTED_ADDRESS  6
#define SERVO_1_ADDRESS             7
#define SERVO_2_ADDRESS             8
#define ENABLE_6V_ADDRESS           9
#define ENABLE_12V_ADDRESS          10
