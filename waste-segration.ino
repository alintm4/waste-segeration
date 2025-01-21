#include <Wire.h>

#include <LiquidCrystal_I2C.h>

#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
Servo myservo1;

int soil_moisture = A0;
int trigPin = 7;
int echoPin = 8;
int pos = 90;
int pos1 = 0;
int duration, distance;
int buzzer = 2;
int led_pin = 3;
int metal = 4;
int near_distance = 35;
int threshold_moisture = 550;
int moistureValue;
int moisturepin = 5;

void setup() { //setup
  Serial.begin(9600);
  myservo.attach(9);
  myservo1.attach(10);
  lcd.init();
  lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(metal, INPUT);
  pinMode(moisturepin, OUTPUT);

}

void loop() { //run
  lcd.setCursor(0, 0);
  lcd.print("WASTE SEGREGATOR");
  lcd.setCursor(4, 1);
  lcd.print("USE ME");

  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 29 / 2;
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  delay(1000);
  if (distance <= near_distance) {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("STARTING");
    if (digitalRead(metal) == HIGH) {
      digitalWrite(moisturepin, LOW);
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("METAL DETECTED");
      myservo1.write(80); //Moist SERVO
      delay(500);
      myservo.write(90);

      delay(500);

      for (pos = 50; pos >= 0; pos--) {
        myservo.write(pos);
        delay(30);
      }
      delay(500);
      for (pos1 = 90; pos1 <= 130; pos1++) {
        myservo1.write(pos1);
        delay(30);
      }
      delay(500);
      for (pos1 = 130; pos1 >= 90; pos1--) {
        myservo1.write(pos1);
        delay(30);
      }
      delay(500);
      for (pos = 0; pos <= 50; pos++) {
        myservo.write(pos);
        delay(30);
      }
      delay(1000);
    } else {
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("PROCESSING");
      digitalWrite(moisturepin, HIGH);
      moistureValue = analogRead(soil_moisture);
      Serial.print("Moisture Value: ");
      Serial.println(moistureValue);
      if (moistureValue < threshold_moisture) {
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("WET SUBSTANCE");
        myservo1.write(80);
        delay(1000);
        myservo.write(90);
        delay(1000);

        for (pos = 90; pos <= 150; pos++) {
          myservo1.write(pos);
          delay(40);
        }
        delay(50);
        for (pos = 150; pos >= 90; pos--) {
          myservo1.write(pos);
          delay(20);
        }

      } else if (moistureValue > threshold_moisture) {
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("DRY SUBSTANCE");
        myservo.write(90);
        delay(1000);
        for (pos = 90; pos >= 30; pos--) {
          myservo1.write(pos);
          delay(40);
        }
        delay(500);
        for (pos = 30; pos <= 90; pos++) {
          myservo1.write(pos);
          delay(20);
        }
        delay(500);
      } else {
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("UNCERTAIN");
        delay(500);
      }
    }
  }
  digitalWrite(moisturepin, LOW);
}