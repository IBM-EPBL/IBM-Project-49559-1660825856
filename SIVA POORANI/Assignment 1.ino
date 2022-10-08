#define trigPin 12
#define echoPin 11
#define buzzer 8

long duration;
int distance;
int pirsensor = 0;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin , HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if(distance<=80)
  { 
    digitalWrite(buzzer,HIGH);
    Serial.println(" some is near the door");
  }
  else
   { 
    	digitalWrite(buzzer,LOW);
   }
    pirsensor = digitalRead(2);
  if (pirsensor == 1) {
    digitalWrite(13, HIGH);
    Serial.println("LED on someone is in the room");
  } else {
    digitalWrite(13, LOW);
    Serial.println("LED OFF no one is in the room");
  }
  delay(1000);
}
