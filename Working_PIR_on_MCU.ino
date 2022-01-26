int pirPin = 5; // This is D1 on the MCU
int LED = 4; // This is D2 on the MCU
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.begin(115200);

}

void loop() {
  int  motionState = digitalRead(pirPin);
  if (motionState == 1) {
        Serial.println("Motion is detected.  Beginning fade loop.");
        analogWrite(LED, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  }
  else {
        Serial.println("Motion is clear.");
        //digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW  
      }
}
