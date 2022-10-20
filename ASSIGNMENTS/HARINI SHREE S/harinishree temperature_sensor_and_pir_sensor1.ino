int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
int BUZZER = 13;
int pirsensor = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(BUZZER,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  // set threshold temperature to activate LEDs
  baselineTemp = 10;
  // measure temperature in Celsius
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  // convert to Fahrenheit
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
   if (celsius < baselineTemp) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(BUZZER, LOW); // turn off Piezo Buzzer
  }
  if (celsius >= baselineTemp && celsius <= baselineTemp + 10) {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(BUZZER, LOW); // turn off Piezo Buzzer
  }
  if (celsius >= baselineTemp + 10 && celsius <= baselineTemp + 20) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(BUZZER, LOW); // turn off Piezo Buzzer
  }
  if (celsius >= baselineTemp + 20 && celsius <= baselineTemp + 30) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(BUZZER, LOW); // turn off Piezo Buzzer
  }
  if (celsius >= baselineTemp + 30) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(BUZZER, HIGH); // turn on Piezo Buzzer
  }
  delay(1000); // Wait for 1000 millisecond(s)
  pirsensor = digitalRead(2);
  if (pirsensor == 1) {
    digitalWrite(12, HIGH);
    Serial.println("Motion detected ,LED ON");
  } else {
    digitalWrite(12, LOW);
    Serial.println("Motion not detected LED OFF");
  }
  
  delay(1000);
}