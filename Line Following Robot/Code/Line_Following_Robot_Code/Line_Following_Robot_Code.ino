#include <AFMotor.h>

#define max_speed 100
#define max_offset 20

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


void setup() {
  Serial.begin(9800);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop() {
  int s1 = analogRead(A0);
  int s2 = analogRead(A1);
  int s3 = analogRead(A2);
  int s4 = analogRead(A3);
  int s5 = analogRead(A4);

  if (s1 <= 500 && s2 <= 500  && s4 <= 500 && s5 <= 500){ // 0 0 0 0
    moveForward();
    Serial.println("Forward");
  }
  if (s1 <= 500 && s2 >= 500  && s4 >= 500 && s5 <= 500){ // 0 1 1 0
    moveForward();
    Serial.println("Forward");
  }
  else if (s1 <= 500 && s2 >= 500 && s4 <= 500 && s5 <= 500){ // 0 1 0 0
    moveRight();
    Serial.println("right");
  }
  else if (s1 <= 500 && s2 <= 500 && s4 >= 500 && s5 <= 500){ // 0 0 1 0
    moveLeft();
    Serial.println("left");
  }
 
  else if (s1 <= 500 && s2 <= 500  && s4 <= 500 && s5 >= 500){ // 0 0 0 1
    moveextrimeLeft();
    Serial.println("extrime left");
  }
 
    else if (s1 <= 500 && s2 <= 500  && s4 >= 500 && s5 >= 500){ // 0 0 1 1
    moveextrimeLeft();
    Serial.println("extrime left");
  }
   else if (s1 <= 500 && s2 >= 500  && s4 >= 500 && s5 >= 500){ // 0 1 1 1
    moveextrimeLeft();
    Serial.println("extrime left");
  }
  else if (s1 >= 500 && s2 <= 500  && s4 <= 500 && s5 <= 500){ //  1 0 0 0
    moveextrimeRight();
    Serial.println("extrime right");
  }
    else if (s1 >= 500 && s2 >= 500  && s4 <= 500 && s5 <= 500){ // 1 1 0 0
    moveextrimeRight();
    Serial.println("extrime right");
  }
      else if (s1 >= 500 && s2 >= 500  && s4 >= 500 && s5 <= 500){ // 1 1 1 0
    moveextrimeRight();
    Serial.println("extrime right");
  }
  else if (s1 >= 500 && s2 >= 500 && s4 >= 500 && s5 >= 500){ // 1 1 1 1
    Stop();
    Serial.println("stop");
  }
  else{
    Stop();
  }
 
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
void moveForward() {
  motor1.setSpeed(90);
  motor2.setSpeed(90);
  motor3.setSpeed(90);
  motor4.setSpeed(90);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

}
void moveBackward() {
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void moveRight() {
  motor1.setSpeed(80);
  motor2.setSpeed(80);
  motor3.setSpeed(80);
  motor4.setSpeed(80);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void moveLeft() {
  motor1.setSpeed(80);
  motor2.setSpeed(80);
  motor3.setSpeed(80);
  motor4.setSpeed(80);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void moveextrimeRight() {
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
void moveextrimeLeft() {
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
