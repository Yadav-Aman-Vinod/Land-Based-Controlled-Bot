/*
    Rotary Encoder - Polling Example

    The circuit:
      encoder pin A to Arduino pin 2
      encoder pin B to Arduino pin 3
      encoder ground pin to ground (GND)

*/

#include <Rotary.h>

Rotary r = Rotary(2, 3);

void setup() {

  pinMode(10, INPUT);
  Serial.begin(9600);
  Serial.println("Hi............ please enter your sex");
  delay(1300);
  Serial.println("Turn right for male and turn left for female and press enter");
  delay(100);

}

void loop() {
  unsigned char a = r.process();
  if (a) {
    Serial.println(a == DIR_CW ? "male" : "female");

  }
    if (digitalRead(10) == false){
    while (digitalRead(10) == false) {}
    Serial.println("Enter your weight ");
    delay(100);
    
    }



}


