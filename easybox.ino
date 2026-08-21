
// v8
//  -- 
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// main loop()

    // [done] short press
        // [done] up main counter  --> back to main loop
                    
    // [done] long press
              
    // game (hit exact 10 seconds): 

        // [done] display countdown 3,2,1
        
        // [done] display timer
        
            // [done] long press
                // [done] exit game -> back to main 
                              
            // [done] short press

                // [done] pause the timer, restart timer
                
                    // show countdown, 3,2,1 on reset ?

                    // [done] on match exact 10 seconds

                        // make the display slowly blinking ?

                        // [done] -- degree the main counter..

                        // FUN FACT ? price for winning

                            // If the goal is to stop at the exact millisecond (10.000s): 
                            // The theoretical probability of hitting the exact millisecond is 1 in 1000 per second. 
                            // Due to human reaction time (around 250-300 milliseconds), 
                            // the window to hit a specific millisecond is extremely small, 
                            // making the odds of hitting the exact time in a single attempt very low 
                            // (around 0.36% or 1 in 276 attempts).

  //  EEPROM:
  //    [done] make it so the MAX_COUNTER can fit ( we should store the counter as a multi-byte value (e.g., 4 bytes for an unsigned int))
  
  //    shift 4 bytes after 100.000 clicks...
        // The maximum write cycles for EEPROM typically range from 100,000 to 1 million write/erase cycles, with 100,000 being a common specification for many microcontrollers. 

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <Adafruit_NeoPixel.h>
#include <TM1637TinyDisplay6.h>
#include <EEPROM.h>

// Pin definitions
#define NEOPIXEL_PIN 2
#define BUTTON_SW_PIN 3    // Interrupt pin (D3)
#define BUTTON_LED_PIN 4
#define TM1637_CLK_PIN 5
#define TM1637_DIO_PIN 6

// Constants
#define NEOPIXEL_COUNT 1
#define DEBOUNCE_DELAY 50        // milliseconds
#define LONG_PRESS_THRESHOLD 1000 // milliseconds
#define COUNTDOWN_START 3        // seconds
#define MAX_COUNTER 999999       // max display value

