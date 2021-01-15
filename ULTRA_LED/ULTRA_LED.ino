#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN     6
const int buzzer = 9; //buzzer to arduino pin 9
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  21
int y = 0;
// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50

const int pingPin = 7;
// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
long duration, inches, cm;

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  pinMode(buzzer, OUTPUT); 
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

     
   Serial.begin(9600);
}

void loop() {
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  
  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  /////////////////////////// MAPPING FOR SENSOR
   for(int i = 21; i > 21/2 + cm; i--) {

    strip.setPixelColor(i - 1, strip.Color(255,   0,   0));
    strip.setPixelColor(21 - i, strip.Color(255,   0,   0));
    //tone(buzzer, 1000);
    strip.show();
    //delay(1);
  }

  for(int i = 21; i > 21/2 - cm; i--) {
    strip.setPixelColor(21 - i+10, strip.Color(0,   0,   0)); 
    strip.setPixelColor((i - 12)+1, strip.Color(0,   0,   0));
    
    strip.show();
    //delay(1);
  }

    /*for(int i=0; i<21-cm; i++) { // For each pixel in strip...
    strip.setPixelColor(i, strip.Color(255,   0,   0));         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(1);                           //  Pause for a moment
  }

  for(int i=21; i>19-cm; i--) { // For each pixel in strip...
 
    strip.setPixelColor(i, strip.Color(0,   0,   0));         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    //delay(1);                           //  Pause for a moment
  }
  */
  // Fill along the length of the strip in various colors...
  //colorWipeBack(strip.Color(255,   0,   0)     , 50); // Red
  //colorWipeBack(strip.Color(0,   0,   0)     , 50); // black
  //colorWipe(strip.Color(255,   0,   0)     , 50); // Red
  //colorWipe(strip.Color(0,   0,   0)     , 50); // black
  //colorWipeIn(strip.Color(255, 0, 0), 200, 21);
  //colorWipeIn(strip.Color(0,   0,   0),200  , 21); // black
  //colorWipeIn(strip.Color(0, 0, 0), 200, 21);
  /*for(int i = 0; i < 10; i++)
  {
    //strip.fill(strip.Color(0,0,0), 0,strip.numPixels());
    ColorDistance(strip.Color(255, 0, 0), strip.numPixels(), i);
    delay(100);
  }*/
}


void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

/*
void colorWipeBack(uint32_t color, int wait) {
  for(int i=19; i>9; i--) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}*/

void colorWipeIn(uint32_t color, int wait, int strandSize)
{
  for(int i = strandSize; i > strandSize/2; i--) {
    strip.setPixelColor(i - 1, color);
    strip.setPixelColor(strandSize - i, color);
    strip.show();
    delay(wait);
  }
}

void ColorDistance(uint32_t color, int strandSize, int distance)
{
  
   strip.setPixelColor(distance - 1, color);
   strip.setPixelColor(strandSize - distance, color);
   strip.fill(strip.Color(255,0,0), 0,distance);
   strip.show();
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}


/*

*/
