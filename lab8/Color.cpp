

#include "Color.h"
#include <map>

//set the int value and get the rgb values
void Color::SetValue(int value) {
    this->value = value;

    //Steps given in lab document
//Step 1: Shift them all the way to the right
//Step 2: & the result with 255, to see which bits are on

    red = (value >> 16) & 255;  //shift value by 16 bits + & w/255  to get red value
    green = (value >> 8) & 255;  //shift value by 8 bits + & w/255  to get green value
    blue = value & 255;  // & w/255  to get blue value
}

//set the name of the color
void Color::SetName(const char *name) {
    this->name = (string) name;
}

//return red value
unsigned char Color::GetR() const {
    return red;
}

//return green value
unsigned char Color::GetG() const {
    return green;
}

//return blue value
unsigned char Color::GetB() const {
    return blue;
}

//get the hex num conversion value
unsigned char Color::hexNum(int num) const{
unsigned char x;

if(num == 1){
    x = '1';
}
else if(num == 2){
    x = '2';
}
else if(num == 3){
    x = '3';
}
else if(num == 4){
    x = '4';
}
else if(num == 5){
    x = '5';
}
else if(num == 6){
    x = '6';
}
else if(num == 7){
    x = '7';
}
else if(num == 8){
    x = '8';
}
else if(num == 9){
    x = '9';
}
else if(num == 10){
    x = 'A';
}
else if(num == 11){
    x = 'B';
}
else if(num == 12){
    x = 'C';
}
else if(num == 13){
    x = 'D';
}
else if(num == 14){
    x = 'E';
}
else{
    x = 'F';
}


return x;  //return hex number
}

//get the hex value of the color
string Color::GetHexValue() const {
    //Instructions on how to convert rgb values to hex given in the lab document

    string hex = "0x000000";  //set the value of string

    //red value value
    int r = (int)red/16;   //first digit
    int r2 = (int)red % 16;  //second digit

    //get the hex number
    if(r != 0){
        hex.at(2) = hexNum(r);   //Reference for changing a character in a string Zybooks: 4.3
    }
    if(r2 != 0){
        hex.at(3) = hexNum(r2);
    }

    //green value
    int g = (int)green/16;  //first digit
    int g2 = (int)green % 16;   //second digit

    //get the hex number
    if(g != 0){
        hex.at(4) = hexNum(g);
    }
    if(g2 != 0){
        hex.at(5) = hexNum(g2);
    }

    //blue value
    int b = (int)blue/16;   //first digit
    int b2 = (int)blue % 16;   //second digit

    //get the hex number
    if(b != 0){
        hex.at(6) = hexNum(b);
    }
    if(b2 != 0){
        hex.at(7) = hexNum(b2);
    }

    return hex;
}


//return name of color
string Color::GetName() const {
    return name;
}

