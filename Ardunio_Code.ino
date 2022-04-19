const int trigPin = 9;
const int echoPin = 10;
int led = 13;
long duration;
int distanceCm, distanceInch;
int oldValue = 0 , newValue = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm =(duration/2)/29.1;
  
  newValue = distanceCm;
  if(newValue != oldValue)
  {
    //Serial.print("Distance: ");
    Serial.println(distanceCm);
    //Serial.println(" cm");
    oldValue = newValue;
  }
   if((distanceCm<=30)) 
  {
    digitalWrite(led, HIGH);
   }
   else if(distanceCm>30)
  {
     digitalWrite(led, LOW);
   }
  delay(1000); 
}
