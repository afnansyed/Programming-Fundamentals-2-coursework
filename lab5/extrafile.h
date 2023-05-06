#pragma once
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Ships{
public:
    class Weapons{ //nested class for ship's weapons; Reference: TA Alexis Daugherty
    public:
        //variables
        string data;  //weapon name
        int powerRating;  //power rating
        float powerConsuption;  //power consumption

        Weapons();  //default constuctor
        Weapons(string data, int powerRating, float powerConsuption);  //constructer
        void displayW();
        string getData();
        int getPowerRating();
        float getPowerCon();
    };

public:
//variables


    string name;   //A string for the name of the vessel
    string shipClass;  //A string for the class of ship
    short shipLength;  // The length of the ship, stored as a short
    int capacity;  //The shield capacity, stored as an integer
    float maxSpeed;  // The maximum warp speed of the ship, stored as a float
    int numWeapons;  //number of weapons
    vector<Weapons> weapons; // An inventory containing a variable number of weapons


public:
    Ships();  //default constructor
    Ships(string name, string shipClass, short shipLength, int capacity, float maxSpeed, int numWeapons, vector<Weapons> weapons);  //contructor
    string getName();
    string getClass();
    short getLength();
    int getCapacity();
    float getMaxSpeed();
    int getNumWeapons();
    int totalFirePower();
    int mostPowerful();
    void Display();
};