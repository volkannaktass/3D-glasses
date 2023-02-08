// defines pins numbers
const int trigPinRight = 10;
const int echoPinRight = 11;
const int buzzerRight = 9;
const int ledPin = 13;

const int buzzerLeft = 7;
const int echoPinLeft = 5;
const int trigPinLeft = 6;

// defines variables
long durationRight;
int distanceRight;
int safetyDistanceRight;

long durationLeft;
int distanceLeft;
int safetyDistanceLeft;

void setup() {
pinMode(trigPinRight, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPinRight, INPUT); // Sets the echoPin as an Input
pinMode(buzzerRight, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(trigPinLeft   , OUTPUT);
pinMode(echoPinLeft, INPUT); // Sets the echoPin as an Input
pinMode(buzzerLeft, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {

  // Clears the trigPin
digitalWrite(trigPinRight, LOW);
delayMicroseconds(2);
digitalWrite(trigPinLeft, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinRight, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinRight, LOW);
digitalWrite(trigPinLeft, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinLeft, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
durationRight = pulseIn(echoPinRight, HIGH);
durationLeft = pulseIn(echoPinLeft, HIGH);
// Calculating the distance
distanceRight= durationRight*0.034/2;
distanceLeft= durationLeft * 0.034/2;
 
safetyDistanceRight = distanceRight;
safetyDistanceLeft = distanceLeft;
 
if (safetyDistanceRight <= 100 && safetyDistanceLeft <= 100){
  digitalWrite(buzzerRight, HIGH);
  digitalWrite(buzzerLeft, HIGH);
  Serial.print("distanceRight: ");
  Serial.println(distanceRight);
  Serial.print("distanceLeft: ");
  Serial.println(distanceLeft);
  //digitalWrite(ledPin, HIGH);
}
else if(safetyDistanceRight <= 100 && safetyDistanceLeft > 100){
  digitalWrite(buzzerRight, HIGH);
  digitalWrite(buzzerLeft, LOW);
  Serial.print("distanceRight: ");
  Serial.println(distanceRight);
  Serial.print("distanceLeft: ");
  Serial.println(distanceLeft);
 }
else if(safetyDistanceRight > 100 && safetyDistanceLeft <= 100){
  digitalWrite(buzzerRight, LOW);
  digitalWrite(buzzerLeft, HIGH);
  Serial.print("distanceRight: ");
  Serial.println(distanceRight);
  Serial.print("distanceLeft: ");
  Serial.println(distanceLeft);
 }
else{
  digitalWrite(buzzerRight, LOW);
  digitalWrite(buzzerLeft, LOW);
  Serial.print("distanceRight: ");
  Serial.println(distanceRight);
  Serial.print("distanceLeft: ");
  Serial.println(distanceLeft);
}

// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
//Serial.print("Distance2: ");
//Serial.println(distance2);
}
