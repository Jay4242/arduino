/*     ---------------------------------------------------------
 *     |  Arduino Experimentation Kit Example Code             |
 *     |  CIRC-02 .: 8 LED Fun :. (Multiple LEDs)   |
 *     |  CIRC-02 .: 8 LED Fun :. (Multiple LEDs)   |
 *     ---------------------------------------------------------
 *
 *  A few Simple LED animations
 *
 * For more information on this circuit http://tinyurl.com/d2hrud
 *
 */

//LED Pin Variables
int ledPins[] = {2,3,4,5,6,7,8,9}; //An array to hold the pin each LED is connected to
                                   //i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
                                   //to address an array use ledPins[0] this would equal 2
                                   //and ledPins[7] would equal 9
const int redLEDs[] = {2,4,6,8};   // Array to hold the pins connected to the red LEDs
const int greenLEDs[] = {3,5,7,9}; // Array to hold the pins connected to the green LEDs

/*
 * setup() - this function runs once when you turn your Arduino on
 * We the three control pins to outputs
 */
void setup()
{

  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 8; i++){         //this is a loop and will repeat eight times
      pinMode(ledPins[i],OUTPUT); //we use this to set each LED pin to output
  }                                   //the code this replaces is below
}


/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called oneAfterAnother(). if you would like a different behaviour
 * uncomment (delete the two slashes) one of the other lines
 */
void loop()                     // run over and over again
{
  knightRiderRGB();
}

/*
 * matrixMadness() - Rapidly switches LEDs on and off in a seemingly random pattern to push the Arduino's limits.
 */
void redGreenCodeDance() {
  // Green LEDs flash random pattern
  for (int i = 0; i < 4; i++) {
    int numberOfFlashes = random(50) + 1; // Random number of flashes (1-50)
    for (int j = 0; j < numberOfFlashes; j++) {
      int delayTime = random(200) + 100; // Random delay time between 100-300 ms

      // Ensure the LED is off before potentially turning it on
      digitalWrite(greenLEDs[i], LOW);

      int action = random(4);           // 0: HIGH, 1: No change, 2: No change,  3: HIGH
      if (action == 0 || action == 3) {
        digitalWrite(greenLEDs[i], HIGH);
      }
      if (random(10) < 9) {           // 90% chance of delay
        delay(delayTime);
      }
    }
    digitalWrite(greenLEDs[i], LOW); // Ensure it's off after the sequence
  }
  delay(random(300) + 100); // Pause between green and red (100-400ms)

  // Red LEDs flash random pattern
  for (int i = 0; i < 4; i++) {
    int numberOfFlashes = random(50) + 1; // Random number of flashes (1-50)
    for (int j = 0; j < numberOfFlashes; j++) {
      int delayTime = random(200) + 100; // Random delay time between 100-300 ms

      // Ensure the LED is off before potentially turning it on
      digitalWrite(redLEDs[i], LOW);

      int action = random(4);           // 0: HIGH, 1: No change, 2: No change,  3: HIGH
      if (action == 0 || action == 3) {
        digitalWrite(redLEDs[i], HIGH);
      }
      if (random(10) < 9) {           // 90% chance of delay
        delay(delayTime);
      }
    }
    digitalWrite(redLEDs[i], LOW);   // Ensure it's off after the sequence
  }
  delay(random(300) + 100); // Pause after red (100-400ms)
}

/*
 * matrixMadness() - Rapidly switches LEDs on and off in a seemingly random pattern to push the Arduino's limits.
 */
