#include <Arduino.h>
//#include <greenhill.cpp>
#include <zeldaslullaby.cpp>

//outputs
int LED1 = 12, 
    LED2 = 11, 
    LED3 = 10;
//inputs
int Switch1 = 2,
    Switch2 = 3,
    Switch3 = 4;
    
int photoresistor = A0; //analog input
int sensorValue = 0;

void blink(int LED){
    digitalWrite(LED, HIGH);
    delay(800);
    digitalWrite(LED, LOW);
}
void setup() {
  //blink all lights once
  blink(LED1);
  blink(LED2);
  blink(LED3);
  blink(LED_BUILTIN);
  tone(buzzer, 200, 500);
  Serial.begin(9600);

  //zeldalul_setup();
  
}

void loop() {
  
    if (digitalRead(Switch1) == HIGH)
      digitalWrite(LED1, HIGH);
    else digitalWrite(LED1, LOW);
    if(digitalRead(Switch2) == HIGH)
      digitalWrite(LED2, HIGH);
    else digitalWrite(LED2, LOW);
    if(digitalRead(Switch3) == HIGH)
      digitalWrite(LED3, HIGH);
    else digitalWrite(LED3, LOW);
  sensorValue = analogRead(photoresistor);
  Serial.println(sensorValue);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  //tone(buzzer, 200);
}//loop