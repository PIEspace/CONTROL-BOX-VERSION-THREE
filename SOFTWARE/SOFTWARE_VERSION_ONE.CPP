// There is a second part.

#include<Arduino.h>
#include<Wire.h>
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>
#include <LiquidCrystal_I2C.h>


// DEFINE THE NRF24L01 MODULE 
//define the CE and CNS pin 
const int CE_PIN = 7 ;
const int CNS_PIN = 8;

//define the radio
RF24 radio (CE_PIN , CNS_PIN);

//define the address 
const byte address[][7] = {"12345" , "123456"};

// DEFINE THE LIQUID CRYSTAL DISPLAY
LiquidCrystal_I2C lcd(0x27 , 16 , 2);




// define the joystick 
const int FIRST_JOYSTICK_X = A0;
const int FIRST_JOYSTICK_Y = A1;
const int SECOND_JOYSTICK_X = A2;
const int SECOND_JOYSTICK_Y = A3;

// define the pushbutton 
const int FIRST_BUTTON = 2;
const int SECOND_BUTTON = 3;
const int THIRD_BUTTON = 4;
const int FOURTH_BUTTON = 5;
const int FIFTH_BUTTON = 6;




// define the global variable FOR JOYSTICK 
int FIRST_JOYSTICK_X_VALUE = 0;
int FIRST_JOYSTICK_Y_VALUE = 0;
int SECOND_JOYSTICK_X_VALUE = 0;
int SECOND_JOYSTICK_Y_VALUE = 0;

// DEFINE THE GLOBAL VARIABLES FOR PUSHBUTTON 
int FIRST_BUTTON_VALUE = 0;
int SECOND_BUTTON_VALUE = 0;
int THIRD_BUTTON_VALUE = 0;
int FOURTH_BUTTON_VALUE = 0;
int FIFTH_BUTTON_VALUE = 0;


struct data_package
{
    byte First_Joystick_X;
    byte First_Joystick_Y;
    byte Second_Joystick_X;
    byte Second_Joystick_Y;
    byte First_Button;
    byte Second_Button;
    byte Third_Button;
    byte Fourth_Button;
    byte Fifth_Button;

};
data_package data;


void setup(){
    // DEFINE THE BUD RATE IN THIS CASE I AM USING 9600 BITS PER SECOND (BPS)
    Serial.begin(9600);

    
    //define the pinMode for joystick 
    pinMode(FIRST_JOYSTICK_X , INPUT);
    pinMode(FIRST_JOYSTICK_Y , INPUT);
    pinMode(SECOND_JOYSTICK_X , INPUT);
    pinMode(SECOND_JOYSTICK_Y , INPUT);
    
    //define the pinMode for button 
    pinMode(FIRST_BUTTON , INPUT);
    pinMode(SECOND_BUTTON , INPUT);
    pinMode(THIRD_BUTTON , INPUT);
    pinMode(FOURTH_BUTTON , INPUT);
    pinMode(FIFTH_BUTTON , INPUT);
    // DEFINE THE NRF24L01 MODULE 
    radio.begin();
    radio.openWritingPipe(address[0]); //the address is = 12345
    radio.openReadingPipe(1 , address[1]); //the address is = 123456
    radio.setPALevel(RF24_PA_HIGH);
    radio.stopListening();

    

    data.First_Joystick_X = 127;
    data.First_Joystick_Y = 127;
    data.Second_Joystick_X = 127;
    data.Second_Joystick_Y = 127;

    

    data.First_Button = 0 ;
    data.Second_Button = 0;
    data.Third_Button = 0;
    data.Fourth_Button = 0;
    data.Fifth_Button = 0;

    lcd.init();
    lcd.backlight();
    lcd.println("PIE.SPACE");
    delay(2000);

}

void loop(){
    

    data.First_Joystick_X = map(analogRead(FIRST_JOYSTICK_X) , 0 , 1023 , 0 , 255);
    data.First_Joystick_Y = map(analogRead(FIRST_JOYSTICK_Y) , 0 , 1023 , 0 , 255);

    data.Second_Joystick_X = map(analogRead(SECOND_JOYSTICK_X) , 0 , 1023 , 0 , 255);
    data.Second_Joystick_Y = map(analogRead(SECOND_JOYSTICK_Y) , 0 , 1023 , 0 , 255);

    
    data.First_Button = digitalRead(FIRST_BUTTON);
    data.Second_Button = digitalRead(SECOND_BUTTON);
    data.Third_Button = digitalRead(THIRD_BUTTON);
    data.Fourth_Button = digitalRead(FOURTH_BUTTON);
    data.Fifth_Button = digitalRead(FIFTH_BUTTON);
    

    radio.write(&data , sizeof(data_package));


    if(data.First_Joystick_X >=130){
        lcd.clear();
        lcd.print("Fir_Joy_X =");
        lcd.println(data.First_Joystick_X);
        

    }

    else if(data.First_Joystick_X <= 120){
        lcd.clear();
        lcd.print("Fir_Joy_X =");
        lcd.println(data.First_Joystick_X);
        
    }




    




    


}