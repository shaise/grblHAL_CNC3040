#include <Arduino.h>
#include "key_defs.h"

const uint32_t jog_key_map[] = 
{
    KEY_XP, CMD_JOG_XR,
    KEY_XM, CMD_JOG_XL,
    KEY_YP, CMD_JOG_YF,
    KEY_YM, CMD_JOG_YB,
    KEY_ZP, CMD_JOG_ZU,
    KEY_ZM, CMD_JOG_ZD,
    KEY_AP, CMD_JOG_AR,
    KEY_AM, CMD_JOG_AL,
    KEY_JOG_MODE, CMD_NEXT_JOG,
    0, 0   
};

const uint32_t motion_key_map[] =
{
    KEY_FEED_P10, CMD_FEED_P10,  
    KEY_FEED_100, CMD_FEED_100,  
    KEY_FEED_M10, CMD_FEED_M10,  
    KEY_RAPID_100, CMD_RAPID_100,  
    KEY_RAPID_50, CMD_RAPID_50,
    KEY_RAPID_25, CMD_RAPID_25,
    KEY_MIST, CMD_TOGL_MIST,
    KEY_FLOOD, CMD_TOGL_FLOOD,
    KEY_HOME, CMD_HOME,
    KEY_SPIN_ON_OFF, CMD_SPIN_STOP,
    KEY_SPIN_P10, CMD_SPIN_P10,
    KEY_SPIN_M10, CMD_SPIN_M10,
    0, 0,
};


const uint32_t control_key_map[] =
{
    KEY_CYCLE_START, CMD_CYC_START,
    KEY_FEED_HOLD, CMD_FEED_HOLD,
    KEY_DOOR, CMD_TOGL_DOOR,
    0, 0
};