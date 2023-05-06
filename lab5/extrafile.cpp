#include <iostream>
#include <fstream>
#include "extrafile.h"
using namespace std;

//default contructor
Ships::Ships() {
    shipLength = 0;
    capacity = 0;
    maxSpeed = 0.00f;
    numWeapons = 0;
}

//constructor
Ships::Ships(string name, string shipClass, short shipLength, int capacity, float maxSpeed, int numWeapons, vector<Weapons> weapons) {
    this->name = name;
    this->shipClass = shipClass;
    this->shipLength = shipLength;
    this->capacity = capacity;
    this->maxSpeed = maxSpeed;
    this->numWeapons = numWeapons;
    this->weapons = weapons;

}

//default contructor
Ships::Weapons::Weapons() {
    powerRating = 0;
    powerConsuption = 0.00f;
}

//constructor
Ships::Weapons::Weapons(string data, int powerRating, float powerConsuption) {
    this->data = data;
    this->powerRating = powerRating;
    this->powerConsuption = powerConsuption;
}

//print current variable values of current weapon
void Ships::Weapons::displayW() {
    cout << data << ", " << powerRating << ", " << powerConsuption << endl;
}

//get weapon name
string Ships::Weapons::getData() {
    return data;
}

//get power rating
int Ships::Weapons::getPowerRating() {
    return powerRating;
}

//get power consumption
float Ships::Weapons::getPowerCon() {
    return powerConsuption;
}


//get ship name
string Ships::getName() {
    return name;
}


//get ship class
string Ships::getClass() {
    return shipClass;
}

//get ship length
short Ships::getLength() {
    return shipLength;
}

//get ship capacity
int Ships::getCapacity() {
    return capacity;
}

//get maximum warp speed
float Ships::getMaxSpeed() {
    return maxSpeed;
}

//get number of weapons
int Ships::getNumWeapons() {
    return numWeapons;
}

//get total power rating of current ship
int Ships::totalFirePower() {
    int totalFirePower = 0;
    for ( int i =0; i < numWeapons; i++){ //loop through all the weapons
        totalFirePower += weapons[i].getPowerRating();  //add the power ratings
    }
    return totalFirePower;  //return power rating
}

//get highest power rating
int Ships::mostPowerful() {
    int currentPowerful = 0;
    for( int i =0; i<numWeapons; i++){   //loop through all the weapons
        if(currentPowerful < weapons[i].getPowerRating()){  //if current value of currentPowerful is less than the power rating at current weapon
            currentPowerful = weapons[i].getPowerRating();  //assign value of currentPowerful to value of power rating at current weapon
        }
    }
    return currentPowerful; //return the highest power rating
}

//print ship
void Ships::Display() {

    cout << "Name: "<< name <<endl;
    cout << "Class: " << shipClass << endl;
    cout << "Length: " << shipLength << endl;
    cout << "Shield capacity: " << capacity << endl;
    cout << "Maximum Warp: " << maxSpeed << endl;
    cout << "Armaments: " << endl;

    if(numWeapons == 0){ //if number of weapons is 0
        cout << "Unarmed" << endl << endl;
    }
    else{
        for ( int i =0; i < numWeapons; i++){ //loop through all the weapons
            weapons[i].displayW();  //print current weapon
        }

        int totalFirePower = 0;   //total power rating
        for ( int i =0; i < numWeapons; i++){  //loop though all the weapons
            totalFirePower += weapons[i].getPowerRating();  //add current power rating
        }
        cout << "Total firepower: " << totalFirePower << endl << endl;

    }

}



