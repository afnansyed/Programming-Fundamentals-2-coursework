#include <iostream>
#include <vector>
#include "Showroom.h"
using namespace std;

#pragma once

class Dealership{
    vector <Showroom> showroomObjects;
    string name;
    int capacity;
    int numberOfShowrooms = 0; //total number of showrooms
    vector <Vehicle> numberOfVehicles;
    float totalPrice = 0;
    int numOfVehicles = 0; //total number of vehicles

public:
    Dealership(string name = "Generic Dealership", unsigned int capacity = 0);
    void AddShowroom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();

};