void matrixMadness() {
  int duration = random(50) + 50; // Reduced duration
  int baseDelay = 10; // Base delay for fading
  int ledBrightness[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // Store brightness of each LED

  for (int i = 0; i < duration; i++) {
    for (int j = 0; j < 8; j++) {
      if (random(10) < 3) { // Reduced frequency of changes
        int fadeAmount = random(10) + 5; // Random fade amount
        delay(random(50)); // Stochastic pause before fading in

        // Fade LED in
        for (int brightness = ledBrightness[j]; brightness <= 255; brightness += fadeAmount) {
          analogWrite(ledPins[j], brightness);
          ledBrightness[j] = brightness; // Update stored brightness
          delay(baseDelay);
        }
        analogWrite(ledPins[j], 255); // Ensure fully on
        ledBrightness[j] = 255;
      } else {
        int fadeAmount = random(10) + 5; // Random fade amount
        delay(random(50)); // Stochastic pause before fading out

        // Fade LED out
        for (int brightness = ledBrightness[j]; brightness >= 0; brightness -= fadeAmount) {
          analogWrite(ledPins[j], brightness);
          ledBrightness[j] = brightness; // Update stored brightness
          delay(baseDelay);
        }
        analogWrite(ledPins[j], 0); // Ensure fully off
        ledBrightness[j] = 0;
      }
    }
    delay(20); // Small delay between frames
  }
}

/*
 * oneAfterAnotherNoLoop() - Will light one LED then delay for delayTime then light
 * the next LED until all LEDs are on it will then turn them off one after another
 *
 * this does it without using a loop which makes for a lot of typing.
 * oneOnAtATimeLoop() does exactly the same thing with less typing
 */
void oneAfterAnotherNoLoop(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower
  digitalWrite(ledPins[0], HIGH);  //Turns on LED #0 (connected to pin 2 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[1], HIGH);  //Turns on LED #1 (connected to pin 3 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[2], HIGH);  //Turns on LED #2 (connected to pin 4 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[3], HIGH);  //Turns on LED #3 (connected to pin 5 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[4], HIGH);  //Turns on LED #4 (connected to pin 6 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[5], HIGH);  //Turns on LED #5 (connected to pin 7 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[6], HIGH);  //Turns on LED #6 (connected to pin 8 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[7], HIGH);  //Turns on LED #7 (connected to pin 9 )
  delay(delayTime);                //waits delayTime milliseconds

//Turns Each LED Off
  digitalWrite(ledPins[7], LOW);  //Turns on LED #0 (connected to pin 2 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[6], LOW);  //Turns on LED #1 (connected to pin 3 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[5], LOW);  //Turns on LED #2 (connected to pin 4 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[4], LOW);  //Turns on LED #3 (connected to pin 5 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[3], LOW);  //Turns on LED #4 (connected to pin 6 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[2], LOW);  //Turns on LED #5 (connected to pin 7 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[1], LOW);  //Turns on LED #6 (connected to pin 8 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[0], LOW);  //Turns on LED #7 (connected to pin 9 )
  delay(delayTime);                //waits delayTime milliseconds
}

/*
 * oneAfterAnotherLoop() - Will light one LED then delay for delayTime then light
 * the next LED until all LEDs are on it will then turn them off one after another
 *
 * this does it using a loop which makes for a lot less typing.
 * than oneOnAtATimeNoLoop() does exactly the same thing with less typing
 */
void oneAfterAnotherLoop(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower

//Turn Each LED on one after another
  for(int i = 0; i <= 7; i++){
    digitalWrite(ledPins[i], HIGH);  //Turns on LED #i each time this runs i
    delay(delayTime);                //gets one added to it so this will repeat
  }                                  //8 times the first time i will = 0 the final
                                     //time i will equal 7;

//Turn Each LED off one after another
  for(int i = 7; i >= 0; i--){  //same as above but rather than starting at 0 and counting u
                    //p
                                //we start at seven and count down
    digitalWrite(ledPins[i], LOW);  //Turns off LED #i each time this runs i
    delay(delayTime);                //gets one subtracted from it so this will repeat
  }                                  //8 times the first time i will = 7 the final
                                     //time it will equal 0


}

/*
 * oneOnAtATime() - Will light one LED then the next turning off all the others
 */
void oneOnAtATime(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower

  for(int i = 0; i <= 7; i++){
    int offLED = i - 1;  //Calculate which LED was turned on last time through
    if(i == 0) {         //for i = 1 to 7 this is i minus 1 (i.e. if i = 2 we will
      offLED = 7;        //turn on LED 2 and off LED 1)
    }                    //however if i = 0 we don't want to turn of led -1 (doesn't exist)
                         //instead we turn off LED 7, (looping around)
    digitalWrite(ledPins[i], HIGH);     //turn on LED #i
    digitalWrite(ledPins[offLED], LOW); //turn off the LED we turned on last time
    delay(delayTime);
  }
}

/*
 * inAndOut() - This will turn on the two middle LEDs then the next two out
 * making an in and out look
 */
void inAndOut(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
                       //make smaller for quicker switching and larger for slower

  //runs the LEDs out from the middle
  for(int i = 0; i <= 3; i++){
    int offLED = i - 1;  //Calculate which LED was turned on last time through
    if(i == 0) {         //for i = 1 to 7 this is i minus 1 (i.e. if i = 2 we will
      offLED = 3;        //turn on LED 2 and off LED 1)
    }                    //however if i = 0 we don't want to turn of led -1 (doesn't exist)
                         //instead we turn off LED 7, (looping around)
    int onLED1 = 3 - i;       //this is the first LED to go on ie. LED #3 when i = 0 and LED
                    //
                             //#0 when i = 3
    int onLED2 = 4 + i;       //this is the first LED to go on ie. LED #4 when i = 0 and LED
                    //
                             //#7 when i = 3
    int offLED1 = 3 - offLED; //turns off the LED we turned on last time
    int offLED2 = 4 + offLED; //turns off the LED we turned on last time

    digitalWrite(ledPins[onLED1], HIGH);
    digitalWrite(ledPins[onLED2], HIGH);
    digitalWrite(ledPins[offLED1], LOW);
    digitalWrite(ledPins[offLED2], LOW);
    delay(delayTime);
  }

  //runs the LEDs into the middle
  for(int i = 3; i >= 0; i--){
    int offLED = i + 1;  //Calculate which LED was turned on last time through
    if(i == 3) {         //for i = 1 to 7 this is i minus 1 (i.e. if i = 2 we will
      offLED = 0;        //turn on LED 2 and off LED 1)
    }                    //however if i = 0 we don't want to turn of led -1 (doesn't exist)
                         //instead we turn off LED 7, (looping around)
    int onLED1 = 3 - i;       //this is the first LED to go on ie. LED #3 when i = 0 and LED
                    //
                             //#0 when i = 3
    int onLED2 = 4 + i;       //this is the first LED to go on ie. LED #4 when i = 0 and LED
                    //
                             //#7 when i = 3
    int offLED1 = 3 - offLED; //turns off the LED we turned on last time
    int offLED2 = 4 + offLED; //turns off the LED we turned on last time

    digitalWrite(ledPins[onLED1], HIGH);
    digitalWrite(ledPins[onLED2], HIGH);
    digitalWrite(ledPins[offLED1], LOW);
    digitalWrite(ledPins[offLED2], LOW);
    delay(delayTime);
  }
}

/*
 * knightRider() - A single LED moves back and forth
 */
void knightRider() {
  int delayTime = 50;
  static int position = 0;
  static int direction = 1;  // 1 for forward, -1 for backward

  // Turn off all LEDs
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  // Turn on the LED at the current position
  digitalWrite(ledPins[position], HIGH);
  delay(delayTime);

  // Update the position
  position += direction;

  // Reverse direction if we reach the end
  if (position == 7 || position == 0) {
    direction = -direction;
  }
}

/*
 * randomFlicker() - Randomly turns LEDs on and off
 */
void randomFlicker() {
  for (int i = 0; i < 8; i++) {
    if (random(2) == 0) {  // 50% chance
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
  delay(50);
}

/*
 * randomWalk() - Each LED has a random chance of turning on or off
 */
void randomWalk() {
  for (int i = 0; i < 8; i++) {
    if (random(10) < 5) {  // 50% chance
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
  delay(50);
}

/*
 * redAndGreenDance() - Alternates between lighting up the red and green LEDs
 */
void redAndGreenDance() {
  int delayTime = 100;

  for (int i = 0; i < 4; i++) {
    int danceSteps = random(3) + 2; // Random number of steps between 2 and 4
    for (int j = 0; j < danceSteps; j++) {
      digitalWrite(redLEDs[i], HIGH);
      delay(delayTime);
      digitalWrite(redLEDs[i], LOW);
      digitalWrite(greenLEDs[i], HIGH);
      delay(delayTime);
      digitalWrite(greenLEDs[i], LOW);
    }
  }
}

/*
 * wildRedGreenSpectacle() - Creates a visually stunning spectacle using red and green LEDs
 */
void wildRedGreenSpectacle() {
  int delayTime = 100; // Faster delay for a more intense effect

  for (int i = 0; i < 20; i++) { // Run the spectacle for a duration

    // Randomly choose LEDs to turn on/off
    for (int j = 0; j < 4; j++) {
      if (random(10) < 3) {
        digitalWrite(redLEDs[j], HIGH);
      } else {
        digitalWrite(redLEDs[j], LOW);
      }

      if (random(10) < 3) {
        digitalWrite(greenLEDs[j], HIGH);
      } else {
        digitalWrite(greenLEDs[j], LOW);
      }
    }

    delay(delayTime); // Short delay to create rapid changes

    // Clear all LEDs for a brief moment
    for (int j = 0; j < 4; j++) {
      digitalWrite(redLEDs[j], LOW);
      digitalWrite(greenLEDs[j], LOW);
    }
    delay(random(delayTime)); // Even shorter, random delay
  }
}

/*
 * oldSchoolMainframe() - Simulates an old-school computer mainframe with blinking lights
 */
void oldSchoolMainframe() {
  int delayTime = 200;

  for (int i = 0; i < 8; i++) {
    // More likely to turn on green LEDs
    if (i % 2 != 0) { // Green LEDs
      if (random(10) < 3) { // 30% chance to turn on
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    } else { // Red LEDs
      if (random(10) < 2) { // 20% chance to turn on
      // The expression random(10) < x means there is x/10 chance of the LED turning on
        digitalWrite(ledPins[i], HIGH);
      } else {
        digitalWrite(ledPins[i], LOW);
      }
    }
  }
  delay(delayTime);
}

/*
 * knightRiderRGB() - A single LED moves back and forth, alternating between green and red LEDs
 */
void knightRiderRGB() {
  for(int i = 0; i < 8; i++){
    knightRiderColor(greenLEDs);
  }
  // Turn off all green LEDs
  for (int i = 0; i < 4; i++) {
    digitalWrite(greenLEDs[i], LOW);
  }
  for(int i = 0; i < 8; i++){
    knightRiderColor(redLEDs);
  }
  // Turn off all red LEDs
  for (int i = 0; i < 4; i++) {
    digitalWrite(redLEDs[i], LOW);
  }
}

/*
 * knightRiderColor() - A single LED moves back and forth for a given color
 */
void knightRiderColor(const int leds[]) {
  int delayTime = 100;
  static int position = 0;
  static int direction = 1;  // 1 for forward, -1 for backward

  // Turn off all LEDs
  for (int i = 0; i < 4; i++) {
    digitalWrite(leds[i], LOW);
  }

  // Turn on the LED at the current position
  digitalWrite(leds[position], HIGH);
  delay(delayTime);

  // Turn off the LED at the current position
  digitalWrite(leds[position], LOW);

  // Update the position
  position += direction;

  // Reverse direction if we reach the end
  if (position == 3 || position == 0) {
    direction = -direction;
  }

  // Turn on the LED at the current position
  digitalWrite(leds[position], HIGH);
}

/*
 * larsonScanner() - Creates a Larson Scanner effect (like Knight Rider, but smoother)
 */
void larsonScanner() {
  int delayTime = 20; // Adjust for speed
  static int position = 0;
  static int direction = 1;
  int fadeAmount = 30; // Adjust for fade speed

  // Dim all LEDs
  for (int i = 0; i < 8; i++) {
    analogWrite(ledPins[i], 0); // Set all LEDs to off initially
  }

  // Move the lit LED
  position += direction;
  if (position >= 7) {
    position = 6;
    direction = -1;
  } else if (position <= 0) {
    position = 1;
    direction = 1;
  }

  // Light the current LED with a fading effect
  int brightness = 255; // Full brightness
  analogWrite(ledPins[position], brightness);

  // Fade adjacent LEDs
  if (position > 0) {
    analogWrite(ledPins[position - 1], brightness - fadeAmount);
  }
  if (position < 7) {
    analogWrite(ledPins[position + 1], brightness - fadeAmount);
  }

  delay(delayTime);
}
