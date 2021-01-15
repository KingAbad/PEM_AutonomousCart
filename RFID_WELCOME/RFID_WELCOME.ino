/*******************************
 *   CODE BY: Abad Sethi       * 
 *                             *
 *  RFID reader with i2c LCD   *
 *                             *
 ******************************/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN     6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  26

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50


// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 

#define SS_PIN 10
#define RST_PIN 9

int groundPin = 6;

MFRC522 mfrc522;  

void setup() 
{
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  Serial.begin(9600);  
  SPI.begin();         
  mfrc522.PCD_Init();
  pinMode(groundPin, OUTPUT);
  digitalWrite(groundPin, LOW); 

 }
void loop() 
{  

  
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
  
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

 
  Serial.println("UID tag: ");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message: ");
  content.toUpperCase();
  if (content.substring(1) == "95 8A 0F 2B") 
  { 
      tone(4,5000,200);
      colorWipe(strip.Color(  0, 255,   0)     , 1); // Green
      strip.show();                          //  Update strip to match
      delay(500);
      colorWipe(strip.Color(  0, 0,   0)     , 1); // black
      delay(500);
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 255,   0)     , 5); // Green
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 0,   0)     , 5); // black
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 255,   0)     , 5); // Green
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 0,   0)     , 5); // black
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 255,   0)     , 5); // Green
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 0,   0)     , 5); // black
      strip.show();                          //  Update strip to match
  }
 
 else   {
      tone(4,250,1000);
      colorWipe(strip.Color(  255, 0,   0)     , 1); // Red
      strip.show();                          //  Update strip to match
      delay(500);
      colorWipe(strip.Color(  0, 0,   0)     , 1); // black
      delay(500);
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  255, 0,   0)     , 5); // Red
      tone(4,250,100);
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 0,   0)     , 5); // black
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  255, 0,   0)     , 5); // Red
      tone(4,250,100);
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 0,   0)     , 5); // black
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  255, 0,   0)     , 5); // Red
      tone(4,250,100);
      strip.show();                          //  Update strip to match
      colorWipe(strip.Color(  0, 0,   0)     , 5); // black
      strip.show();                          //  Update strip to match
  }
}


void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    delay(wait);                           //  Pause for a moment
  }
}

 
