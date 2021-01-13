/*******************************
 *   CODE BY: Abad Sethi       * 
 *                             *
 *  RFID reader with i2c LCD   *
 *                             *
 ******************************/

#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
int redPin = 3;
int greenPin = 4;
int bluePin = 5;
int groundPin = 6;

MFRC522 mfrc522;  

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() 
{
  Serial.begin(9600);  
  SPI.begin();         
  mfrc522.PCD_Init();
  pinMode(groundPin, OUTPUT);
  digitalWrite(groundPin, LOW); 
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();

 }
void loop() 
{  
  lcd.clear();
  lcd.print("READ YOUR CARD");
  delay(1000);
  lcd.clear();
  delay(500);
  
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
  
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  lcd.clear();
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
    lcd.clear();
    tone(9,4500,150);
    lcd.print("Verified user");
    digitalWrite(greenPin, HIGH);
    delay(2000);
    lcd.clear();
    lcd.print("Access granted");
    delay(2000);
    lcd.clear();
    lcd.print("Welcome:");
    lcd.setCursor(0,1);
    lcd.print("Abad Sethi");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Buggy starts in...");
    delay(1000); 
    lcd.setCursor(0,1);
    lcd.print("3..");
    delay(1000); 
    lcd.setCursor(3,1);
    lcd.print("2..");
    delay(1000);
    lcd.setCursor(6,1);
    lcd.print("1..");
    delay(1000);
    lcd.clear();
    lcd.print("BUGGY STARTED");
    lcd.setCursor(0,1);
    lcd.print("SUCESSFULLY");
    fastBlinkGreen();
  }
 
 else   {
    lcd.clear();
    tone(9,200,450);
    lcd.print("Unverified user");
    digitalWrite(redPin, HIGH);
    delay(2000);
    lcd.clear();
    lcd.print("Access denied");
    fastBlinkRed();
  }
}

void fastBlinkGreen()
{
    digitalWrite(greenPin, HIGH);   
    delay(250);                      
    digitalWrite(greenPin, LOW);    
    delay(250);
    digitalWrite(greenPin, HIGH);   
    delay(250);                      
    digitalWrite(greenPin, LOW);    
    delay(250);
    digitalWrite(greenPin, HIGH);   
    delay(250);                      
    digitalWrite(greenPin, LOW);    
    delay(250);
    digitalWrite(greenPin, HIGH);   
    delay(250);                      
    digitalWrite(greenPin, LOW);    
    delay(250);
    digitalWrite(greenPin, HIGH);   
    delay(250);                      
    digitalWrite(greenPin, LOW);    
    delay(250);
    digitalWrite(greenPin, HIGH);   
    delay(250);                      
    digitalWrite(greenPin, LOW);    
    delay(250);
  }
  
void fastBlinkRed()
{
    digitalWrite(redPin, LOW);   
    delay(150);                      
    digitalWrite(redPin, HIGH);    
    delay(350);
    digitalWrite(redPin, LOW);   
    delay(150);                      
    digitalWrite(redPin, HIGH);    
    delay(350);
    digitalWrite(redPin, LOW);   
    delay(150);                      
    digitalWrite(redPin, HIGH);    
    delay(350);
    digitalWrite(redPin, LOW);   
    delay(150);                      
    digitalWrite(redPin, HIGH);    
    delay(350);
    digitalWrite(redPin, LOW);   
    delay(150);                      
    digitalWrite(redPin, HIGH);    
    delay(350);
    digitalWrite(redPin, LOW);
  }
