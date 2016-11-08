#include "PCA9685.h"
#include <avr/io.h>
#include <util/delay.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN 119
#define SERVOMAX 445

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

uint8_t thumb = 0;
uint8_t index = 1;
uint8_t middle = 2;
uint8_t ring = 3;
uint8_t pinkie = 4;
uint8_t wrist = 5;

int a = 97, q = 113, s = 115, w = 119, d = 100, e = 101, f = 102, r = 114, g = 103, t = 116; 

void setup() {
   Serial.begin(9600);
   Serial.println("Motion Test");

   pwm.begin();
  
   pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

   yield();
}
  
void loop() {
  while(Serial.available() == 0); //enabling serial reading
  int val = Serial.read();        //keyboard serial data coming from serial display is save to int val 
  Serial.println(val);            //print the ANCI code of the entered key stroke
  
  if(val == s){                 //if val is the value corresponding to 's' go to 180 position (closed hand)
    pwm.setPWM(ring, 0, SERVOMAX);
    delay(1000);
    }
  if(val == w){                   //if val is the value corresponding to 'w' go to 0 position (opened hand)
    pwm.setPWM(ring, 0, SERVOMIN);
    delay(1000);
    }
  
  if(val == a){                 
    pwm.setPWM(pinkie, 0, SERVOMAX);
    delay(1000);
    }
  if(val == q){                   
    pwm.setPWM(pinkie, 0, SERVOMIN);
    delay(1000);
  }
  
  if(val == d){                 
    pwm.setPWM(middle, 0, SERVOMAX);
    delay(1000);
    }
  if(val == e){                   
    pwm.setPWM(middle, 0, SERVOMIN);
    delay(1000);
  }
  
  if(val == f){                 
    pwm.setPWM(index, 0, SERVOMAX);
    delay(1000);
    }
  if(val == r){                   
    pwm.setPWM(index, 0, SERVOMIN);
    delay(1000);
  }
  
  if(val == g){                 
    pwm.setPWM(thumb, 0, SERVOMAX);
    delay(1000);
    }
  if(val == t){                   
    pwm.setPWM(thumb, 0, SERVOMIN);
    delay(1000);
  }
    
//  pwm.setPWM(ring, 0, SERVOMIN);
//  delay(1000);
//  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
//    pwm.setPWM(thumb, 0, pulselen);
//  }
//
//  delay(500);
//  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
//    pwm.setPWM(thumb, 0, pulselen);
//  }
//  pwm.setPWM(ring, 0, SERVOMAX);
//  delay(1000);
//  pwm.setPWM(ring, 0, SERVOMIN);
//  delay(1000);
}
