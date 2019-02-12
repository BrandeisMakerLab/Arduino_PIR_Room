  #include <Adafruit_NeoPixel.h>
      #define PIN 9
 
/**
 * This code is the source code to allow a user to use the PIR sensor with an RGB LED.
 * When the sensor triggers, the LED should light up, if the sensor is continuously activated,
 * it will remain lit and change color from green to red
 */

//int ledPin = 13;          //pin for the RGB led
int out = 3;         //the input from the PIR sensor
int middle = 2;      //input for middle PIR
int in = 1;          //input for the inner PIR sensor
int counter = 0;          //if pin is triggered multiple times it will grandually change color

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
//  pinMode(ledPin,OUTPUT);
  pinMode(out, INPUT);    //PIR throws out ~679 through the analog out... so we should keep that in mind for the threshold
  pinMode(middle, INPUT);
  pinMode(in, INPUT);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  int outerRead = analogRead(out);
  int middleRead = analogRead(middle);
  int inRead = analogRead(in);
  checkMove(outerRead, 2);
  checkMove(middleRead, 1);
  checkMove(inRead, 0);
  strip.show();
}

void checkMove(int on, int pir){
   if(on>600){           //we will set threshold well below PIR value so that we get all use cases
//    digitalWrite(ledPin,HIGH);
    strip.setPixelColor(pir, 255, 0, 255);
    
    
  }else{
//    digitalWrite(ledPin,LOW);
    strip.setPixelColor(pir, 0, 0, 0);
  }
}

