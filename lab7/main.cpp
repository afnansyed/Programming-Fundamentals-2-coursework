#include <iostream>
#include <map>
#include <random>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

mt19937 random_mt;

int Random(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

//rolling the dice
void RollDice(int numberOfRolls, int numberOfSides){
    map<int,int> dice; //create map

    int number;  //number rolled
    for(int i = 1; i <= numberOfRolls; i++){
        number = Random(1,numberOfSides); //get the side rolled
        dice[number] += 1;   //increment the value for the key (number rolled)
    }

    //print all the keys and values in the map
    for(int i = 1; i <= numberOfSides; i++){
        cout << i << ": " << dice[i] << endl;
    }

}

//data from file
class state{
public:
    string stateName;
    int capitaIncome = 0;
    int population = 0;
    int houseIncome = 0;
    int numHouses = 0;

    state(){
        capitaIncome = 0;
        population = 0;
        houseIncome = 0;
        numHouses = 0;
    }
    state(string stateName, int capitaIncome, int population, int houseIncome,int numHouses){
        this->stateName = stateName;
        this->capitaIncome = capitaIncome;
        this->population = population;
        this->houseIncome = houseIncome;
        this->numHouses = numHouses;
    }
};

int main()
{
    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;

    if (option == 1)
    {
        int randomSeed;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);


        int numberOfRolls;
        cout << "Number of times to roll the die: ";
        cin >> numberOfRolls; // user input

        int numberOfSides;
        cout << "Number of sides on this die: ";
        cin >> numberOfSides; // user input

        // Roll Dice
        RollDice(numberOfRolls, numberOfSides);
    }
    else if (option == 2){
        // Load the states

        //Reference and steps for reading and saving data from a file: Prof. Fox's Reading Complex data using ifstream lecture

        map<string,state> files;  //create map

        ifstream inFile("states.csv");

        //if file is open
        if (inFile.is_open()){

            //0. Read the heading data from the file
            string line;
            getline(inFile, line);

            //1. Get all enteries/records from the file, one line at a time
            while(getline(inFile, line)){

                state S;  //state class object

                //2. create a stream from the line of data from the file
                istringstream stream(line);

                getline(stream, S.stateName, ',');  //get state name

                //get capita income
                string capIn;
                getline(stream, capIn, ',');
                S.capitaIncome = stoi(capIn);

                //get population
                string pop;
                getline(stream, pop, ',');
                S.population = stoi(pop);

                //get house income
                string house;
                getline(stream, house, ',');
                S.houseIncome = stoi(house);

                //get number of houses
                string numH;
                getline(stream, numH, ',');
                S.numHouses = stoi(numH);

                files.emplace(S.stateName, S);  //add key (name of the state) and value (class) to map; reference: Prof. Fox maps lecture and Zybooks 18.4
            }
        }


        // Get input for option 1 (show all states) or 2 (do a search for a particular state)
        int choice;
        cout << "1. Print all states " << endl;
        cout << "2. Search for a state " << endl;
        cin >> choice; // user input

        if(choice == 1){
            map<string, state>::iterator iter = files.begin();  //reference: Prof. Fox maps lecture

            //loop through the map to print all the key and values; reference: Prof. Fox maps lecture
            for(iter = files.begin(); iter != files.end(); iter++){
                cout << iter->first << endl;
                cout << "Population: " << (iter->second).population << endl;
                cout << "Per Capita Income: " << (iter->second).capitaIncome << endl;
                cout << "Median Household Income: " << (iter->second).houseIncome << endl;
                cout << "Number of Households: " << (iter->second).numHouses << endl;
            }
        }

        else if(choice == 2){
            //get particular state
            string stateName;
            cin >> stateName;  //user input

            map<string, state>::iterator iter = files.begin();
            bool found = false;
            //loop through the map; reference: Prof. Fox maps lecture
            for(iter = files.begin(); iter != files.end(); iter++){

                //if the key matches the inputed state name, print the key and the value
                if(iter->first == stateName) {
                    cout << iter->first << endl;
                    cout << "Population: " << (iter->second).population << endl;
                    cout << "Per Capita Income: " << (iter->second).capitaIncome << endl;
                    cout << "Median Household Income: " << (iter->second).houseIncome << endl;
                    cout << "Number of Households: " << (iter->second).numHouses << endl;

                    found = true;  //found is true
                }
            }

            //if inputed state name is not found in the map
            if(found == false){
                cout << "No match found for " << stateName << endl;
            }
        }

    }

    return 0;
}
