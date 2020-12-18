#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define pulseTimeout 50000 //50.000µs of 50ms

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN     6
//const int buzzer = 9; //buzzer to arduino pin 9
// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  21
int y = 0;
// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 25

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
long duration, inches, cm;

#define amountSensors 4
double sensorArray[amountSensors]; 

uint8_t sensorcount = 0; //do not touch

void setup() {
  // put your setup code here, to run once:
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)

  //Setup of ultrasonic, first two are front, last two are rear
  //setup of pulse pins, 2 3 4 and 5
  for(int i = 2; i <= 2 + amountSensors; i++){
      pinMode(i, INPUT);
  }
  //setup of echo pins, 7, 8, 9 and 10
  for(int j = 7; j <= 7 + amountSensors; j++){
      pinMode(j, OUTPUT);
  }

     
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Throughput of sensors is increased by doing one scan per cycle and updating the led strip more frequently
  if (sensorcount == 0)
  {
    sensorcount++;
    for (int k = 0; k < amountSensors - 2; k++){
      sensorArray[k] = GetDistance(7+k, 2+k);
    }
  }
  else
  {
    sensorcount = 0;
    for (int k = 2; k < amountSensors; k++){
      sensorArray[k] = GetDistance(7+k, 2+k);
    }
  }

  
}

void DistanceFade(uint8_t dir, uint8_t leds, int startpos)
{
  
}

double GetDistance(int trigpin, int echopin){
  long duration;
  double distance;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH, pulseTimeout); //pulsetimeout good enough for around 5 meters or so
  distance = (duration/2)/29.1;
  return distance;
}
