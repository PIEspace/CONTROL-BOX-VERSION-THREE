// check the pushbutton connect to the arduino nano


#include<Arduino.h>

// define the pushbutton 
const int First_Push_Button = 2;
const int Second_Push_Button = 3;
const int Third_Push_Button = 4;
const int Fourth_Push_Button = 5;
const int Fifth_Push_Button = 6;


// DEFINE THE GLOBAL VARIABLES 
int First_Push_Button_Value = 0 ;
int Second_Push_Button_Value = 0;
int Third_Push_Button_Value = 0;
int Fourth_Push_Button_Value = 0;
int Fifth_Push_Button_Value = 0;


void setup(){
    // define the bud rate 
    // in this case i am using 9600 bits per second 
    Serial.begin(9600);

    // define the pinMode
    pinMode(First_Push_Button , INPUT);
    pinMode(Second_Push_Button , INPUT);
    pinMode(Third_Push_Button , INPUT);
    pinMode(Fourth_Push_Button , INPUT);
    pinMode(Fifth_Push_Button , INPUT);


}


void loop(){

    // read the pushbutton values 
    First_Push_Button_Value = digitalRead(First_Push_Button);
    Second_Push_Button_Value = digitalRead(Second_Push_Button);
    Third_Push_Button_Value = digitalRead(Third_Push_Button);
    Fourth_Push_Button_Value = digitalRead(Fourth_Push_Button);
    Fifth_Push_Button_Value = digitalRead(Fifth_Push_Button);

    // print on the serial monitor
    // define the first pushbutton 
    Serial.print("First_Button = ");
    Serial.print(First_Push_Button_Value);
    Serial.print(" , ");
  
    //define the second pushbutton  
    Serial.print("Second_Button = ");
    Serial.print(Second_Push_Button_Value);
    Serial.print(" , ");


    //define the third pushbutton 
    Serial.print("Third_Button = ");
    Serial.print(Third_Push_Button_Value);
    Serial.print(" , ");

    //define the fourth pushbutton
    Serial.print("Fourth_Button = ");
    Serial.print(Fourth_Push_Button_Value);
    Serial.print(" , ");


    //define the fifth pushbutton 
    Serial.print("Fifth_Button = ");
    Serial.println(Fifth_Push_Button_Value);


    delay(15);

}