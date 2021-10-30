#include <SoftwareSerial.h>
#include<AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
SoftwareSerial mySerial(13, 2); // TX, RX

void setup() {
  mySerial.begin(9600);
motor1.setSpeed(255);
motor2.setSpeed(255);
motor3.setSpeed(255);
motor4.setSpeed(255);
}

void loop() {
   
  if(mySerial.available() > 1){ 
       
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    
    if(input == 1111){
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);
    }
    if(input == 0000){//if off code is received
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
    }
    if(input == 2222){
motor1.run(BACKWARD);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD);
    }
    if(input == 2220){//if off code is received
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
    }

if(input == 3333){
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD);
    }
    if(input == 3330){//if off code is received
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
    }

if(input == 4444){
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD);
    }
    if(input == 4440){//if off code is received
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
    }

    
  }
  mySerial.flush();//clear the serial buffer for unwanted inputs     
  
  delay(20);//delay little for better serial communication
 
}
