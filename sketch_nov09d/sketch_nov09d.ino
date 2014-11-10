#include <Servo.h>

const int buttonPin = 2;    // the number of the pushbutton pin
const int stateLed = 13;    // the number of the LED pin
Servo s;                    // the servo to use

// Variables will change:
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

boolean forward;

void setup() {
  s.attach(7);
  pinMode(buttonPin, INPUT);
  pinMode(stateLed, OUTPUT);
  forward = true;
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
  int i;
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
 
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        if(forward==true){
          digitalWrite(stateLed, HIGH);
          for(i=LOW;i<256;++i) {s.write(i); delay(5);Serial.println(i);}
          forward=false;
        } else {
          digitalWrite(stateLed, LOW);
          for(;i>=LOW;--i) { 
              if(i == 0){
                s.write(LOW);
              } else {
                s.write(i);
            }z0
              delay(5);
              Serial.println(i);
            }
          forward=true;  
        }
      }
    }
  }


  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}
