#include <Arduino.h>

//outputs
int RED = 12, 
    GREEN = 11, 
    YELLOW = 10;
//inputs
int Switch1 = 2; 
   
void blink(int LED){
    digitalWrite(LED, HIGH);
    delay(800);
    digitalWrite(LED, LOW);
}
void setup() {
  //blink all lights once
  blink(RED);
  blink(GREEN);
  blink(YELLOW);
}

void loop() {
  
    if (digitalRead(Switch1) == HIGH)
    {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, HIGH);
      digitalWrite(YELLOW, HIGH);
    }
    else{
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(YELLOW, LOW);
    }
}