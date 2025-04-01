const int RED_LEDS[] = {2, 3, 4, 5, 6, 7, 8, 12};
const int NUM_RED_LEDS = sizeof(RED_LEDS) / sizeof(RED_LEDS[0]);
const int MULTI_LED_GREEN = 9;
const int MULTI_LED_BLUE = 10;
const int MULTI_LED_RED = 11;

int currentLEDIndex = 0;
int direction = 1; // 1 for forward, -1 for backward

// Variables to store the current color of the multi-colored LED
int redValue = 255;
int greenValue = 0;
int blueValue = 0;

// PWM increment/decrement step
int pwmStep = 15;  // Increased for faster color changes

// Control the speed of color change
int colorChangeInterval = 1; // Reduced interval for more frequent changes
int colorChangeCounter = 0;

// Color cycle state
int colorState = 0; // 0: Red -> Green, 1: Green -> Blue, 2: Blue -> Red

void setup() {
  // Configure red LEDs as outputs
  for (int i = 0; i < NUM_RED_LEDS; i++) {
    pinMode(RED_LEDS[i], OUTPUT);
  }

  // Configure multi-colored LED pins as outputs
  pinMode(MULTI_LED_RED, OUTPUT);
  pinMode(MULTI_LED_GREEN, OUTPUT);
  pinMode(MULTI_LED_BLUE, OUTPUT);

  // Set initial state of multi-colored LED
  analogWrite(MULTI_LED_RED, redValue);
  analogWrite(MULTI_LED_GREEN, greenValue);
  analogWrite(MULTI_LED_BLUE, blueValue);

  randomSeed(analogRead(0)); // Seed the random number generator
}

void shiftColors() {
  colorChangeCounter++;
  if (colorChangeCounter >= colorChangeInterval) {
    colorChangeCounter = 0;

    // Transition to the next color
    if (colorState == 0) { // Red -> Green
      redValue -= pwmStep;
      greenValue += pwmStep;
      if (redValue <= 0) {
        redValue = 0;
        greenValue = 255;
        colorState = 1;
      }
    } else if (colorState == 1) { // Green -> Blue
      greenValue -= pwmStep;
      blueValue += pwmStep;
      if (greenValue <= 0) {
        greenValue = 0;
        blueValue = 255;
        colorState = 2;
      }
    } else if (colorState == 2) { // Blue -> Red
      blueValue -= pwmStep;
      redValue += pwmStep;
      if (blueValue <= 0) {
        blueValue = 0;
        redValue = 255;
        colorState = 0;
      }
    }

    // Keep values within bounds
    redValue = constrain(redValue, 0, 255);
    greenValue = constrain(greenValue, 0, 255);
    blueValue = constrain(blueValue, 0, 255);
  }

  // Write the color values to the LED
  analogWrite(MULTI_LED_RED, redValue);
  analogWrite(MULTI_LED_GREEN, greenValue);
  analogWrite(MULTI_LED_BLUE, blueValue);
}

void loop() {
  // Knight Rider effect
  digitalWrite(RED_LEDS[currentLEDIndex], HIGH);
  shiftColors(); // Shift colors when LED is turned on
  delay(50);
  digitalWrite(RED_LEDS[currentLEDIndex], LOW);
  shiftColors(); // Shift colors when LED is turned off

  currentLEDIndex += direction;

  if (currentLEDIndex >= NUM_RED_LEDS) {
    currentLEDIndex = NUM_RED_LEDS - 2;
    direction = -1;
  } else if (currentLEDIndex < 0) {
    currentLEDIndex = 1;
    direction = 1;
  }
}
