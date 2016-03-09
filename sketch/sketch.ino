/*
  Interval
  Turns on relay for 15 sec in 3 min intervals
 */

// SETTINGS:
#define INTERVAL 600    // interval between switching
#define DURATION 20     // turn on for 15 seconds
int relayPin     = 13;  // Relay data pin
int relayOnState = LOW; // ON state for relay (LOW for most relay shields)

unsigned long intervalMs;  
unsigned long durationMs;   
unsigned long previousMs  = 0;
unsigned long currentMs   = 0;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, ((relayOnState == LOW) ? HIGH : LOW));  // initial relay state is OFF
  intervalMs = (unsigned long)INTERVAL * 1000L;
  durationMs = (unsigned long)DURATION * 1000L;
}

void loop() {
  currentMs = millis();
  
  if (currentMs - previousMs >= intervalMs) {
    digitalWrite(relayPin, relayOnState);
  }
  if(currentMs - previousMs >= (intervalMs + durationMs)) {
    previousMs = currentMs;
    digitalWrite(relayPin, ((relayOnState == LOW) ? HIGH : LOW));
  }
  
  delay(1);
}
