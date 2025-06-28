#define BLYNK_TEMPLATE_ID "TMPL30HoMHZDP"
#define BLYNK_TEMPLATE_NAME "5 Smart parking system"
#define BLYNK_AUTH_TOKEN  "FysXe1rN9Iae1Y2VUXLq1mUjtO1099Bq"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
char ssid[] = "Wokwi-GUEST";
char pass[] = "";

/* Ultrasonic pins  */
#define TRIG1 5
#define ECHO1 18
#define TRIG2 19
#define ECHO2 23

/* I²C LCD  */
LiquidCrystal_I2C lcd(0x27, 16, 2);

BlynkTimer timer;


long readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);  // 30 ms timeout
  return duration * 0.034 / 2;
}

void updateParkingStatus() {
  long d1 = readDistance(TRIG1, ECHO1);
  long d2 = readDistance(TRIG2, ECHO2);

  bool occ1 = (d1 > 0 && d1 < 15);   // <15 cm ⇒ occupied
  bool occ2 = (d2 > 0 && d2 < 15);

  /* --- Serial Monitor --- */
  Serial.printf("Slot 1: %s | Slot 2: %s\n",
                occ1 ? "Occupied" : "Free",
                occ2 ? "Occupied" : "Free");

  /* --- LCD --- */
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("S1: ");
  lcd.print(occ1 ? "Occupied" : "Free    ");
  lcd.setCursor(0, 1);
  lcd.print("S2: ");
  lcd.print(occ2 ? "Occupied" : "Free    ");

  /* --- Blynk Dashboard --- */
  Blynk.virtualWrite(V0, occ1 ? "Occupied" : "Free");
  Blynk.virtualWrite(V1, occ2 ? "Occupied" : "Free");
}

void setup() {
  Serial.begin(115200);

  /* Set pin modes */
  pinMode(TRIG1, OUTPUT);  pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT);  pinMode(ECHO2, INPUT);

  /* LCD init */
  lcd.init();
  lcd.backlight();
  lcd.print("Smart Parking...");

  /* Connect Wi‑Fi + Blynk */
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  /* Call update every 2 s */
  timer.setInterval(2000L, updateParkingStatus);
}

void loop() {
  Blynk.run();
  timer.run();
}
