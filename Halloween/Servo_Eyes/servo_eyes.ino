#include <Servo.h>

#define SERVOS 12

Servo myServos[SERVOS];
int servoIntervals[SERVOS];
unsigned long PreviousMills[SERVOS] = {0};

void initServos(){
  for(int i=2; i < SERVOS; i++)
  {
    myServos[i].attach(i);
    servoIntervals[i] = random(450, 550);
    Serial.println(i);
  }
}


void setup() { 
  randomSeed(analogRead(0));
  initServos();
  
}

int randServoPos;

void loop() { 
  for(int i=2; i < SERVOS; i++)
  {
    if(millis() - PreviousMills[i] >= servoIntervals[i])
    {
      randServoPos = random(10, 190);
      myServos[i].write(randServoPos);
      servoIntervals[i] = random(450, 550);
      PreviousMills[i] = millis();
    }
  }
}
