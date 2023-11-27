#include <Keyboard.h>

void setup() {
  Serial.begin(9600);
  delay(1000);
  Keyboard.begin();
  ledColor(0, 0, 64);
  Serial.println("JVS_BOOT_OK");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    processInput(input);
  }
}

void processInput(String input) {
  if (input == "TEST") {
    ledColor(255, 0, 0);
    Keyboard.press('1');
    Serial.println("JVS_TEST");
  } else if (input == "SERVICE") {
    ledColor(255, 0, 0);
    Keyboard.press('2');
    Serial.println("JVS_SERVICE");
  } else if (input == "CREDIT") {
    ledColor(0, 255, 0);
    Keyboard.press('3');
    Serial.println("JVS_COIN");
  } else if (input == "START") {
    ledColor(0, 0, 255);
    Keyboard.press('7');
    Serial.println("JVS_START");
  } else if (input == "CARD") {
    ledColor(0, 0, 255);
    Keyboard.press(KEY_RETURN);
    Serial.println("AIME_SCAN");
  } else {
    Serial.println("Invalid command");
  }
  delay(150);
  Keyboard.releaseAll();
  delay(500);
  ledColor(0, 0, 64);
}

void ledColor(int r, int g, int b) {
  analogWrite(18, map(r, 255, 0, 0, 255));
  analogWrite(19, map(g, 255, 0, 0, 255));
  analogWrite(20, map(b, 255, 0, 0, 255));
}