#include <QTRSensors.h>

#define m11Pin 5
#define m12Pin 7
#define m21Pin 3
#define m22Pin 2
#define m1Enable 16
#define m2Enable 4
#define ledPin 10
#define sensorCount 6
#define minSpeed -255
#define maxSpeed 255
#define baseSpeed 135
#define minSensorValue 0
#define maxSensorValue 5000
#define minErrorValue -45
#define maxErrorValue 45

#define calibrationSpeed 40
#define blackLineThreshold 700
#define calibrationSteps 250

uint16_t sensorValues[sensorCount];
int sensors[sensorCount] = { 0, 0, 0, 0, 0, 0 };


int m1Speed = 0;
int m2Speed = 0;
int motorSpeed;

int p = 0;
int i = 0;
int d = 0;

int error = 0;
int lastError = 0;

float kp = 9.7;
float ki = 0.0002;
float kd = 26.5;

QTRSensors qtr;

void autoCalibrate() {
  setMotorSpeed(calibrationSpeed, -calibrationSpeed);

  for (uint16_t i = 0; i < calibrationSteps; ++i) {
    qtr.calibrate();
    qtr.read(sensorValues);
    // Check if the robot is at the rightmost position
    if (sensorValues[0] > blackLineThreshold) {
      setMotorSpeed(0, 0);
      setMotorSpeed(-calibrationSpeed, calibrationSpeed);
    }
    // Check if the robot is at the leftmost position
    if (sensorValues[sensorCount - 1] > blackLineThreshold) {
      setMotorSpeed(0, 0);
      setMotorSpeed(calibrationSpeed, -calibrationSpeed);
    }
  }
}

void setup() {
  pinMode(m11Pin, OUTPUT);
  pinMode(m12Pin, OUTPUT);
  pinMode(m21Pin, OUTPUT);
  pinMode(m22Pin, OUTPUT);
  pinMode(m1Enable, OUTPUT);
  pinMode(m2Enable, OUTPUT);
  pinMode(ledPin, OUTPUT);

  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){ A0, A1, A2, A7, A8, A9 }, sensorCount);
  delay(4000);
  digitalWrite(ledPin, HIGH);
  autoCalibrate();
  digitalWrite(ledPin, LOW);
}

void loop() {
  pidControl(kp, ki, kd);
  motorPidControl();
  setMotorSpeed(m1Speed, m2Speed);
}

void pidControl(float kp, float ki, float kd) {
  error = map(qtr.readLineBlack(sensorValues), minSensorValue, maxSensorValue, minErrorValue, maxErrorValue);
  p = error;
  i = i + error;
  d = error - lastError;
  lastError = error;

  motorSpeed = kp * p + ki * i + kd * d;
}


void motorPidControl() {
  m1Speed = baseSpeed;
  m2Speed = baseSpeed;

  if (error < 0) {
    m1Speed += motorSpeed;
  } else if (error > 0) {
    m2Speed -= motorSpeed;
  }

  m1Speed = constrain(m1Speed, minSpeed, maxSpeed);
  m2Speed = constrain(m2Speed, minSpeed, maxSpeed);
}

void setMotorSpeed(int motor1Speed, int motor2Speed) {
  if (motor1Speed == 0) {
    digitalWrite(m11Pin, LOW);
    digitalWrite(m12Pin, LOW);
    analogWrite(m1Enable, motor1Speed);
  } else {
    if (motor1Speed > 0) {
      digitalWrite(m11Pin, HIGH);
      digitalWrite(m12Pin, LOW);
      analogWrite(m1Enable, motor1Speed);
    }
    if (motor1Speed < 0) {
      digitalWrite(m11Pin, LOW);
      digitalWrite(m12Pin, HIGH);
      analogWrite(m1Enable, -motor1Speed);
    }
  }
  if (motor2Speed == 0) {
    digitalWrite(m21Pin, LOW);
    digitalWrite(m22Pin, LOW);
    analogWrite(m2Enable, motor2Speed);
  } else {
    if (motor2Speed > 0) {
      digitalWrite(m21Pin, HIGH);
      digitalWrite(m22Pin, LOW);
      analogWrite(m2Enable, motor2Speed);
    }
    if (motor2Speed < 0) {
      digitalWrite(m21Pin, LOW);
      digitalWrite(m22Pin, HIGH);
      analogWrite(m2Enable, -motor2Speed);
    }
  }
}
