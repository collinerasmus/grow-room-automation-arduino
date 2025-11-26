#include <DHT.h>

// Pin Definitions (customised)
#define PIR_PIN 13           // PIR sensor digital pin
#define DHT_PIN 12           // DHT11 signal pin
#define DHT_TYPE DHT11
#define SOUND_PIN A0         // Analog pin for sound sensor

DHT dht(DHT_PIN, DHT_TYPE);

// State
bool lastMotion = false;

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(SOUND_PIN, INPUT);
  dht.begin();
  Serial.println("Grow Room Automation Started");
}

void loop() {
  // Read sensors
  bool motion = digitalRead(PIR_PIN);  
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  
  // Motion detected: Light action + Sound event
  if (motion && !lastMotion) {
    Serial.println("MOTION DETECTED");
    // (For Home Assistant): Send a marker over Serial, picked up by HA automation/mqtt
    Serial.println("ACTION:LIGHT_ON");
    // Record sound level (simple implementation - can expand to actual recording/shield)
    int soundVal = analogRead(SOUND_PIN);
    Serial.print("Sound level (on motion): ");
    Serial.println(soundVal);
    // Optionally, trigger further actions/logging here
  }
  lastMotion = motion;

  // Output temp/humidity every 5s
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 5000) {
    lastUpdate = millis();
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" °C, Humidity: ");
    Serial.print(hum);
    Serial.println(" %");
  }
  
  delay(100); // Debounce/polling
}