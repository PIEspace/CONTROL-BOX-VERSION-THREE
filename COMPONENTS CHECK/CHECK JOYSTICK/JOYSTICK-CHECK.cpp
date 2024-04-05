// check the joystick 

#include<Arduino.h>

// define the joystick 
const int First_Joystick_X = A0;
const int First_Joystick_Y = A1;
const int Second_Joystick_X = A2;
const int Second_Joystick_Y = A3;



// define the globe variables
int First_Joystick_X_Value = 0;
int First_Joystick_Y_Value = 0;
int Second_Joystick_X_Value = 0;
int Second_Joystick_Y_Value = 0;


void setup(){
    // define the bud rate so in this case i am using 9600 bits per second 
    Serial.begin(9600);

    // define the pinMode
    pinMode(First_Joystick_X , INPUT);
    pinMode(First_Joystick_Y , INPUT);
    pinMode(Second_Joystick_X , INPUT);
    pinMode(Second_Joystick_Y , INPUT);


}

void loop(){

    // read the value from the joystick and show the data on your serial monitor
    First_Joystick_X_Value = analogRead(First_Joystick_X);
    First_Joystick_Y_Value = analogRead(First_Joystick_Y);
    Second_Joystick_X_Value = analogRead(Second_Joystick_X);
    Second_Joystick_Y_Value = analogRead(Second_Joystick_Y);


    // print on the serial monitor
    Serial.print("First_Joy_X = ");
    Serial.print(First_Joystick_X_Value);
    Serial.print(" , ");

    Serial.print("First_Joy_Y = ");
    Serial.print(First_Joystick_Y_Value);
    Serial.print(" , ");

    Serial.print("Second_Joy_X = ");
    Serial.print(Second_Joystick_X_Value);
    Serial.print(" , ");

    Serial.print("Second_Joy_Y = ");
    Serial.println(Second_Joystick_Y_Value);

    // delay 
    delay(15);

}