// Globals
Adafruit_NeoPixel ledStrip(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
TM1637TinyDisplay6 display(TM1637_CLK_PIN, TM1637_DIO_PIN);
uint8_t displayBrightness = 0; // default brightness (0-15)

// Main counter variable
unsigned int counter = 0;

// Button state variables
volatile bool buttonReleasedFlag = false;
volatile unsigned long buttonPressStartTime = 0;
volatile unsigned long buttonPressEndTime = 0;
volatile bool longPressDetected = false;

// For debouncing
unsigned long lastDebounceTime = 0;

// Button event enumeration
enum ButtonEvent {
  BtnIDLE,
  BtnSHORT_PRESS,
  BtnLONG_PRESS
};
ButtonEvent buttonEvent = BtnIDLE;

// Timer states
enum TimerStates {
  TimerIDLE,
  TimerCOUNTDOWN,
  TimerRUNNING,
  TimerSTOPPED
};
TimerStates timerState = TimerIDLE;

// Timer variables
unsigned long countdownStartTime = 0;
unsigned long timerStartMicros = 0; // high-res start time
unsigned long elapsedMicros = 0;

// Flags
bool inLongPressMode = false;        // Set true once countdown starts
bool timerPaused = false;            // Paused state
unsigned long pausedMicros = 0;       // Store elapsed micros when paused

// EEPROM address for counter (using 4 bytes for unsigned int)
const int EEPROM_ADDR = 0; // starting address

// Forward declaration
void handleButtonInterrupt();

void writeCounterToEEPROM(unsigned int value) {
  // Store 2 bytes (since max is 999999, 4 bytes needed)
  EEPROM.put(EEPROM_ADDR, value);
}

unsigned int readCounterFromEEPROM() {
  unsigned int value = 0;
  EEPROM.get(EEPROM_ADDR, value);
  if (value > MAX_COUNTER) {
    value = 0; // Reset if out of bounds
  }
  return value;
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting setup...");
  Serial.println("EasyBox v0.8 loaded --> https://github.com/KunstGraveren/easybox");
  Serial.println("powered by: kunstgraveren.nl");
  
  // Initialize NeoPixel
  ledStrip.begin();
  ledStrip.show(); // off
  ledStrip.setBrightness(50);

  // Initialize display
  display.setBrightness(displayBrightness);
  display.clear();

  // Read counter from EEPROM
  counter = readCounterFromEEPROM();

  // Show initial counter
  display.showNumberDec(counter);

  // Button pin setup
  pinMode(BUTTON_SW_PIN, INPUT_PULLUP);
  pinMode(BUTTON_LED_PIN, OUTPUT);
  digitalWrite(BUTTON_LED_PIN, LOW);

  attachInterrupt(digitalPinToInterrupt(BUTTON_SW_PIN), handleButtonInterrupt, CHANGE);
}

void loop() {
  unsigned long now = millis();

  // Detect long press automatically
  if (digitalRead(BUTTON_SW_PIN) == LOW && !longPressDetected) {
    unsigned long heldDuration = now - buttonPressStartTime;
    if (heldDuration >= LONG_PRESS_THRESHOLD) {
      buttonEvent = BtnLONG_PRESS;
      longPressDetected = true;
    }
  }

  // Handle button release
  if (buttonReleasedFlag) {
    noInterrupts();
    unsigned long duration = buttonPressEndTime - buttonPressStartTime;
    buttonReleasedFlag = false;
    if (duration >= LONG_PRESS_THRESHOLD) {
      // Long press already handled
    } else if (duration >= DEBOUNCE_DELAY) {
      buttonEvent = BtnSHORT_PRESS;
    }
    longPressDetected = false;
    interrupts();
  }

  // Process button events
  if (buttonEvent != BtnIDLE) {
    switch (buttonEvent) {
      case BtnSHORT_PRESS:
        Serial.println("Handling short press...");
      
        if (inLongPressMode) {
          // During long press mode, short press does nothing
        } else {
          // Not in long press mode, increment counter
          digitalWrite(BUTTON_LED_PIN, !digitalRead(BUTTON_LED_PIN));
          // NeoPixel color
                                  //R, G, B
          ledStrip.setPixelColor(0, 0, 0, 255); // Blue
          ledStrip.show();
          if (counter < MAX_COUNTER) counter++;
          else counter = 0;
          writeCounterToEEPROM(counter);
          display.clear();
          display.showNumberDec(counter);
        }
        break;

      case BtnLONG_PRESS:

        Serial.println("Handling long press...");
        // Example action: change NeoPixel color
        ledStrip.setPixelColor(0, 0, 255, 0); // Green
        ledStrip.show();
      
        if (!inLongPressMode) {
          // Start countdown
  
          display.showString("HIT 10 Seconds");
          delay(500);
      
          inLongPressMode = true;
          timerState = TimerCOUNTDOWN;
          countdownStartTime = millis();
        } else {
          // Exit long press mode
          inLongPressMode = false;
          timerState = TimerIDLE;
          // Display main counter again
          display.clear();
          display.showNumberDec(counter);
        }
        break;

      default:
        break;
    }
    buttonEvent = BtnIDLE;
  }

  // Timer logic
  switch (timerState) {
    case TimerCOUNTDOWN: {
      unsigned long elapsedSeconds = (millis() - countdownStartTime) / 1000;
      int count = COUNTDOWN_START - elapsedSeconds;      
      if (count >= 0) {
        display.showNumberDec(count);
      } else {
        // countdown finished, start timer
        timerState = TimerRUNNING;
        timerStartMicros = micros();
      }
      break;
    }
    case TimerRUNNING: {
      unsigned long currentMicros = micros();
      unsigned long totalElapsed = currentMicros - timerStartMicros;
      unsigned long totalSeconds = totalElapsed / 1000000;
      unsigned long milliseconds = (totalElapsed % 1000000) / 1000;
      unsigned long minutes = totalSeconds / 60;
      unsigned long seconds = totalSeconds % 60;

      float timeFloat = minutes * 60.0 + seconds + (milliseconds / 1000.0);
      display.showNumber(timeFloat);

      // During timer running, check for button press to toggle pause/resume
      if (digitalRead(BUTTON_SW_PIN) == LOW && !longPressDetected) {
        // Handled in interrupt
      }
      break;
    }
    case TimerSTOPPED: {
      unsigned long totalElapsed;
      if (timerPaused) {
        totalElapsed = elapsedMicros;
      } else {
        totalElapsed = micros() - timerStartMicros;
      }

      // Convert totalElapsed to seconds with fractional part
      float totalSeconds = totalElapsed / 1000000.0;

      // Check if the paused time matches exactly 10.000 seconds
      if (abs(totalSeconds - 10.000) < 0.001) {
        // Matched 10.000 seconds
        Serial.println("Paused time is exactly 10.000 seconds!");

        // Decrement counter
        if (counter > 1) counter--;
        else counter = 0;
        writeCounterToEEPROM(counter);
        display.clear();
        display.showNumberDec(counter);
      } 

      //// DEBUG:
      //  else {
      //  Serial.println("Paused time is NO MATCH!");
      //  Serial.println(totalSeconds);
      //  Serial.println(abs(totalSeconds - 10.000));
      // }

      unsigned long secondsPart = (unsigned long)totalSeconds;
      unsigned long millisecondsPart = (totalElapsed % 1000000) / 1000;
      unsigned long minutes = secondsPart / 60;
      unsigned long seconds = secondsPart % 60;

      float timeFloat = minutes * 60.0 + seconds + (millisecondsPart / 1000.0);
      display.showNumber(timeFloat);
      break;
    }
    default:
      break;
  }

  delay(50);
}

void handleButtonInterrupt() {
  static bool lastState = HIGH;
  bool currentState = digitalRead(BUTTON_SW_PIN);
  unsigned long now = millis();

  if (currentState != lastState) {
    if (now - lastDebounceTime > DEBOUNCE_DELAY) {
      lastDebounceTime = now;
      if (currentState == LOW) {
        // Button pressed down
        buttonPressStartTime = now;
        longPressDetected = false;

        // During long press mode, toggle pause/resume immediately on press
        if (inLongPressMode) {
          if (timerState == TimerRUNNING) {
            // pause
            timerState = TimerSTOPPED;
            timerPaused = true;
            unsigned long nowMicros = micros();
            elapsedMicros = nowMicros - timerStartMicros;
          } else if (timerState == TimerSTOPPED) {
            // resume
            timerState = TimerRUNNING;
            // When resuming from pause, reset start time to now
            timerStartMicros = micros();
            timerPaused = false;
          }
        }
      } else {
        // Button released
        buttonPressEndTime = now;
        buttonReleasedFlag = true;
        if (buttonPressEndTime - buttonPressStartTime >= LONG_PRESS_THRESHOLD) {
          longPressDetected = true;
        }
      }
    }
  }
  lastState = currentState;
}
