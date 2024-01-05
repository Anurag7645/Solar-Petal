#include <Servo.h>
#include <AFMotor.h>

Servo myservo,myservo1,motor1; 
AF_DCMotor motor(4); // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(10); // attaches the servo on pin 9 to the servo objec
  myservo1.attach(9); // attaches the servo1 on pin 9 to the servo objec
  motor.setSpeed(200);
	motor.run(RELEASE);  
}

void loop() {
  uint8_t i;
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    myservo1.write(pos);
    motor1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    myservo1.write(pos);
    motor1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  // Turn on motor
	motor.run(FORWARD);
	
	// Accelerate from zero to maximum speed
	for (i=0; i<255; i++) 
	{
		motor.setSpeed(i);  
		delay(10);
	}
	
	// Decelerate from maximum speed to zero
	for (i=255; i!=0; i--) 
	{
		motor.setSpeed(i);  
		delay(10);
	}
// Now change motor direction
	motor.run(BACKWARD);
	
	// Accelerate from zero to maximum speed
	for (i=0; i<255; i++) 
	{
		motor.setSpeed(i);  
		delay(10);
	}

	// Decelerate from maximum speed to zero
	for (i=255; i!=0; i--) 
	{
		motor.setSpeed(i);  
		delay(10);
	}

	// Now turn off motor
	motor.run(RELEASE);
	delay(1000);
}

