#ifndef __KEY_DEFS_H__
#define __KEY_DEFS_H__

#define KEY_CYCLE_START  0x00000001
#define KEY_SPIN_M10     0x00000002
#define KEY_AM           0x00000004
#define KEY_XM           0x00000008
#define KEY_BM           0x00000010
#define KEY_FEED_HOLD    0x00000020
#define KEY_SPIN_ON_OFF  0x00000040
#define KEY_YP           0x00000080
#define KEY_JOG_MODE     0x00000100
#define KEY_YM           0x00000200
#define KEY_AUX1         0x00000400
#define KEY_SPIN_P10     0x00000800
#define KEY_AP           0x00001000
#define KEY_XP           0x00002000
#define KEY_BP           0x00004000
#define KEY_ALARM_OFF    0x00008000
#define KEY_HOME         0x00010000
#define KEY_ZP           0x00020000
#define KEY_AUX2         0x00040000
#define KEY_ZM           0x00080000
#define KEY_DOOR         0x00100000
#define KEY_MIST         0x00200000
#define KEY_FEED_P10     0x00400000
#define KEY_FEED_100     0x00800000
#define KEY_FEED_M10     0x01000000
#define KEY_ESTOP        0x02000000
#define KEY_FLOOD        0x04000000
#define KEY_RAPID_100    0x08000000
#define KEY_RAPID_50     0x10000000
#define KEY_RAPID_25     0x20000000


#define CMD_FEED_HOLD '!'  // 	Enter feed hold
#define CMD_CYC_START '~'  // 	Cycle start
#define CMD_EN_MPG    0x8B //   Enable MPG full control1
#define CMD_CANCL_JOG 0x85 //   Cancel jog motion2
#define CMD_STEP_JOG  '0'  // 	Enable step mode jogging
#define CMD_SLOW_JOG  '1'  // 	Enable slow jogging mode
#define CMD_FAST_JOG  '2'  // 	Enable fast jogging mode
#define CMD_NEXT_JOG  'h'  // 	Select next jog mode
#define CMD_HOME      'H'  // 	Home machine
#define CMD_JOG_XR    'R'  // 	Continuous jog X+
#define CMD_JOG_XL    'L'  // 	Continuous jog X-
#define CMD_JOG_YF    'F'  // 	Continuous jog Y+
#define CMD_JOG_YB    'B'  // 	Continuous jog Y-
#define CMD_JOG_ZU    'U'  // 	Continuous jog Z+
#define CMD_JOG_ZD    'D'  // 	Continuous jog Z-
#define CMD_JOG_XRYF  'r'  // 	Continuous jog X+Y+
#define CMD_JOG_XRYB  'q'  // 	Continuous jog X+Y-
#define CMD_JOG_XLYF  's'  // 	Continuous jog X-Y+
#define CMD_JOG_XLYB  't'  // 	Continuous jog X-Y-
#define CMD_JOG_XRZU  'w'  // 	Continuous jog X+Z+
#define CMD_JOG_XRZD  'v'  // 	Continuous jog X+Z-
#define CMD_JOG_XLZU  'u'  // 	Continuous jog X-Z+
#define CMD_JOG_XLZD  'x'  // 	Continuous jog X-Z-
#define CMD_JOG_AR    'A'  //    Continuous jog A CW
#define CMD_JOG_AL    'a'  //    Continuous jog A CCW
#define CMD_TOGL_DOOR    0x84 	// Toggle safety door open status
#define CMD_TOGL_OP_STOP 0x88 	// Toggle optional stop mode
#define CMD_TOGL_BLK_EXE 0x89 	// Toggle single block execution mode
#define CMD_TOGL_FAN     0x8A 	// Toggle Fan 0 output3
#define CMD_FEED_100     'I'	// Restore feed override value to 100%
#define CMD_FEED_100X    0x90 	// Restore feed override value to 100%
#define CMD_FEED_P10     'i' 	// Increase feed override value 10%
#define CMD_FEED_P10X    0x91 	// Increase feed override value 10%
#define CMD_FEED_M10     'j' 	// Decrease feed override value 10%
#define CMD_FEED_M10X    0x92 	// Decrease feed override value 10%
#define CMD_FEED_P1      0x93 	// Increase feed override value 1%
#define CMD_FEED_M1      0x94 	// Decrease feed override value 1%
#define CMD_RAPID_100    0x95 	// Restore rapids override value to 100%
#define CMD_RAPID_50     0x96 	// Set rapids override to 50%
#define CMD_RAPID_25     0x97 	// Set rapids override to 25%
#define CMD_SPIN_100     'K' 	// Restore spindle RPM override value to 100%
#define CMD_SPIN_100X    0x99 	// Restore spindle RPM override value to 100%
#define CMD_SPIN_P10     'k' 	// Increase spindle RPM override value 10%
#define CMD_SPIN_P10X    0x9A 	// Increase spindle RPM override value 10%
#define CMD_SPIN_M10     'z' 	// Decrease spindle RPM override value 10%
#define CMD_SPIN_M10X    0x9B 	// Decrease spindle RPM override value 10%
#define CMD_SPIN_P1      0x9C 	// Increase spindle RPM override value 1%
#define CMD_SPIN_M1      0x9D 	// Decrease spindle RPM override value 1%
#define CMD_SPIN_STOP    0x9E 	// Toggle spindle stop override4
#define CMD_TOGL_FLOOD   'C' 	// Toggle flood coolant output
#define CMD_TOGL_FLOODX  0xA0 	// Toggle flood coolant output
#define CMD_TOGL_MIST    'M' 	// Toggle mist coolant output
#define CMD_TOGL_MISTX   0xA1 	// Toggle mist coolant output

extern const uint32_t jog_key_map[];
extern const uint32_t motion_key_map[];
extern const uint32_t control_key_map[];






#endif