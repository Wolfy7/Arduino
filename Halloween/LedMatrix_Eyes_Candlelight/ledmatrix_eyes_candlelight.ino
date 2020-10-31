//We always have to include the library
#include "LedControl.h"
// own header file with animations
#include "animations.h"

#define LEFT_EYE  0
#define RIGHT_EYE 1

/*
 Now we need a LedControl to work with.
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 */
LedControl lc=LedControl(12,10,11,2);

animation blink {krgui64BLINK, ANIMATION_LENGTH(krgui64BLINK), 40};
animation down_up {ui64DOWN_UP, ANIMATION_LENGTH(ui64DOWN_UP), 120};
animation up_down {ui64UP_DOWN, ANIMATION_LENGTH(ui64UP_DOWN), 120};
animation right_out_left_in {ui64RIGHT_OUT_LEFT_IN, ANIMATION_LENGTH(ui64RIGHT_OUT_LEFT_IN), 40};
animation one_round {ui64ONE_ROUND, ANIMATION_LENGTH(ui64ONE_ROUND), 80};
animation look_rdown{ui64LOOK_RDOWN, ANIMATION_LENGTH(ui64LOOK_RDOWN), 80};
animation look_rdown_back {ui64LOOK_RDOWN_BACK, ANIMATION_LENGTH(ui64LOOK_RDOWN_BACK), 80};
animation look_ldown{ui64LOOK_LDOWN, ANIMATION_LENGTH(ui64LOOK_LDOWN), 80};
animation look_ldown_back {ui64LOOK_LDOWN_BACK, ANIMATION_LENGTH(ui64LOOK_LDOWN_BACK), 80};
animation look_rup{ui64LOOK_RUP, ANIMATION_LENGTH(ui64LOOK_RUP), 80};
animation look_rup_back {ui64LOOK_RUP_BACK, ANIMATION_LENGTH(ui64LOOK_RUP_BACK), 80};
animation look_lup{ui64LOOK_LUP, ANIMATION_LENGTH(ui64LOOK_LUP), 80};
animation look_lup_back {ui64LOOK_LUP_BACK, ANIMATION_LENGTH(ui64LOOK_LUP_BACK), 80};
animation close_eye {ui64CLOSE_EYE, ANIMATION_LENGTH(ui64CLOSE_EYE), 20};
animation right_eye_evile {ui64RIGHT_EYE_EVILE, ANIMATION_LENGTH(ui64RIGHT_EYE_EVILE), 800};
animation left_eye_evile {ui64LEFT_EYE_EVILE, ANIMATION_LENGTH(ui64LEFT_EYE_EVILE), 800};


animation wait_500 {NULL, 0, 500};
animation wait_2000 {NULL, 0, 2000};

animation right_eye[] = {
  blink,
  wait_2000,
  look_ldown,
  wait_2000,
  look_ldown_back,
  wait_2000,
  down_up,
  wait_2000,
  look_rup,
  wait_2000,
  look_rup_back,
  wait_2000,
  blink,
  wait_2000,
  right_out_left_in,
  right_out_left_in,
  wait_2000,
  up_down,
  wait_2000,
  one_round,
  wait_2000,
  look_lup,
  wait_2000,
  look_lup_back,
  wait_2000,
  close_eye,
  right_eye_evile,
  wait_2000
};
const unsigned int right_eye_size = sizeof(right_eye)/sizeof(right_eye[0]);

animation left_eye[] = {
  blink,
  wait_2000,
  look_rdown,
  wait_2000,
  look_rdown_back,
  wait_2000,
  down_up,
  wait_2000,
  look_rup,
  wait_2000,
  look_rup_back,
  wait_2000,
  blink,
  wait_2000,
  right_out_left_in,
  right_out_left_in,
  wait_2000,
  up_down,
  wait_2000,
  one_round,
  wait_2000,
  look_lup,
  wait_2000,
  look_lup_back,
  wait_2000,
  close_eye,
  left_eye_evile,
  wait_2000
};
const unsigned int left_eye_size = sizeof(left_eye)/sizeof(left_eye[0]);

void nextAnimation(const unsigned int *max_size, unsigned int *current)
{   
  if(*current >= (*max_size -1)){
    *current = 0;
  }
  else
  {
    *current = *current + 1;
  }  
}

void setup()
{
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  lc.shutdown(1,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  lc.setIntensity(1,8);
  /* and clear the display */
  lc.clearDisplay(0);
  lc.clearDisplay(1);

  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void displayImage(int matrix, uint64_t image)
{
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      lc.setLed(matrix, i, j, bitRead(row, j));
    }
  }
}

void Eye_task()
{
  static unsigned long uliPreviousMills = 0;
  static unsigned int i = 0;
  static unsigned int currentAnimation = 0;

  if(millis() - uliPreviousMills >= left_eye[currentAnimation].speed)
  {
    if( left_eye[currentAnimation].frames != NULL)
    {
      displayImage(LEFT_EYE, left_eye[currentAnimation].frames[i]);
      displayImage(RIGHT_EYE, right_eye[currentAnimation].frames[i]);
      if (++i >= left_eye[currentAnimation].length ) {
        i = 0;
        nextAnimation(&left_eye_size, &currentAnimation);
      }
    }
    else
    {
      nextAnimation(&left_eye_size, &currentAnimation);
    }
    uliPreviousMills = millis();
  }
}

void candlelight_task()
{
  static unsigned long uliPreviousMills = 0;
  static unsigned long uliWaitMills = random(100);

  if(millis() - uliPreviousMills >= uliWaitMills)
  {
    analogWrite(3, random(120) + 135);
    analogWrite(5, random(120) + 135);
    analogWrite(6, random(120) + 135);

    uliWaitMills = random(100);
    uliPreviousMills = millis();
  }
}

void loop()
{
  Eye_task();
  candlelight_task();
}
