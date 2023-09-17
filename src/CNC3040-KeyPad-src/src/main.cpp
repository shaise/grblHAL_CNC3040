#include <Arduino.h>
#include "key_defs.h"

const uint8_t input_ios[] = {PA0, PA1, PA2, PA3, PA4};
const uint8_t output_ios[] = {PB3, PB4, PB5, PB6, PB7, PB8, PB10, PB11, PB12, PB13, PB14};
#define NUM_INPUTS sizeof(input_ios)
#define NUM_OUTPUTS sizeof(output_ios)

// scan from PB3 to PB8 
#define SCAN_START (1<<3)
#define SCAN_END   (1<<8)
#define SCAN_OUT_MASK 0x1F8
#define SCAN_IN_MASK 0x1F
#define SCAN_LED_MASK 0x7C00
int line_shift = SCAN_START; 
int line_count = 0;

uint32_t last_but_state, cur_but_state = 0;
uint32_t led_state = 0;
uint32_t last_millis = 0, cur_millis;

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
  for (int i = 0; i < NUM_INPUTS; i++)
    pinMode(input_ios[i], INPUT_PULLUP);
  for (int i = 0; i < NUM_OUTPUTS; i++)
    pinMode(output_ios[i], OUTPUT);
  //GPIOB->ODR = SCAN_LED_MASK;
}

uint32_t presslap;

void SendCmd(uint8_t cmd)
{
  Serial1.write(cmd);
  //Serial.println(cmd, 16);
}

void HandleDirectMap(const uint32_t *map, int press_mask)
{
  while (*map != 0)
  {
    uint32_t key = *map++;
    uint8_t cmd = (uint8_t)*map++;
    if (press_mask & key)
      SendCmd(cmd);
  }
}

void HandleKeyPressed(int press_mask)
{
  #define IF_PRESSED(x) if (press_mask & (x))
  if (press_mask == 0)
    return;
  presslap = millis();
  HandleDirectMap(jog_key_map, press_mask);
  HandleDirectMap(motion_key_map, press_mask);
  HandleDirectMap(control_key_map, press_mask);

}

void HandleKeyReleased(int release_mask)
{
  #define IF_RELEASED(x) if (press_mask & (x))
  if (release_mask == 0)
    return;
  
  //Serial.println(millis()-presslap);
  // any key release will cancel jog motion
  SendCmd(CMD_CANCL_JOG);
}


void poll_buttons_leds()
{
  int in, leds, shift;
  in = (int)GPIOA->IDR & SCAN_IN_MASK;
  shift = line_count * 5;
  cur_but_state &= ~(SCAN_IN_MASK << shift);
  cur_but_state |= (in ^ SCAN_IN_MASK) << shift;
  line_shift <<= 1;
  line_count++;
  if (line_count >= 6)
  {
    line_shift = SCAN_START;
    line_count = 0;
  }
  GPIOB->BRR = SCAN_LED_MASK;
  shift = line_count * 5;
  leds = (led_state >> shift) & 0x1F;
  GPIOB->BSRR = SCAN_OUT_MASK | leds << 10;
  //GPIOB->BSRR = leds << 10;
  GPIOB->BRR = line_shift;

  // look for key press/release
  if (cur_but_state != last_but_state)
  {
    //Serial.println((int)GPIOB->ODR & SCAN_LED_MASK, 16);
    //Serial.println(cur_but_state, 16);
    uint32_t changes = last_but_state ^ cur_but_state;
    HandleKeyPressed(changes & cur_but_state);
    HandleKeyReleased(changes & ~cur_but_state);
    last_but_state = cur_but_state;
    led_state = cur_but_state;
    //Serial1.write((uint8_t)0xA5);
  }

}



void loop() {
  cur_millis = millis();
  if (cur_millis == last_millis)
    return; 
  
  poll_buttons_leds();
  last_millis = cur_millis;

  if (Serial1.available())
  {
    Serial.print("Got: ");
    Serial.println((int)Serial1.read(), 16);
  }
}

