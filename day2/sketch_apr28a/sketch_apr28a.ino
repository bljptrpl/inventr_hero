int Light = 12;
void dot() {
  digitalWrite(Light, HIGH);
  delay(500);
  digitalWrite(Light, LOW);
  delay(100);
}
void dash() {
  digitalWrite(Light, HIGH);
  delay(1200);
  digitalWrite(Light, LOW);
  delay(100);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(Light, OUTPUT);
  digitalWrite(Light, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
//digitalWrite(Light, LOW);
//delay(1000);
//digitalWrite(Light, HIGH);
//delay(1000);

//Hello World in morse code
  dot();
  dot();
  dot();
  dot();
  delay(800);
  dot();
  dash();
  dot();
  dot();
  delay(800);
  dot();
  dash();
  dot();
  dot();
  delay(800);
  dash();
  dash();
  dash();

  delay(1500);
  
  dot();
  dash();
  dash();
  delay(800);
  dash();
  dash();
  dash();
  delay(800);
  dot();
  dash();
  dot();
  delay(800);
  dot();
  dash();
  dot();
  dot();
  delay(800);
  dash();
  dot();
  dot();
  delay(1500);
}
