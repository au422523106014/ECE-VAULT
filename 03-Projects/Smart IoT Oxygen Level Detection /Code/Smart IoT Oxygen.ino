#define BLYNK_TEMPLATE_ID "TMPL3Nj8oS8ci"
#define BLYNK_TEMPLATE_NAME "SMART IOT OXYGEN LEVEL DETECTION AND CROWD SAFETY"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Wi-Fi Credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define MQ2_PIN 34
#define RELAY_PIN 26
#define BUZZER_PIN 27
#define RED 19
#define GREEN 4

LiquidCrystal_I2C lcd(0x27, 16, 2);

BlynkTimer timer;

int gasThreshold = 2000; // Adjust after testing

void sendSensor()
{
  int gasValue = analogRead(MQ2_PIN);

  Serial.print("O2 Value: ");
  Serial.println(gasValue);

  Blynk.virtualWrite(V0, gasValue);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("O2 Value:");
  lcd.setCursor(0, 1);
  lcd.print(gasValue);

  if (gasValue < gasThreshold)
  {
    digitalWrite(RELAY_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ALERT !!!");
    lcd.setCursor(0, 1);
    lcd.print("OXYGEN NEEDED");

    Blynk.virtualWrite(V1, "ALERT !!!");
    Blynk.virtualWrite(V2, "OXYGEN NEEDED");
    Blynk.logEvent("OXYGEN_ALERT", "OXYGEN NEEDED!!!");
    Blynk.virtualWrite(V3, 0);

    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  }
  else
  {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);

    Blynk.virtualWrite(V1, "O2 LEVEL");
    Blynk.virtualWrite(V2, "SUFFICIENT");
    Blynk.virtualWrite(V3, 1);

    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  }
}

void setup()
{
  Serial.begin(115200);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("O2 Monitoring");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
