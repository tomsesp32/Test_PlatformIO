#include <Arduino.h>

static constexpr uint8_t LED_PIN = 10;          // matches your YAML: pin: 10
static constexpr uint32_t PERIOD_MS = 500;     // matches your YAML: interval: 2.5s

// Some ESP32-C3 boards wire the LED "active-low" (LED turns on when pin is LOW).
// If yours is active-low, set this to true.
static constexpr bool ACTIVE_LOW = false;

static bool ledState = false;                  // logical "ON/OFF" state
static uint32_t lastToggleMs = 0;

static void writeLed(bool on) {
  if (ACTIVE_LOW) {
    digitalWrite(LED_PIN, on ? LOW : HIGH);
  } else {
    digitalWrite(LED_PIN, on ? HIGH : LOW);
  }
}

void setup() {

  pinMode(LED_PIN, OUTPUT);

  // Start in OFF state (same idea as ESPHome "switch" default unless you set restore_mode).
  ledState = false;
  writeLed(ledState);

  // Optional: serial for debugging
  Serial.begin(115200);
  delay(500);
  Serial.println("Boot OK: serial smoke test");
}

void loop() {
  const uint32_t now = millis();
  if (now - lastToggleMs >= PERIOD_MS) {
    lastToggleMs = now;
    ledState = !ledState;   // toggle (switch.toggle)
    writeLed(ledState);

    Serial.printf("Toggled: %s\n", ledState ? "ON" : "OFF");
  }
}