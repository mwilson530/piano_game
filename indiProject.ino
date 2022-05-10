#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
const int LED_PIN = 13;
const int INTERRUPT_PIN = 2;
volatile bool ledState = LOW;
volatile int count = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(INTERRUPT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), ledInterrupt, FALLING); // trigger when button pressed, but not when released.
    lcd.begin(16, 2);
    Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_PIN, ledState);
}

void ledInterrupt() {
   ledState = !ledState;
   count = count + 1;
   Serial.print(count);
}
