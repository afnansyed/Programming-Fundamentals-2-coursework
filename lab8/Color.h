#pragma once
#include <iostream>
#include <string>
using namespace std;

class Color{
public:
    int value;
    string name;
    unsigned char red;
    unsigned char green;
    unsigned char blue;

    Color(){
        value = 0;
    }
    Color(int value, string name){
        this->value = value;
        this->name = name;
    }
    //Given an integer value, convert it to RGB and Hex values
    void SetValue(int value);
    void SetName(const char *name);

    //Accessors
    unsigned char GetR() const;
    unsigned char GetG() const;
    unsigned char GetB() const;
    string GetHexValue() const;
    string GetName() const;
    unsigned char hexNum(int num) const;  //set hex value

};