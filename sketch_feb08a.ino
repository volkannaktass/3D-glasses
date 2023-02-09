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
pinMode(trigPinLeft, OUTPUT);
pinMode(echoPinLeft, INPUT); // Sets the echoPin as an Input
pinMode(buzzerLeft, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {

  // Clears the trigPin
digitalWrite(trigPinRight, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPinRight, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinRight, LOW);



// Reads the echoPin, returns the sound wave travel time in microseconds
durationRight = pulseIn(echoPinRight, HIGH);
//
// Calculating the distance
distanceRight= durationRight*0.034/2;
//
 
safetyDistanceRight = distanceRight;


Serial.println("DISTANCE RIGHT");
Serial.println(distanceRight);
 if(safetyDistanceRight <= 100){
   digitalWrite(buzzerRight, HIGH);
   
 }
 else{
   digitalWrite(buzzerRight, LOW);
   
 }



 
durationRight = pulseIn(echoPinRight, LOW);
pulseIn(echoPinRight, LOW);

digitalWrite(trigPinLeft, LOW);
delayMicroseconds(2);

digitalWrite(trigPinLeft, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinLeft, LOW);
 
durationLeft = pulseIn(echoPinLeft, HIGH);
distanceLeft= durationLeft * 0.034/2;
safetyDistanceLeft = distanceLeft;
Serial.println("Distance LEFT");
Serial.println(distanceLeft);
 if(safetyDistanceLeft <= 100){
   digitalWrite(buzzerLeft, HIGH);

   
 }
 else{
   digitalWrite(buzzerLeft, LOW);

 }
durationLeft = pulseIn(echoPinLeft, LOW);
pulseIn(echoPinLeft, LOW);
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
//Serial.print("Distance2: ");
//Serial.println(distance2);
}
