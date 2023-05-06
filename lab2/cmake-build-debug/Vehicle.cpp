#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(){ //default constructor, variables initialized to default values
    make = "COP3503";
    model = "Rust Bucket";
    year = 1900;
    price = 0;
    mileage = 0;
}

Vehicle::Vehicle(string make, string model, int year, float price, int mileage){
    this->make = make; //"this ->" reference: Classes lecture and COP3502
    this->model = model;
    this->year = year;
    this->price = price;
    this->mileage = mileage;
}

void Vehicle::Display(){  //print out vehicles in a single line
    cout << year << " " << make << " " << model << " $" << price << " " << mileage << endl;
}

string Vehicle::GetYearMakeModel(){ //create and return a string
    string stringYear = to_string(year); //int to string conversion, Reference: Prof. Fox on slack
    string YearMakeModel = stringYear + " " + make + " " + model;

    return YearMakeModel;
}

float Vehicle::GetPrice(){ //return the price
    return price;
}
