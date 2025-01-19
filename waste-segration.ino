#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
// Servo servo2;
int soil_moisture = A0;
int trigPin = 7;
int echoPin = 8;
int pos = 90;
// int pos1 = 0;
int duration, distance;
int buzzer = 2;
int led_pin = 3;
int near_distance = 40;
int threshold_moisture = 400;
int moistureValue;

void setup()
{ // setup
    Serial.begin(9600);
    myservo.attach(9);
    // myservo1.attach(10);
    lcd.init();
    lcd.backlight();
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop()
{ // run
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
    delay(100);
    if (distance < near_distance)
    {
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("STARTING");
        //  myservo1.write(pos1);
        //  for (pos1 = 0; pos1 <= 70; pos1++) {
        //  myservo1.write(pos1);
        // delay(30);
        // }
        // delay(50);
        // for (pos1 = 70; pos1 >= 0; pos1--) {
        //   myservo1.write(pos1);
        //  delay(30);
        // }

        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("PROCESSING");
        moistureValue = analogRead(soil_moisture);
        Serial.print("Moisture Value: ");
        Serial.println(moistureValue);
        if (moistureValue < threshold_moisture)
        {
            lcd.clear();
            lcd.setCursor(4, 0);
            lcd.print("wanna be wet");
            myservo.write(pos);
            for (pos = 90; pos <= 150; pos++)
            {
                myservo.write(pos);
                delay(40);
            }
            delay(50);
            for (pos = 150; pos >= 90; pos--)
            {
                myservo.write(pos);
                delay(20);
            }
        }
        else if (moistureValue > threshold_moisture)
        {
            lcd.clear();
            lcd.setCursor(4, 0);
            lcd.print("why so dry");
            for (pos = 90; pos >= 30; pos--)
            {
                myservo.write(pos);
                delay(40);
            }
            delay(500);
            for (pos = 30; pos <= 90; pos++)
            {
                myservo.write(pos);
                delay(20);
            }
            delay(500);
        }
    }
}