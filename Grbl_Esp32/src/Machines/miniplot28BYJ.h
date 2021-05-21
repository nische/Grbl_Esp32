#pragma once
// clang-format off

/*
    miniplot28BYJ.h
    Part of Grbl_ESP32

    Template for a machine configuration file.

    2020    - Mitch Bradley

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/

// This contains a long list of things that might possibly be
// configured.  Most machines - especially simple cartesian machines
// that use stepper motors - will only need to define a few of the
// options herein, often just the pin assignments.

// Pin assignments depend on how the ESP32 is connected to
// the external machine.  Typically the ESP32 module plugs into
// an adapter board that wires specific ESP32 GPIO pins to
// other connectors on the board, such as Pololu sockets for
// stepper drivers or connectors for external drivers, limit
// pins, spindle control, etc.  This file describes how those
// GPIO pins are wired to those other connectors.

// Some machines might choose to use an adapter board in a
// non-standard way, for example a 3-axis board might have axes
// labeled XYZ, but the machine might have only 2 axes one of which is
// driven by two ganged motors.  In that case, you would need
// a custom version of this file that assigns the pins differently
// from the adapter board labels.

// In addition to pin assignments, many other aspects of Grbl
// can be configured, such as spindle speeds, special motor
// types like servos and unipolars, homing order, default values
// for $$ settings, etc.  A detailed list of such options is
// given below.

// Furthermore, it is possible to implement special complex
// behavior in custom C++ code, for non-Cartesian machines,
// unusual homing cycles, etc.  See the Special Features section
// below for additional instructions.

// === Machine Name
// Change TEMPLATE to some name of your own choosing.  That name
// will be shown in a Grbl startup message to identify your
// configuration.

#define MACHINE_NAME            "MINIPLOTTER_28BYJ"

// If your machine requires custom code as described below in
// Special Features, you must copy Custom/custom_code_template.cpp
// to a new name like Custom/my_custom_code.cpp, implement the
// functions therein, and enable its use by defining:
// #define CUSTOM_CODE_FILENAME "Custom/my_custom_code.cpp"

// === Number of axes

// You can set the number of axes that the machine supports
// by defining N_AXIS.  If you do not define it, 3 will be
// used.  The value must be at least 3, even if your machine
// has fewer axes.
#define N_AXIS 3


// == Pin Assignments

#define USE_UNIPOLAR
 
#define X_UNIPOLAR  
#define X_PIN_PHASE_0   GPIO_NUM_23
#define X_PIN_PHASE_1   GPIO_NUM_22
#define X_PIN_PHASE_2   GPIO_NUM_21
#define X_PIN_PHASE_3   GPIO_NUM_19     
 
#define Y_UNIPOLAR
#define Y_PIN_PHASE_0   GPIO_NUM_18
#define Y_PIN_PHASE_1   GPIO_NUM_17
#define Y_PIN_PHASE_2   GPIO_NUM_16
#define Y_PIN_PHASE_3   GPIO_NUM_15

#define Z_UNIPOLAR
#define Z_PIN_PHASE_0   GPIO_NUM_34
#define Z_PIN_PHASE_1   GPIO_NUM_35
#define Z_PIN_PHASE_2   GPIO_NUM_32
#define Z_PIN_PHASE_3   GPIO_NUM_33

// #define X_LIMIT_PIN             GPIO_NUM_17
// #define Y_LIMIT_PIN             GPIO_NUM_4
// #define Z_LIMIT_PIN             GPIO_NUM_16

#define DEFAULT_STEP_PULSE_MICROSECONDS 3
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 200 // 200ms

#define DEFAULT_X_MAX_RATE 5000.0   // mm/min
#define DEFAULT_Y_MAX_RATE 5000.0   // mm/min
#define DEFAULT_Z_MAX_RATE 200000.0 // mm/min

#define DEFAULT_X_ACCELERATION 500.0 // mm/sec^2. 500 mm/sec^2 = 1800000 mm/min^2
#define DEFAULT_Y_ACCELERATION 500.0 // mm/sec^2
#define DEFAULT_Z_ACCELERATION 500.0 // mm/sec^2

// Input pins for various functions.  If the corresponding pin is not defined,
// the function will not be available.

// CONTROL_SAFETY_DOOR_PIN shuts off the machine when a door is opened
// or some other unsafe condition exists.
// #define CONTROL_SAFETY_DOOR_PIN GPIO_NUM_35  // labeled Door,  needs external pullup

// RESET, FEED_HOLD, and CYCLE_START can control GCode execution at
// the push of a button.

// #define CONTROL_RESET_PIN       GPIO_NUM_34  // labeled Reset, needs external pullup
// #define CONTROL_FEED_HOLD_PIN   GPIO_NUM_36  // labeled Hold,  needs external pullup
// #define CONTROL_CYCLE_START_PIN GPIO_NUM_39  // labeled Start, needs external pullup

// === Ganging
// If you need to use two motors on one axis, you can "gang" the motors by
// defining a second pin to control the other motor on the axis.  For example:

// #define Y2_STEP_PIN             GPIO_NUM_27  /* labeled Z */
// #define Y2_DIRECTION_PIN        GPIO_NUM_33  /* labeled Z */

// === Homing cycles
// Set them using $Homing/Cycle0= optionally up to $Homing/Cycle5=

// === Default settings
// Grbl has many run-time settings that the user can changed by
// commands like $110=2000 .  Their values are stored in non-volatile
// storage so they persist after the controller has been powered down.
// Those settings have default values that are used if the user
// has not altered them, or if the settings are explicitly reset
// to the default values wth $RST=$.
//
// The default values are established in defaults.h, but you
// can override any one of them by definining it here, for example:

//#define DEFAULT_INVERT_LIMIT_PINS 1
//#define DEFAULT_REPORT_INCHES 1


// Grbl_ESP32 use the ESP32's special RMT (IR remote control) hardware
// engine to achieve more precise high step rates than can be done
// in software.  That feature is enabled by default, but there are
// some machines that might not want to use it, such as machines that
// do not use ordinary stepper motors.  To turn it off, do this:
// #undef USE_RMT_STEPS

// === Special Features

// USE_KINEMATICS enables the functions inverse_kinematics(),
// kinematics_pre_homing(), and kinematics_post_homing(),
// so non-Cartesian machines can be implemented.
// #define USE_KINEMATICS

// USE_M30 enables the user_m30() function which implements
// custom behavior when a GCode programs stops at the end
// #define USE_M30

// === Grbl behavior options
// There are quite a few options that control aspects of Grbl that
// are not specific to particular machines.  They are listed and
// described in config.h after it includes the file machine.h.
// Normally you would not need to change them, but if you do,
// it will be necessary to make the change in config.h