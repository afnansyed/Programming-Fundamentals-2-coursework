#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Legos{

private:
//variables
    int number;
    string theme;
    string name;
    int miniFigs;
    int pieces;
    double usPrice;

public:
    Legos();  //default constructor
    Legos(int number,string theme,string name,int miniFigs, int pieces,double usPrice);  //contructor
    int getNumber();
    string getTheme();
    string getName();
    int getMiniFigs();
    int getPieces();
    double getUSPrice();
    void Display();
    void displayN();
};
