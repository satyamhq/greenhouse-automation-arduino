/*
 AUTOMATION IN GREENHOUSE CLIMATE CONTROL
 Board: Arduino Uno R3
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// ---------- LCD I2C ----------
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------- DHT22 ----------
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ---------- Analog Sensors ----------
#define LDR_PIN A0
#define SOIL_PIN A1

// ---------- Relays (Active LOW) ----------
#define RELAY_FAN   3   // IN1 - Fan
#define RELAY_PUMP  4   // IN2 - Pump
#define RELAY_LIGHT 5   // IN3 - Grow light
#define RELAY_SPARE 10  // IN4 - Spare

#define RELAY_ON  LOW
#define RELAY_OFF HIGH

// ---------- Buzzer & LEDs ----------
#define BUZZER_PIN 6
#define LED_GREEN  7
#define LED_RED    8
#define LED_WHITE  9

// ---------- Variables ----------
float temperature = 0.0;
float humidity = 0.0;
int ldrValue = 0;
int soilValue = 0;

bool fanOn = false;
bool pumpOn = false;
bool lightOn = false;

// ---------- Thresholds ----------

// LDR thresholds (0–1023)
int LDR_DARK   = 700;  // Dark → Light ON
int LDR_BRIGHT = 500;  // Bright → Light OFF

// Temperature & Humidity
float TEMP_ON  = 30.0; // Fan ON above this
float TEMP_OFF = 27.0; // Fan OFF below this

float HUM_ON  = 85.0;  // Fan ON if humidity high
float HUM_OFF = 75.0;  // Fan OFF when normal

// Soil moisture (higher value = drier soil)
int SOIL_DRY = 700;  // Pump ON
int SOIL_WET = 450;  // Pump OFF

// Timers
unsigned long lastSensorRead = 0;
unsigned long lastDisplayUpdate = 0;
const unsigned long SENSOR_INTERVAL  = 1000; // 1 second
const unsigned long DISPLAY_INTERVAL = 800;  // 0.8 second

// ================= SETUP =================
void setup() {
  Serial.begin(115200);

  // LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Greenhouse ");
  lcd.setCursor(0, 1);
  lcd.print(" Initializing ");
  delay(1500);
  lcd.clear();

  // DHT
  dht.begin();

  // Sensors
  pinMode(LDR_PIN, INPUT);
  pinMode(SOIL_PIN, INPUT);

  // Relays
  pinMode(RELAY_FAN, OUTPUT);
  pinMode(RELAY_PUMP, OUTPUT);
  pinMode(RELAY_LIGHT, OUTPUT);
  pinMode(RELAY_SPARE, OUTPUT);

  digitalWrite(RELAY_FAN, RELAY_OFF);
  digitalWrite(RELAY_PUMP, RELAY_OFF);
  digitalWrite(RELAY_LIGHT, RELAY_OFF);
  digitalWrite(RELAY_SPARE, RELAY_OFF);

  // Buzzer & LEDs
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);

  digitalWrite(LED_GREEN, HIGH); // System ON
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_WHITE, LOW);
}

// ================= LOOP =================
void loop() {
  unsigned long now = millis();

  // ---- 1) Sensor Reading ----
  if (now - lastSensorRead >= SENSOR_INTERVAL) {
    lastSensorRead = now;

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    if (!isnan(h)) humidity = h;
    if (!isnan(t)) temperature = t;

    ldrValue = analogRead(LDR_PIN);
    soilValue = analogRead(SOIL_PIN);

    Serial.print("T=");
    Serial.print(temperature);
    Serial.print("C  H=");
    Serial.print(humidity);
    Serial.print("%  LDR=");
    Serial.print(ldrValue);
    Serial.print("  SOIL=");
    Serial.println(soilValue);
  }

  // ---- 2) Light Control ----
  if (!lightOn && ldrValue >= LDR_DARK) {
    lightOn = true;
  }
  if (lightOn && ldrValue <= LDR_BRIGHT) {
    lightOn = false;
  }
  digitalWrite(RELAY_LIGHT, lightOn ? RELAY_ON : RELAY_OFF);
  digitalWrite(LED_WHITE, lightOn ? HIGH : LOW);

  // ---- 3) Fan Control ----
  bool needFan = (temperature >= TEMP_ON) || (humidity >= HUM_ON);
  bool stopFan = (temperature <= TEMP_OFF) && (humidity <= HUM_OFF);

  if (!fanOn && needFan) fanOn = true;
  if (fanOn && stopFan)  fanOn = false;

  digitalWrite(RELAY_FAN, fanOn ? RELAY_ON : RELAY_OFF);

  // ---- 4) Pump Control ----
  if (!pumpOn && soilValue >= SOIL_DRY) pumpOn = true;
  if (pumpOn && soilValue <= SOIL_WET) pumpOn = false;

  digitalWrite(RELAY_PUMP, pumpOn ? RELAY_ON : RELAY_OFF);

  // ---- 5) Alert System ----
  bool critical = (temperature >= 40.0) ||
                  (humidity >= 95.0) ||
                  (humidity <= 30.0);

  if (critical) {
    digitalWrite(LED_RED, HIGH);
    tone(BUZZER_PIN, 2000);
    delay(80);
    noTone(BUZZER_PIN);
  } else {
    digitalWrite(LED_RED, LOW);
  }

  // ---- 6) LCD Update ----
  if (now - lastDisplayUpdate >= DISPLAY_INTERVAL) {
    lastDisplayUpdate = now;
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperature, 1);
    lcd.print("C H:");
    lcd.print(humidity, 0);
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("S:");
    lcd.print(soilValue);

    lcd.setCursor(9, 1);
    lcd.print("F");
    lcd.print(fanOn ? "1" : "0");
    lcd.print("P");
    lcd.print(pumpOn ? "1" : "0");
    lcd.print("L");
    lcd.print(lightOn ? "1" : "0");
  }
}
