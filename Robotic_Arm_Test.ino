#include <Servo.h>
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;
int servoAngle;

int button1 = 4;
int button2 = 7;
int button3 = 8;
int button4 = 12;

int potPin1 = A0;
int potPin2 = A1;
int potReading1;
int potReading2;
int mappedPotReading1;
int mappedPotReading2;

int buttonPress1;
int buttonPress2;
int buttonPress3;
int buttonPress4;

int xPin = A2;
int yPin = A3;

int xReading;
int yReading;

int mappedXreading;
int mappedYreading;

void setup() {
  Serial.begin(9600);
  pinMode(potPin1, INPUT);
  pinMode(potPin2, INPUT);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);

  servo01.attach(3);
  servo02.attach(5);
  servo03.attach(6);
  servo04.attach(9);
  servo05.attach(10);
  servo06.attach(11);
}

void loop() {
  //-----WRIST-----
  potReading1 = analogRead(potPin1);
  mappedPotReading1 = map(potReading1, 0, 1023, 0, 180);
  servo04.write(mappedPotReading1);
  

  //-----GRIPPER-----
  potReading2 = analogRead(potPin2);
  mappedPotReading2 = map(potReading2, 0, 1023, 0, 180);
  servo06.write(mappedPotReading2);
  

  //-----PITCH-----
  buttonPress3 = digitalRead(button3);
  buttonPress4 = digitalRead(button4);
  if (buttonPress3 == 1) {
    servoAngle += 1;
  }
  if (buttonPress4 == 1) {
    servoAngle -= 1;
  }
  servo05.write(servoAngle);
  

  //-----WAIST/SHOULDER-----
  xReading = analogRead(xPin);
  mappedXreading = map(xReading, 0, 1023, 0, 180);
  servo01.write(mappedXreading);
  yReading = analogRead(yPin);
  mappedYreading = map(yReading, 0, 1023, 0, 180);
  servo02.write(mappedYreading);
  

  //-----ELBOW-----
  buttonPress1 = digitalRead(button1);
  buttonPress2 = digitalRead(button2);
  if (buttonPress1 == 1 || buttonPress2 == 1) {
    if (buttonPress1 == 1) {
      servo03.writeMicroseconds(2000);
    }
    if (buttonPress2 == 1) {
      servo03.writeMicroseconds(1000);
    }
  }
  else {
    servo03.writeMicroseconds(1500);
  }
}
