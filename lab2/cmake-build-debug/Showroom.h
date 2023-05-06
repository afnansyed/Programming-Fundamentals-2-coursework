#include <iostream>
#include <vector>
#include "Vehicle.h"
using namespace std;

#pragma once

class Showroom{
    string name;
    vector <Vehicle> vehicleObjects;
    int capacity;
    int numberOfVehicles = 0; //total number of vehicles
    int totalPrice = 0;

public:
    Showroom(string name = "Unnamed Showroom", unsigned int capacity = 0);
    vector <Vehicle> GetVehicleList();
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
};