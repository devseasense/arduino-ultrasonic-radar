#define TRIGPIN 11
#define ECHOPIN 10

float duration, distance;

void setup() {
  Serial.begin(9600);

  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(20);  

  digitalWrite(TRIGPIN, LOW);

  duration = pulseIn(ECHOPIN, HIGH);

  
  distance = (duration / 2) * 0.343;  

  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  delay(100);
}
