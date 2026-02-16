#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int Sensor = 7;   
int G_LED = 2;
int R_LED = 3;
int B_LED = 4;
int Buzzer = 5;

void setup() {

  pinMode(Sensor, INPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(R_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  // Welcome Message
  lcd.setCursor(0,0);
  lcd.print("WELCOME");
  lcd.setCursor(0,1);
  lcd.print("System Ready...");
  delay(1000);
  lcd.clear();
}

void loop() {

  digitalWrite(B_LED, HIGH);   // System Ready Indicator

  int state = digitalRead(Sensor);

  if (state == HIGH) {
    // SENSOR OK CONDITION
    digitalWrite(G_LED, HIGH);
    digitalWrite(R_LED, LOW);
    digitalWrite(B_LED, LOW);
    digitalWrite(Buzzer, LOW);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sensor Working");
    lcd.setCursor(0,1);
    lcd.print("Testing OK");
  }
  else {
    // SENSOR FAULT CONDITION
    digitalWrite(G_LED, LOW);
    digitalWrite(R_LED, HIGH);
    digitalWrite(B_LED, LOW);
    digitalWrite(Buzzer, HIGH);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERT!");
    lcd.setCursor(0,1);
    lcd.print("Check Sensor");
    delay(5000);
  }

  delay(500);
}
