int const GAS_Sensor = A1;
int Buzzer = 7;
int pirsensor = 0;
void setup(){
  	pinMode(Buzzer, OUTPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}
void loop(){
  int value = analogRead(GAS_Sensor);
  value = map(value, 300, 750, 0, 100);
  if (value > 50)
  {
    digitalWrite(Buzzer, HIGH);
  }
  else
  {
    digitalWrite(Buzzer, LOW) ;
    
  }
  pirsensor = digitalRead(2);
  if (pirsensor == 1) {
    digitalWrite(13, HIGH);
    Serial.println("Motion detected , presence of human or animals");
  } else {
    digitalWrite(13, LOW);
    Serial.println("Motion not detected");
  }
  
  delay(1000);
  }
