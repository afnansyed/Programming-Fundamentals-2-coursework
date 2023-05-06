#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include "Color.h"
using namespace std;

void ReadFile(const char* filename,  map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);

int main()
{
    cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
    cout << "7. Load all 6 files" << endl;
    int choice;
    cin >> choice;

    map<string, Color> colors;
    if (choice >= 1 && choice <= 6)
    {
        string file = "colors" + to_string(choice) + ".txt";
        ReadFile(file.c_str(), colors);
    }
    else if (choice == 7)
    {
        for (int i = 1; i <= 6; i++)
        {
            string file = "colors" + to_string(i) + ".txt";
            ReadFile(file.c_str(), colors);
        }

    }

    // Secondary menu
    cout << "1. Show all colors" << endl;
    cout << "2. Search for a color" << endl;
    cin >> choice;

    if (choice == 1)
        PrintColors(colors);
    else if (choice == 2)
        SearchForColor(colors);
    return 0;
}

void ReadFile(const char* filename, map<string, Color>& colors) {
    // TODO: Read the file, create and store some Color objects
    //Reference for writing this function: Prof. Fox Reading complex data using if stream Lecture
    string file = (string) filename;
    ifstream inFile(file);

    //if file is open
    if (inFile.is_open()) {

        string line;

        //1. Get all enteries/records from the file, one line at a time
        while (getline(inFile, line)) {

            Color C;  // class object

            //2. create a stream from the line of data from the file
            istringstream stream(line);

            string colorName;
            getline(stream, colorName, ' ');  //get state name
            C.name = colorName;

            string colorNum;
            getline(stream, colorNum);
            C.value = stoi(colorNum);

            C.SetName(colorName.c_str());
            C.SetValue(C.value);

            colors[C.name] = C; //add key (name of the color) and value (class) to map; reference: Prof. Fox maps lecture and Zybooks 18.4

        }

    }
}

void PrintColors(const map<string, Color>& colors)
{
    // TODO: iterate through all entries in the map and print each color, one at a time

     map<string, Color>::const_iterator iter = colors.begin();
    //loop through the map to print all the key and values; reference: Prof. Fox maps lecture
    int counter = 0;
    for(colors.begin(); iter != colors.end(); iter++){
        PrintColor(iter->second);  //print color
        counter++;
    }
    // Print out the color count afterward
    cout << "Number of colors: " << counter << endl;

}
void PrintColor(const Color& color)
{
    cout << left << setw(20) << color.GetName();
    cout << right << setw(10) << color.GetHexValue();
    cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors)
{
    // TODO: Get some input, check if that key exists, then print out the color (or an error message)
    //get input
    string colorSearch;
    cin >> colorSearch;  //user input

    map<string, Color>::iterator iter = colors.begin();
    bool found = false;
    //loop through the map; reference: Prof. Fox maps lecture
    for(iter = colors.begin(); iter != colors.end(); iter++){

        //if the key matches the inputed state name, print the key and the value
        if(iter->first == colorSearch) {
            PrintColor(iter->second);
            found = true;  //found is true
        }
    }

    //if inputed state name is not found in the map
    if(found == false){
        cout << colorSearch << " not found!" << endl;
    }
}