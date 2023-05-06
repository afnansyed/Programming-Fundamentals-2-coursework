#include <iostream>
#include "Dealership.h"

using namespace std;

Dealership::Dealership(string name, unsigned int capacity){ //constructor
    this->name = name; //"this ->" reference: Classes lecture and COP3502
    this->capacity = capacity;
}

void Dealership::AddShowroom(Showroom s){ //behavior
    if(numberOfShowrooms == capacity){ //if dealership is full
        cout << "Dealership is full, can't add another showroom!" << endl;
    }
    else{ //if there is space
        showroomObjects.push_back(s); //add passed-in object to vector class member
        numberOfShowrooms++; //increase the total number of showrooms by 1
    }
}

float Dealership::GetAveragePrice(){ //behavior, for-loop reference: Zybooks textbook 6.4
    for (int i=0; i<showroomObjects.size(); i++){ //loop through showrooms
        numberOfVehicles = showroomObjects[i].GetVehicleList(); //find total number of vehicles in a showroom
        for(int i = 0; i<numberOfVehicles.size(); i++){ //loop through all vehicles in a showroom
            totalPrice = totalPrice + numberOfVehicles[i].GetPrice(); //get price of each and add to total price
            numOfVehicles++; //increase the total number of vehicles by 1
        }
    }
    float average = totalPrice/numOfVehicles; //find average

    return average; //return average price
}

void Dealership::ShowInventory(){ //behavior, show all showrooms
    if (numberOfShowrooms == 0){ //if there are no showrooms
        cout << name << " is empty!" << endl;
        cout << "Average car price: $0.00";
    }
    else { //if there are showrooms
        for (int i = 0; i < showroomObjects.size(); i++) { //loop through all showrooms, for-loop reference: Zybooks textbook 6.4
            showroomObjects[i].ShowInventory();
            cout<< endl;
        }
        cout << "Average car price: $" << GetAveragePrice(); //display average price
    }
}
