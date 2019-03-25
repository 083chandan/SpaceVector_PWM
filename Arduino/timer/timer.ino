#include "Timer.h"

Timer t;

#define t0 33
#define t1 36
#define t2 98


int PWM1;
int PWM2;
int PWM3;

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
//  int t0Event = t.every(t0, t0EventFun, (void*)0);
  int t1Event = t.every(t1, t1EventFun, (void*)1);
//  int t2Event = t.every(t2, t2EventFun, (void*)2);

  PWM1 = t.oscillate(3, 33, HIGH);
  PWM1 = t.oscillate(5, 36, HIGH);
  PWM1 = t.oscillate(6, 98, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  t.update();
//  Serial.println(analogRead(13));
}
//
//void t0EventFun(void* context)
//{
//  int time = (int)context;
//  Serial.print(time);
//  Serial.print(" second tick: millis()=");
//  Serial.println(millis());
//}
//
//void t1EventFun(void* context)
//{
//  int time = (int)context;
//  Serial.print(time);
//  Serial.print(" second tick: millis()=");
//  Serial.println(millis());
//}
//
//void t2EventFun(void* context)
//{
//  int time = (int)context;
//  Serial.print(time);
//  Serial.print(" second tick: millis()=");
//  Serial.println(millis());
//}
