int pirPin = 5; // This is D1 on the MCU
int LED = 4; // This is D2 on the MCU
int brightness = 0;    // how bright the LED starts
int fadeAmount = 4;    // how many points to fade the LED by

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
        CallSmokin(130);
  }
  else {
        Serial.println("Motion is clear.");
        delay(1000);
        analogWrite(LED, 0);  // turn the LED off by making the voltage LOW  
        brightness = 0;
      }
}

void CallSmokin(int t){
for(int counter = 1;counter <= t;counter++) {
analogWrite(LED, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
  if ( brightness <0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  Serial.println(counter);
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
}
