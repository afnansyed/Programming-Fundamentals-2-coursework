#include <iostream>
#include <vector>
#include "Showroom.h"
using namespace std;

Showroom::Showroom(string name, unsigned int capacity) {  //default constructor
this->name = name; //"this ->" reference: Classes lecture and COP3502
this->capacity = capacity;
}

vector <Vehicle> Showroom:: GetVehicleList(){ //accessor, return to vehicle objects
    return vehicleObjects;
}

void Showroom::AddVehicle(Vehicle v){ //behavior
    if(numberOfVehicles == capacity){ //if showroom is full
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    }
    else{ //if showroom has space
        vehicleObjects.push_back(v); //add vehicle
        numberOfVehicles++; //increase the total number of vehicles by 1
    }
}

void Showroom::ShowInventory(){ //behavior
    if (numberOfVehicles == 0){ //if there are no cars in the showroom
        cout << name << " is empty!" << endl;
    }
    else { //if there are cars, print all of them using Display()
        cout << "Vehicles in " << name << endl;
        for (int i = 0; i < vehicleObjects.size(); i++) { //use for-loop to print out each one, for-loop Reference: Zybooks textbook 6.4
            vehicleObjects[i].Display();
        }
    }
}

float Showroom::GetInventoryValue(){ //behavior
    for(int i = 0; i<vehicleObjects.size(); i++){  //add all the prices of all the cars, for-loop Reference: Zybooks textbook 6.4
        totalPrice = totalPrice + vehicleObjects[i].GetPrice();
    }
    return totalPrice; //return total price
}

