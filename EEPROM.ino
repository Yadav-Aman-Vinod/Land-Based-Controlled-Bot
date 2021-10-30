#include <IRremote.h>
#include <IRremoteInt.h>
#include <IRremoteTools.h>

#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
}

void loop() {

  for (int i = 0; i <= 3; i++) {

    if (digitalRead(12) == true)
    {
      while (digitalRead(12) == true) {}
      EEPROM.write(i, 12);
    }
    if (digitalRead(11) == true)
    {
      while (digitalRead(11) == true) {}
      EEPROM.write(i, 11);
    }
    if (digitalRead(10) == true)
    {
      while (digitalRead(10) == true) {}
      EEPROM.write(i, 10);
    }
    if (digitalRead(9) == true)
    {
      while (digitalRead(9) == true) {}
      EEPROM.write(i, 9);
    }

  }
  Serial.println(EEPROM.read(0));
  delay(1000);
  Serial.println(EEPROM.read(1));
  delay(1000);
  Serial.println(EEPROM.read(2));
  delay(1000);
  Serial.println(EEPROM.read(3));
  delay(100000);
}
