#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
  
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  int i;
    for(i=0; i<180; i++)                                // in steps of 1 degree 
  {
    myservo.write(i);              // tell servo to go to position in variable 'pos' 
    delay(100);
  }
} 
