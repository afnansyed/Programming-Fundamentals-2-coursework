#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "extrafile.h"

using namespace std;

//default constructor
Legos::Legos() {
    number = 0;
    miniFigs = 0;
    pieces = 0;
    usPrice = 0.00;
}

//constructor
Legos::Legos(int number, string theme, string name, int miniFigs, int pieces, double usPrice) {
    this->number = number;
    this->theme = theme;
    this->name = name;
    this->miniFigs = miniFigs;
    this->pieces = pieces;
    this->usPrice = usPrice;
}

//get number
int Legos::getNumber() {
    return number;
}

//get theme
string Legos::getTheme() {
    return theme;
}

//get name
string Legos::getName() {
    return name;
}

//get number of minifigs
int Legos::getMiniFigs() {
    return miniFigs;
}

//get number of pieces
int Legos::getPieces() {
    return pieces;
}

//get price
double Legos::getUSPrice() {
    return usPrice;
}

//display set
void Legos::Display() {
    cout << "Name: " << name << endl;
    cout << "Number: " << number << endl;
    cout << "Theme: " << theme << endl;
    cout << "Price: $" << usPrice << endl;
    cout << "Minifigures: " << miniFigs << endl;
    cout << "Piece count: " << pieces << endl;
}

//display set for options 3 and 4
void Legos::displayN() {
    cout << number << " " << name << " $" << usPrice << endl;
}





