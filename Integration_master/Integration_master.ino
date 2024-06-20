
// LCD Library 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address >> 0x27 (GREEN) หรือ 0x3F (BLUE) 

// RGB Library 
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN 7
#define PIN2 8
Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(12, PIN2, NEO_GRB + NEO_KHZ800);
//servo head and arm 
#include <Servo.h>
#define servo_armRight_pin 9
#define servo_armleft_pin 10
#define servo_head_pin 11
Servo servo_armleft;
Servo servo_armRight;
Servo servo_head;

//voice recognition 
#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
VR myVR(2,3);    // 2:RX 3:TX, you can choose your favourite pins.
uint8_t records[7]; // save record
uint8_t buf[64];

//*********************************edit**********************************
#define Hello (0)         //Name command 0
#define Robot (1)         //Name command 1
#define red (2)      //Name command 2
#define green (3)      //Name command 3
#define goodbye (4)      //Name command 4
#define Seeyou (5)      //Name command 5
#define command6 (6)      //Name command 6
//***********************************************************************

void setup() {
  // put your setup code here, to run once:
  myVR.begin(9600);
  Serial.begin(9600);
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.setBrightness(50);
  strip2.show(); // Initialize all pixels to 'off'
  servo_head.attach(servo_head_pin);
  servo_armRight.attach(servo_armRight_pin);
  servo_armleft.attach(servo_armleft_pin);
  lcd.init();
  lcd.backlight();
  
 //***************************************voice************************
  if(myVR.clear() == 0){
    Serial.println("Recognizer cleared.");
  }else{
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while(1);
  }  
  if(myVR.load((uint8_t)Hello) >= 0){       //edit Name command 0 Name to match the line 32
  }
  if(myVR.load((uint8_t)Robot) >= 0){       //edit Name command 1 Name to match the line 33
  }
  if(myVR.load((uint8_t)red) >= 0){    //edit Name command 2 Name to match the line 34
  }
  if(myVR.load((uint8_t)green) >= 0){    //edit Name command 3 Name to match the line 35
  }
  if(myVR.load((uint8_t)goodbye) >= 0){    //edit Name command 4 Name to match the line 36
  }
  if(myVR.load((uint8_t)Seeyou) >= 0){    //edit Name command 5 Name to match the line 37
  }
  if(myVR.load((uint8_t)command6) >= 0){    //edit Name command 5 Name to match the line 38
  }
  //*********************************************************************

  
  setup_command();
}

void loop() {
   speech_command();
}
