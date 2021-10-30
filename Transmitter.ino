#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //TX, RX

int buttonPin1 = 8;
int buttonPin2 = 7;
int buttonPin3 = 6;
int buttonPin4 = 5;
int buttonPin5 = 4;
boolean onOff = 0;
void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  mySerial.begin(9600);
}

void loop() {
 
  int buttonState1 = digitalRead(buttonPin1);//read button state
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  int buttonState5 = digitalRead(buttonPin5);
  
  if(buttonState1 == 1){//if button is down
    mySerial.println(1111);//send unique code to the receiver to turn on. In this case 1111
    onOff = 1;//set boolean to 1
  }
  if(buttonState1 == 0 && onOff == 1){//Verifier to send off signal once
    mySerial.println(0000);//send unique code to the receiver to turn off. In this case 0000
  }

  if(buttonState2 == 1){//if button is down
    mySerial.println(2222);//send unique code to the receiver to turn on. In this case 1111
    onOff = 1;//set boolean to 1
  }
  if(buttonState2 == 0 && onOff == 1){//Verifier to send off signal once
    mySerial.println(2220);//send unique code to the receiver to turn off. In this case 0000
  }

  if(buttonState3 == 1){//if button is down
    mySerial.println(3333);//send unique code to the receiver to turn on. In this case 1111
    onOff = 1;//set boolean to 1
  }
  if(buttonState3 == 0 && onOff == 1){//Verifier to send off signal once
    mySerial.println(3330);//send unique code to the receiver to turn off. In this case 0000
  }
  if(buttonState4 == 1){//if button is down
    mySerial.println(4444);//send unique code to the receiver to turn on. In this case 1111
    onOff = 1;//set boolean to 1
  }
  if(buttonState4 == 0 && onOff == 1){//Verifier to send off signal once
    mySerial.println(4440);//send unique code to the receiver to turn off. In this case 0000
  }



  
  delay(20);//delay little for better serial communication
}
