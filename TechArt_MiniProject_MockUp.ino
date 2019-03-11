

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

// Defines the pins to which the button and LED are connected.
const int colorR = 0;
const int colorG = 255;
const int colorB = 10;

// Defines the pins to which the button is connected.
const int pinButton = 4; //this will be simulated with jumper wires
const int pinElBlue = 7; //Blue EL wire for OBEY sign
const int pinElYellow = 6; //Yellow EL wire for OBEY sign, when puzzle piece is put in
const int pinElOrange = 5; //Orange EL wire for dis sign, when puzzle piece is put in
const int pinMagnet = 2; //Electromagnet in the puzzle
int counter = 0; //counter initialization for strobe effect


void setup() 
{
  
    // Configure the button's pin for input signals.
    pinMode(pinButton, INPUT);

    // Configure the Blue El wire's pin for output.
    pinMode(pinElBlue, OUTPUT);

    // Configure the Yellow El wire's pin for output.
    pinMode(pinElYellow, OUTPUT);

    // Configure the Orange EL wire's pin for output.
    pinMode(pinElOrange, OUTPUT);

    // Configure the magnet's pin for output.
    pinMode(pinMagnet, OUTPUT);
    
 
}

void loop() 
{
   
    digitalWrite(pinElBlue, HIGH);
    digitalWrite(pinMagnet, LOW);
    
    if(digitalRead(pinButton))
    {
        delay(1000);
        // When the button is pressed, turn the Yellow and Orange El wire's on.
        digitalWrite(pinElOrange, HIGH);
        digitalWrite(pinElYellow, HIGH);
        digitalWrite(pinElBlue, LOW);
        digitalWrite(pinMagnet, HIGH);

        counter = 0;
        //five seconds for the strobe effect
        while(counter < 4000)
        {
          digitalWrite(pinElYellow, HIGH);
          digitalWrite(pinElOrange, HIGH);
          delay(500);
          digitalWrite(pinElYellow, LOW);
          digitalWrite(pinElOrange, LOW);
          delay(500);
          counter = counter + 1000;
        }
     
    }
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
