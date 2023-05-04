#include <Arduino.h>
#include <zeldaslullaby.cpp>

//outputs
int LED1 = 12, 
    LED2 = 11, 
    LED3 = 10;
//inputs
int Switch1 = 2,
    Switch2 = 3,
    Switch3 = 4;

//day 6 - photoresistor     
int photoresistor = A0; //analog input
int sensorValue = 0;

//day 7 - battery operations
unsigned int batteryCapacity = 50000;
unsigned int batteryLevel = 0;
unsigned int ticks = 0;
unsigned int wait = 100;
double PercentFull;
 


void blink(int LED){
    digitalWrite(LED, HIGH);
    delay(800);
    digitalWrite(LED, LOW);
}
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  //blink all lights once
  blink(LED1);
  blink(LED2);
  blink(LED3);
  blink(LED_BUILTIN);
  tone(buzzer, 200, 500);
  Serial.begin(9600);

  //zeldalul_setup();
  
}

void PrintBatteryPercentage() {
// print the elasped time
  Serial.print(ticks);
  Serial.print(" ms    charge at ");
 
//  convert the integers to decimal numbers, divide them and print...
  PercentFull=100*((double)batteryLevel / (double)batteryCapacity);
  Serial.print(PercentFull);
 
// print a percent character and line return...
  Serial.println("%");
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


  sensorValue = analogRead(photoresistor); // read the value from the sensor:
  batteryLevel += sensorValue;
  ticks += wait;
 
  if(batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.print(" ms     ");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity; // to prevent integer from continuing to increase
    ticks = 0;
    delay(20000);      // long pause
  }
  else {
    PrintBatteryPercentage();
  }
 
  delay(wait);

}//loop