/*
* Garbage Monitoring Module 
* Ultrasonic Sensor (HC_SR04)
* LCD Display-16x2
* Buzzer set at 2000Khz
*/
/*
 * LCD pins- Arduino pins
 vss-gnd
 vdd-5v
 vo-6
 rs-12
 rw-gnd
 e-11
 d4-5
 d5-4
 d6-3
 d7-2
 A-5v
 K-gnd

 Buzzer Pins
 positive - pin 8
 negative - gnd

 Ultrasonic Sensor Pins
 VCC - 5V 
 trig - 9
 echo - 10
 Gnd - Gnd
 */
#include <LiquidCrystal.h> 
int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// defining buzzer pins
 const int buzzer = 8;
// defining the ultrasonic pins
int percent = 0;
int check = 0;
const int trigPin = 9;
const int echoPin = 10;
// defining variables
long duration;
int distance;
void setup() {
     analogWrite(6,Contrast);
     lcd.begin(16, 2);
     pinMode(buzzer, OUTPUT);

pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(20);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(100);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
 // For Buzzer and flashing congestion level
 percent= distance*100/8;
  if (percent <= 25 || distance > 300)
   {
    tone(buzzer, 2000);
    lcd.setCursor(0,1);
    lcd.print("GARBAGE IS FULL");
     
   }
   else
   {
    noTone(buzzer);
   }
lcd.setCursor(0,0);
     //lcd.print("DISTANCE = ");
     //lcd.print(distance);
//lcd.setCursor(0,1);
     if (distance > 200)
     lcd.print("CONGESTION =100%");
     if(percent >= 100 && distance <= 200)
     lcd.print("Retry in 3' pipe");
     else
     lcd.print("CONGESTION = ");
     lcd.print(100-percent);
     lcd.print("%");
     delay(500);

lcd.clear();     
}
