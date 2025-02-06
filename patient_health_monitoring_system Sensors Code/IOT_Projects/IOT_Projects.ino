#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <Ubidots.h>
#include "MAX30100_PulseOximeter.h"
#include <OneWire.h>
#include <DallasTemperature.h>

// WiFi credentials
const char* ssid = "syedmaazsaeed";
const char* password = "11000000";

// Ubidots credentials
const char* TOKEN = "BBUS-S0RqfZyU0YYsamLvwsb3oErnw3m948";
Ubidots ubidots(TOKEN);

// Pins and Objects
#define BLUE_LED 16
#define GREEN_LED 13
#define RED_LED 15
#define BUZZER  16
#define ONE_WIRE_BUS 2
#define ECG_PIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
PulseOximeter pox;

// Timing
unsigned long lastSendTime = 0;
const unsigned long sendInterval = 16000;
const unsigned long lcdUpdateInterval = 1000;
unsigned long lastLcdUpdate = 0;

// Variables
float temperature;
float heartRate;
float spo2;
int ecgValue;

// Function to handle abnormal values
void handleAbnormal() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BUZZER, HIGH);
}

// Function to handle normal values
void handleNormal() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BUZZER, LOW);
}

// WiFi connection check
void checkWiFi() {
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(BLUE_LED, HIGH);
  } else {
    digitalWrite(BLUE_LED, LOW);
  }
}

// Callback for MAX30100
void onBeatDetected() {
  Serial.println("Beat detected!");
}

void setup() {
  // Initialize serial and peripherals
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);

  // Show WiFi connecting message on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Connecting to   ");
  lcd.setCursor(0, 1);
  lcd.print("      WiFi        ");    

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  // Clear LCD and show connection success
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  delay(2000);
  lcd.clear();

  // Initialize sensors
  sensors.begin();
  pox.begin();
  //pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
  // Update WiFi status
  checkWiFi();

  // Read MAX30100 heart rate and SpO2
  pox.update();

  // Read DS18B20 temperature sensor
  sensors.setWaitForConversion(true);
  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);
  sensors.setWaitForConversion(false);

  heartRate = pox.getHeartRate();
  spo2 = pox.getSpO2();

  // Read ECG sensor
  ecgValue = analogRead(ECG_PIN);

  // Determine LED and buzzer states
  if (temperature > 40.1 || temperature < 35.2 || heartRate < 60 || heartRate > 100 || spo2 < 93) {
    handleAbnormal();
  } else {
    handleNormal();
  }

  // Update LCD periodically
  if (millis() - lastLcdUpdate >= lcdUpdateInterval) {

    lastLcdUpdate = millis();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(temperature, 1);
    lcd.print(" S:");
    lcd.print(spo2, 0);
    lcd.print("%");        
    lcd.setCursor(0, 1);
    lcd.print("H:");
    lcd.print(heartRate, 1);
    lcd.print(" EC:");
    lcd.print(ecgValue);
  }

  // Send data to Ubidots periodically
  if (millis() - lastSendTime >= sendInterval && WiFi.status() == WL_CONNECTED) {
    lastSendTime = millis();
    ubidots.add("temperature", temperature);
    ubidots.add("heart_rate", heartRate);
    ubidots.add("spo2", spo2);
    ubidots.add("ecg", ecgValue);
    ubidots.send("Data");
    // Initialize sensors
    sensors.begin();
    pox.begin();
    //pox.setOnBeatDetectedCallback(onBeatDetected);
  }
}