// C++ code

const int leftMotorForwardPin = 11;
const int leftMotorBackwardPin = 12;
const int rightMotorForwardPin = 9;
const int rightMotorBackwardPin = 10;
const int leftMotorSpeedPin = 6;
const int rightMotorSpeedPin = 5;

const int sensor1Pin = A1;
const int sensor2Pin = A0;

int sensor1;
int sensor2;

const int triggerPin = 8;
const int echoPin = 7;

long duration;
long cm;
const long threshold = 20;

void setup()
{
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorBackwardPin, OUTPUT);
  pinMode(rightMotorForwardPin , OUTPUT);
  pinMode(rightMotorBackwardPin , OUTPUT);
  pinMode(leftMotorSpeedPin , OUTPUT);
  pinMode(rightMotorSpeedPin , OUTPUT);

}

void loop(){
  digitalWrite(triggerPin,LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin,LOW);

  duration = pulseIn(echoPin,HIGH);

  cm = duration/58;

  sensor1 = analogRead(sensor1Pin);
  sensor2 = analogRead(sensor2Pin);

  if((sensor1 > threshold) && (sensor2 > threshold)){
    driveForward(0,200,200);
  }
  else if((sensor1 < threshold) && (sensor2 < threshold)){
    turnRight(0,200,200);
  }
    else if((sensor1 > threshold) && (sensor2 < threshold)){
    turnLeft(0,200,200);
  }
    else{
    stopDriving(1000);
  }
}

void driveForward(int delay_time, int leftSpeed,int rightSpeed){
  analogWrite(leftMotorSpeedPin,leftSpeed);
  analogWrite(rightMotorSpeedPin,rightSpeed);
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
  delay(delay_time);
}

void driveBackward(int delay_time, int leftSpeed,int rightSpeed){
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
  delay(delay_time);
}

void turnLeft(int delay_time,int leftSpeed,int rightSpeed){
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
  delay(delay_time);
}

void turnRight(int delay_time,int leftSpeed,int rightSpeed){
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
  delay(delay_time);
}

void stopDriving(int delay_time){
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
  delay(delay_time);
}





