#include <Arduino.h>
//#include <greenhill.cpp>
#include <zeldaslullaby.cpp>

//outputs
int RED = 12, 
    GREEN = 11, 
    YELLOW = 10;
//inputs
int Switch1 = 2,
    Switch2 = 3,
    Switch3 = 4;
    


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
  tone(buzzer, 200, 2000);
  // greenhill_setup();
  zeldalul_setup();
}

void loop() {
  
    if (digitalRead(Switch1) == HIGH)
      digitalWrite(RED, HIGH);
    else digitalWrite(RED, LOW);
    if(digitalRead(Switch2) == HIGH)
      digitalWrite(GREEN, HIGH);
    else digitalWrite(GREEN, LOW);
    if(digitalRead(Switch3) == HIGH)
      digitalWrite(YELLOW, HIGH);
    else digitalWrite(YELLOW, LOW);
    
  //tone(buzzer, 200);
}//loop