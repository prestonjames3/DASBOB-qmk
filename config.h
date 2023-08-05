#pragma once

// #include "config_common.h"  //?????

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

// GP14 is now GP5
#define DIRECT_PINS { \
    { GP13, GP28, GP12, GP29, GP0 }, \
    { GP22, GP5, GP26, GP4, GP27 }, \
    { GP21, GP23, GP7, GP20, GP6 }, \
    { GP16, GP9, GP8, NO_PIN, NO_PIN } \
}
/*
    { D5, F5, B7, F4, D3 }, \
    { B1, C6, F7, D4,  F6}, \
    { B6, B2, E6, B3, D7 }, \
    { F0, B5, B4, NO_PIN, NO_PIN } \
*/
#define DIRECT_PINS_RIGHT {  \
    { GP0, GP29, GP12, GP28, GP13 }, \
    { GP27, GP4, GP26, GP5, GP22}, \
    { GP6, GP20, GP7, GP23, GP21 }, \
    { GP8, GP9, GP16, NO_PIN, NO_PIN } \
}
/*
    { D3, F4, B7, F5, D5 }, \
    { F6, D4, F7, C6, B1}, \
    { D7, B3, E6, B2, B6 }, \
    { B4, B5, F0, NO_PIN, NO_PIN } \
*/


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5



/* Serial Config */
#define USE_SERIAL

// OLD
// #define SERIAL_USART_TX_PIN GP1

// NEW
#define SOFT_SERIAL_PIN GP1
#define SERIAL_USE_MULTI_TRANSACTION
#define SERIAL_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the Serial implementation uses the PIO0 peripheral



#define MASTER_LEFT

/* I2C Pin mapping */
//#define I2C1_SDA_PIN GP7
//#define I2C1_SCL_PIN GP6
//#define I2C1_CLOCK_SPEED 400000
//#define I2C_DRIVER I2CD2

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100



#define TAPPING_TERM 205 //235//275  //*****
#define PERMISSIVE_HOLD  //*****
// #define IGNORE_MOD_TAP_INTERRUPT  //*****
// #define HOLD_ON_OTHER_KEY_PRESS  //*****/*****
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY  //*****/*****
// #define TAPPING_FORCE_HOLD  //*****
// #define TAPPING_FORCE_HOLD_PER_KEY  //*****
#define QUICK_TAP_TERM TAPPING_TERM  // NOTE: QUICK_TAP_TERM = TAPPING_TERM is the default  //*****/*****
#define QUICK_TAP_TERM_PER_KEY  //*****/*****
//#define RETRO_TAPPING  //*****/*****
 //Normally: Holding and releasing a dual function key without pressing another key will result in nothing happening.
 //With Retro Tapping: Releasing a dual function key without pressing another will send the original keycode,
 //even if it is outside the tapping term.



#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET  //?????
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U  //?????





#define USB_VBUS_PIN 19
#define AUDIO_PWM_DRIVER PWMD2
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#define AUDIO_STATE_TIMER GPTD4
#define AUDIO_PIN GP5
#ifdef AUDIO_ENABLE
    #define AUDIO_INIT_DELAY
    #define AUDIO_CLICKY
    #define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f
    #define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

#define STARTUP_SOUND E__NOTE(_E6), E__NOTE(_A6), ED_NOTE(_E7),
