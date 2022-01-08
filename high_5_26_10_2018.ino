#include <PS2X_lib.h>
#include <Servo.h>
PS2X ps2x;

Servo Xservo, Yservo, Zservo;
int X, Y, x, y,a1, b1,a2, b2;
const int in1 = 5;
const int in2 = 6;
const int in3 = 7;
const int in4 = 8;
const int enA = 3;
const int enB = 9;
int fspeed = 255;
int rspeed, lspeed;
byte PS2 = 0;
void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  PS2 = ps2x.config_gamepad(13, 
  Xservo.attach(A0);
  Yservo.attach(A1);11, 10, 12, false, false);
  x = 0;
  y = 0;
  Serial.begin(57600);
}

void loop() {
  ps2x.read_gamepad();
  if (ps2x.Button(PSB_GREEN)){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH );
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, fspeed);
    analogWrite(enA, fspeed);
  }
  if (ps2x.Analog(PSS_RY) > 128) {
  rspeed = map(ps2x.Analog(PSS_RY), 129, 255, 0, 255);
    Serial.println(rspeed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, rspeed);

  }
  delay(10);
  if (ps2x.Analog(PSS_RY) < 128) {
  rspeed = map(ps2x.Analog(PSS_RY), 0, 127, 255, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);

    analogWrite(enA, rspeed);

  }
  delay(10);
  if (ps2x.Analog(PSS_LY) < 128)  {
  lspeed = map(ps2x.Analog(PSS_LY), 0, 127, 255, 0);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, lspeed);


  }
  delay(10);
  if (ps2x.Analog(PSS_LY) > 128)  {
  lspeed = map(ps2x.Analog(PSS_LY), 129, 255, 0, 255);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, lspeed);

  }
  else {
    analogWrite(enA, fspeed);
    analogWrite(enB, fspeed);
  }
  delay(10);

  if (ps2x.Button(PSB_L2)) {
  a1 = 1;
}
else {
  a1 = 0;
}
if (ps2x.Button(PSB_L1)) {
  a2 = 1;
}
else {
  a2 = 0;
}
if (ps2x.Button(PSB_R1)) {
  b1 = 1;
}
else {
  b1 = 0;
}
if (ps2x.Button(PSB_R2)) {
  b2 = 1;
}
else {
  b2 = 0;
}
if (a1 == 1) {
  X = ++x;
  delay(5);
  }
  if (a2 == 1) {
  X = --x;
  delay(5);
  }
  if (b1 == 1) {
  Y = ++y;
  delay(5);
  }
  if (b2 == 1) {
  Y = --y;
  delay(5);
  }
  if (X > 140 ) {
  X = 140;
}
else if (X < 10) {
  X = 10;
}
else {
  X = X;
}
if ( Y > 60 ) {

  Y = 60;
}
else if (Y < 0 ) {
  Y = 0;
}
else {
  Y = Y;
}
Serial.print("  X>>"); Serial.print(X);
Serial.print("  Y>>"); Serial.print(Y);
Xservo.write(X);
Yservo.write(Y);
x = X;
    y = Y;
    delay(5);
}
