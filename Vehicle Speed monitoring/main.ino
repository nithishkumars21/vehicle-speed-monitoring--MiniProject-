#include <Wire.h>
#include <LiquidCrystal_I2C.h> //library for LCD display

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensor1Pin = 2;
const int sensor2Pin = 3;
const int buzzerPin  = 8;
const int ledPin     = 9;

const float SENSOR_DISTANCE_M = 10.0;
const float SPEED_LIMIT_KMH   = 40.0;

unsigned long triggerTime1 = 0;
bool waitingForSensor2     = false;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(sensor1Pin, INPUT_PULLUP);
  pinMode(sensor2Pin, INPUT_PULLUP);
  pinMode(buzzerPin,  OUTPUT);
  pinMode(ledPin,     OUTPUT);
  showWelcome();
}

void showWelcome() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wildlife Zone");
  lcd.setCursor(0, 1);
  lcd.print("Speed Monitor ON");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Waiting for");
  lcd.setCursor(0, 1);
  lcd.print("Vehicle...");
}

void triggerAlert(float speed) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("!! OVERSPEED !!");
  lcd.setCursor(0, 1);
  lcd.print("Slow Down Now!");
  Serial.print("ALERT! Speed: ");
  Serial.print(speed, 1);
  Serial.println(" km/h — Limit exceeded!");
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
}

void showSpeed(float speed) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.print(speed, 1);
  lcd.print(" km/h");
  lcd.setCursor(0, 1);
  if (speed > SPEED_LIMIT_KMH) {
    lcd.print("ALERT TRIGGERED!");
    triggerAlert(speed);
  } else {
    lcd.print("Speed OK. Safe.");
    Serial.print("Speed: ");
    Serial.print(speed, 1);
    Serial.println(" km/h — Within limit");
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
  }
  delay(3000);
  showWelcome();
}

void loop() {
  bool s1 = (digitalRead(sensor1Pin) == LOW);
  bool s2 = (digitalRead(sensor2Pin) == LOW);

  if (s1 && !waitingForSensor2) {
    triggerTime1 = millis();
    waitingForSensor2 = true;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Vehicle at S1");
    lcd.setCursor(0, 1);
    lcd.print("Timing started");
    Serial.println("Sensor 1 triggered");
  }

  if (s2 && waitingForSensor2) {
    unsigned long elapsed = millis() - triggerTime1;
    if (elapsed > 0) {
      float timeSec = elapsed / 1000.0;
      float speedMS = SENSOR_DISTANCE_M / timeSec;
      float speedKMH = speedMS * 3.6;
      waitingForSensor2 = false;
      Serial.print("Time elapsed: ");
      Serial.print(timeSec, 2);
      Serial.println("s");
      showSpeed(speedKMH);
    }
  }

  if (waitingForSensor2 && (millis() - triggerTime1 > 30000)) {
    waitingForSensor2 = false;
    showWelcome();
  }
}