#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  Serial.println("initialized");
  delay(2000);// attaches the servo on pin 9 to the servo object
}

void loop() {
  
  int potRead = analogRead(A0);
  int pwm = map(potRead, 0, 1023, 0, 180);
  Serial.println(pwm);
  myservo.write(pwm);
  delay(50);
  

  
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15 ms for the servo to reach the position
//  }
}
