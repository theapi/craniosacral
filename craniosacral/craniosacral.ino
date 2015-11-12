/**
 * Sweep on the three main craniosacral frequencies.
 */

#include <Servo.h> 
 
Servo midtide; 
Servo longtide;
Servo cri;

// 2 - 2.5 cycles per minute
unsigned long midtide_last = 0; 
unsigned long midtide_interval = 28;
byte midtide_direction = 1;
long midtide_pos = 1750;

// 100 secs per cycle
unsigned long longtide_last = 0; 
unsigned long longtide_interval = 50; 
byte longtide_direction = 1;
long longtide_pos = 1750;

// 8 - 14 cycles per minute
unsigned long cri_last = 0; 
unsigned long cri_interval = 4; 
byte cri_direction = 1;
long cri_pos = 1750;
 
void setup() 
{ 
  midtide.attach(4);
  longtide.attach(5);
  cri.attach(6);

} 
 
 
void loop() 
{ 
  //midtide.writeMicroseconds(1250);
  unsigned long now = millis();
  
  // mid tide
  if (now - midtide_last > midtide_interval) {
    midtide_last = now;
    if (midtide_direction) {
      midtide_pos++;
      if (midtide_pos <= 1750) {
        midtide.writeMicroseconds(midtide_pos);
      } else {
        midtide_direction = !midtide_direction;
      }  
    }
    if (!midtide_direction) {
      midtide_pos--;
      if (midtide_pos >= 1250) {
        midtide.writeMicroseconds(midtide_pos);
      } else {
        midtide_direction = !midtide_direction;
      }  
    }
  }
  
  // longtide tide
  if (now - longtide_last > longtide_interval) {
    longtide_last = now;
    if (longtide_direction) {
      longtide_pos++;
      if (longtide_pos <= 1750) {
        longtide.writeMicroseconds(longtide_pos);
      } else {
        longtide_direction = !longtide_direction;
      }  
    }
    if (!longtide_direction) {
      longtide_pos--;
      if (longtide_pos >= 1250) {
        longtide.writeMicroseconds(longtide_pos);
      } else {
        longtide_direction = !longtide_direction;
      }  
    }
  }
  
  // cri
  if (now - cri_last > cri_interval) {
    cri_last = now;
    if (cri_direction) {
      cri_pos++;
      if (cri_pos <= 1750) {
        cri.writeMicroseconds(cri_pos);
      } else {
        cri_direction = !cri_direction;
      }  
    }
    if (!cri_direction) {
      cri_pos--;
      if (cri_pos >= 1250) {
        cri.writeMicroseconds(cri_pos);
      } else {
        cri_direction = !cri_direction;
      }  
    }
  }

  
} 
