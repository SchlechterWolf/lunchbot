#include <Servo.h>

// Define variables
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
int sensorValueAdjusted = 0;
int sensorValueDrive = 0;
int forward = 6;
int forwardnum = 0;
int backward = 7;
int backwardnum = 0;
Servo myservo;

// Setup
void setup() {//If you are reading this, then something is wrong then it is TOTALLY NOT LOGAN NO'S FAULT

  pinMode(forward, INPUT_PULLUP);
  pinMode(backward, INPUT_PULLUP);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  myservo.attach(3);
}

//Main loop
void loop() { 
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  // adjusting value to 0 - 89
  sensorValueAdjusted = sensorValue / 11.4943820225;
  
  // get direction switch value
  forwardnum = digitalRead(forward);
  backwardnum = digitalRead(backward);
  
  // drive logic
  if(forwardnum == 0)
  {
     sensorValueDrive = 180 - sensorValueAdjusted;//91-180 (forward values) clockwise
     myservo.write(sensorValueDrive);
  }
  else if(backwardnum == 0)
  {
     sensorValueDrive = sensorValueAdjusted;//0-89 (backward values) c.clockwise
     myservo.write(sensorValueDrive);
  }
  else
     myservo.write(90);
     
  // print information
  Serial.print(forwardnum);
  Serial.print("\t");
  Serial.print(backwardnum);
  Serial.print("\t");
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.print(sensorValueAdjusted);
  Serial.print("\t");
  Serial.println(sensorValueDrive);

}
