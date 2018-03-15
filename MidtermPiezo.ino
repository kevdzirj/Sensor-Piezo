int trgPin = 11;
int echPin = 12;
int green = 9;
int piezo = 4;
long microsecond;
long centimeter;

void setup() {
pinMode(trgPin, OUTPUT); 
pinMode(echPin, INPUT); 
pinMode(green, OUTPUT); 
pinMode(piezo, OUTPUT);
Serial.begin(9600); 
}

void loop() {
digitalWrite(trgPin, HIGH); 
delayMicroseconds(10);
digitalWrite(trgPin, LOW); //starts the internal clock by sending out a "ping"

microsecond = pulseIn(echPin, HIGH); //time the echoPin takes to arrive
centimeter= ((microsecond/2)*.03436); //divided by 2 because the sensor records the time hitting object to the time back to sensor & the .03436 is the conversion factor fo speed of sound

if (centimeter < 25 && centimeter > 0) { 
  digitalWrite(green,HIGH); 
  tone(piezo, 1000);
  delay(500);
  noTone(piezo);
  delay(5);
} 

 if (centimeter >=25 && centimeter <=75){
  digitalWrite(green,HIGH); 
  tone(piezo, 200);
  delay(50);
  tone(piezo, 400);
  delay(50);
  tone(piezo, 600);
  delay(50);
  tone(piezo, 800);
  delay(50);
  noTone(piezo);
}

else { 
digitalWrite(green,LOW); 
} 
}
