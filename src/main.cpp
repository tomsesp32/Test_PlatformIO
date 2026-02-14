#include <Arduino.h>

static constexpr uint8_t BLINK_PIN = 10;
static constexpr uint32_t ON_TIME_MS = 1000;
static constexpr uint32_t OFF_TIME_MS = 1000;
static constexpr uint32_t WAIT_BETWEEN_CYCLES_MS = 3000;
static constexpr uint8_t BLINK_COUNT = 3;

void setup() {
  pinMode(BLINK_PIN, OUTPUT);
  Serial.begin(115200);
  delay(2000);
  Serial.println("=== BOOT ===");
}

void loop() {
  for (uint8_t i = 0; i < BLINK_COUNT; ++i) {
    Serial.printf("Blink %u ON\n", i + 1);
    digitalWrite(BLINK_PIN, HIGH);
    delay(ON_TIME_MS);

    Serial.printf("Blink %u OFF\n", i + 1);
    digitalWrite(BLINK_PIN, LOW);
    delay(OFF_TIME_MS);
  }
  Serial.println("Loop start");
  Serial.flush();
  Serial.println("Waiting 3 seconds before repeating...");
  delay(WAIT_BETWEEN_CYCLES_MS);
}
