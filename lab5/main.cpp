#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "extrafile.h"
using namespace std;

void getData(string file, vector<Ships>& ships){
//Reference for writing getData function and steps:
// Prof. Fox's Binary File I/O-Reading complex data lecture
//TA: Alexis Daugthery
// Lecture: Binary File I/O slides

    ifstream inFile(file, ios_base::binary);  //collecting data

    unsigned int count;
    inFile.read((char*)&count, sizeof(count));  //reading collection of data

    for(unsigned int i = 0; i<count; i++){

        //1. Read name
        int length;
        inFile.read((char*)&length, sizeof (length));  //Read length of the string
        char* words = new char[length];  //dynamically allocate an array of charecters of that size
        inFile.read(words, length); //read into the array
        string name = words;  //copy array into string
        delete[] words;  //delete array

        //2. read ship class
        inFile.read((char*)&length,sizeof (length));
        words = new char[length];
        inFile.read(words, length);
        string shipClass = words;
        delete[] words;

        //3. read ship length
        short shipLength;
        inFile.read((char*)&shipLength,sizeof(shipLength));  //read length of short

        //4. read capacity
        int capacity;
        inFile.read((char*)&capacity,sizeof (capacity));  //read length of int

        //5. get max speed
        float maxSpeed;
        inFile.read((char*)&maxSpeed,sizeof (maxSpeed));  //read length of float

        //6. get number of weapons
        int numWeapons;
        inFile.read((char*)&numWeapons,sizeof(numWeapons)); //read length of int

        string data;
        int powerRating;
        float powerConsuption;
        vector<Ships::Weapons> weapons;  //create vector of weapons, References: TA: Alexis Daughtery

        //Reference for writing this for loop: TA Alexis Daugthery
        for(int j =0; j<numWeapons; j++){

            //7. get name of weapon
            inFile.read((char*)&length,sizeof (length));
            words = new char[length];
            inFile.read(words, length);
            data = words;
            delete[] words;

            //8. get power rating of weapon
            inFile.read((char*)&powerRating,sizeof(powerRating));

            //9. get power consumption of weapon
            inFile.read((char*)&powerConsuption,sizeof(powerConsuption));

            //construct weapons object from the data
            Ships::Weapons w(data, powerRating, powerConsuption);
            weapons.push_back(w);  //store data

        }

        //construct ship object from the data
        Ships s(name, shipClass, shipLength, capacity, maxSpeed, numWeapons, weapons);
        ships.push_back(s);  //store data

    }

}

int main(){
    vector<Ships> ships;  //vector to store ship data

/*
    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    */

    int option;
    cin >> option;

    /* Load files here */
    if(option == 1){
        getData("friendlyships.shp", ships);
    }
    if(option == 2){
        getData("enemyships.shp", ships);
    }
    if(option == 3){
        getData("friendlyships.shp", ships);
        getData("enemyships.shp", ships);
    }


    /*
    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;
*/

    cin >> option;

    //1. Print all the ships
    if(option == 1){
        for(unsigned  int i =0; i<ships.size(); i++){ //loop through all the ships
            ships[i].Display(); //print ship at current index
        }
    }

    //2. Print the starship with the most powerful weapon
    if(option == 2){
        unsigned int index = 0;  //index
        int mostPower = 0; // current power rating

        for(unsigned int i =0; i<ships.size(); i++){   //loop through all the ships
            if(mostPower < ships[i].mostPowerful()){  //if current value of the mostPower is less than the highest power rating in current ship
                mostPower = ships[i].mostPowerful();  //assign current value of the mostPower to value of the highest power rating in current ship
            }
        }

        for(unsigned  int i =0; i<ships.size(); i++){   //loop through all the ships
            if(mostPower == ships[i].mostPowerful()){  //if value of the mostPower matches the value of the highest power rating in current ship
                index = i;  //save index
            }
        }

        ships[index].Display();  //print ships at the stored index
    }

    //3. Print the most powerful ship (highest combined power rating of all weapons)
    if(option == 3){

        int currentFire = 0;  //current highest sum of power ratings of a ship
        unsigned int index = 0;  //index

        for(unsigned int i =0; i<ships.size(); i++){  //loop through all the ships
            if(currentFire < ships[i].totalFirePower()){   //if current highest sum of power ratings of a ship is less than the sum of power ratings of ship at index
                currentFire = ships[i].totalFirePower();  //assign the value of currentFire to the sum of power ratings of ship at current index
            }
        }

        for(unsigned  int i =0; i<ships.size(); i++){  //loop through all the ships
            if(currentFire == ships[i].totalFirePower()){  //if the current highest sum of power ratings of a ship matches the value of the sum of power ratings of ship at index
                index = i;  //save index as current index
            }
        }

        ships[index].Display();  //display ship at the stored index

    }

    //4. Print the weakest ship (out of ships that actually have weapons)
    if(option == 4){
        unsigned int index = 0;  // index
        int currentFire = ships[0].totalFirePower();  //assign value of currentFire to the sum of the total power ratings at index 0

        for(unsigned int i =0; i< ships.size(); i++){ //loop through all ships
            if(ships[i].getNumWeapons() > 0) {  //if number of weapons is greater than 0
                if (currentFire > ships[i].totalFirePower()) {  //if current sum of power ratings of a ship is greater than the sum of power ratings at current index
                    currentFire = ships[i].totalFirePower(); //assign value of currentFire to sum of power ratings at current index
                }
            }
        }

        for(unsigned  int i =0; i<ships.size(); i++){  //loop through all ships
            if(currentFire == ships[i].totalFirePower()){  //if value of sum of power ratings at current index matches the value of currentFire
                index = i;  //save index
            }
        }

        ships[index].Display();  //display ship at the stored index

    }

    //5. Print the unarmed ships
    if(option == 5){
        for(unsigned int i =0; i< ships.size(); i++){  //loop through all the ships
            if(ships[i].getNumWeapons() == 0) {  //if number of ships for current ship is 0
                ships[i].Display();  //print ship
            }
        }
    }


    return 0;
}