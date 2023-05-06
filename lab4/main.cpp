#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include "extrafile.h"

using namespace std;

void getData(string file, vector<Legos>& legos){
    //Reference in writing this function: Prof. Fox's Reading Complex data using ifstream lecture

    ifstream inFile(file);

    //if file is open
    if (inFile.is_open()){

        //0. Read the heading data from the file
        string line;
        getline(inFile, line);

        //1. Get all enteries/records from the file, one line at a time
        while(getline(inFile, line)){

            //2. create a stream from the line of data from the file
            istringstream stream(line);

            int number;
            string numStr;

            string theme;
            string name;

            int miniFigs;
            string miniFigStr;

            int pieces;
            string piecesStr;

            double usPrice;
            string usPriceStr;

            getline(stream, numStr, ',');
            number = stoi(numStr);

            getline(stream, theme, ',');
            getline(stream, name, ',');
            getline(stream, miniFigStr, ',');
            miniFigs = stoi(miniFigStr);

            getline(stream, piecesStr, ',');
            pieces = stoi(piecesStr);

            getline(stream, usPriceStr);
            usPrice = stod(usPriceStr);   //stod Reference from C++ library

            //3. construct an object from the data
            Legos l(number, theme, name, miniFigs, pieces, usPrice);
            legos.push_back(l);  //store data
        }
    }
}


int main(){

    vector<Legos> legos;

    unsigned int index = 0;
    int totalPieces = 0;
    int numSets = 0;
    int numMini = 0;
    double totalPrice = 0.00;


    cout << std::fixed << setprecision(2);

    /*
    cout << "Which file(s) to open?\n";
    cout << "1. lego1.csv" << endl;
    cout << "2. lego2.csv" << endl;
    cout << "3. lego3.csv" << endl;
    cout << "4. All 3 files" << endl;

*/
    int option;
    cin >> option;

    /*======= Load data from file(s) =======*/
    if(option == 1){
        getData("lego1.csv", legos);
    }
    if(option == 2){
        getData("lego2.csv", legos);
    }
    if(option == 3){
        getData("lego3.csv", legos);
    }
    if(option == 4){
        getData("lego1.csv", legos);
        getData("lego2.csv", legos);
        getData("lego3.csv", legos);
    }


/*
    cout << "1. Most Expensive set" << endl;
    cout << "2. Largest piece count" << endl;
    cout << "3. Search for set name containing..." << endl;
    cout << "4. Search themes..." << endl;
    cout << "5. Part count information" << endl;
    cout << "6. Price information" << endl;
    cout << "7. Minifigure information" << endl;
    cout << "8. If you bought one of everything..." << endl;
    cout << "0. Exit" << endl;
*/

    int choice;
    cin >> choice;
    cin.get();  // Clear newline character for any later input

    numSets = legos.size();  //get number of sets

    /*======= Print out how many sets were loaded =======*/
    cout << "Total number of sets: " << numSets << endl << endl;


    /*======= Based on the choice, execute the appropriate task and show the results =======*/

    //Referece for writing for loops: Prof. Fox's Reading Complex data using ifstream lecture; Zybooks: 6.4

    //Most Expensive set
    if(choice == 1){

        //iterate through the list
        for(unsigned int i = 0; i<legos.size(); i++){

            //if price at index is greater than the price at next index
            if(legos[i].getUSPrice() > legos[i+1].getUSPrice()){
                index = i;  //store index
            }
        }
        cout << "The most expensive set is: " << endl;
        legos[index].Display();
    }


    //Largest piece count
    if(choice == 2){

        int currentPiece = 0;

        //iterate through the list to get the largest piece count
        for(unsigned int i = 0; i<legos.size(); i++){

            //if current piece is smaller than the piece at index
            if(currentPiece < legos[i].getPieces()){
                currentPiece = legos[i].getPieces();   //store current piece to piece at current index
            }
        }

        //iterate through the list to get the index at which the larget piece count is
        for(unsigned int i = 0; i<legos.size(); i++){

            //if the largest piece count value matches the piece count at current index
            if(currentPiece == legos[i].getPieces()){
                index = i;  //save as index
            }
        }

        cout << "The set with the highest parts count: " << endl;
        legos[index].Display();
    }

    //Search for set names containing..
    if(choice == 3){

        string input;
        getline(cin, input);   //get input

        int count = 0;
        string name;

        //iterate through the list to find if the set names contain the inputed term
        for(unsigned int i = 0; i<legos.size(); i++){

            //store current set name
            name = legos[i].getName();
            size_t found = name.find(input);  //find reference: TA Alexis Daugthery, Zybooks Reference: 4.5

            if(found != string::npos){   //if term found; Reference: TA Alexis Daugthery
                count++;   //increment counter
            }
        }

        //if counter is less than 1
        if(count < 1){

            //list does not contain the term
            cout << "No sets found matching that search term" << endl;
        }

        else {
            cout << "Sets matching " << "\"" << input << "\":" << endl;

            //iterate through list to find the sets with the inputed term
            for (unsigned int i = 0; i < legos.size(); i++) {

                //store current set name
                string names = legos[i].getName();

                //find index of term
                size_t founds = names.find(input);  //find reference: TA Alexis Daugthery, Zybooks Reference: 4.5

                if (founds != string::npos) {  //if set name contains the inputed term; Reference: TA Alexis Daugthery
                    legos[i].displayN();  //print set
                }
            }
        }
    }

    //Search for set themes containing...
    if(choice == 4){

        string input;
        getline(cin, input);  //get input

        int count = 0;
        string name;

        //iterate through the list to find if the set theme contain the inputed term
        for(unsigned int i = 0; i<legos.size(); i++){

            //store current set theme
            name = legos[i].getTheme();
            size_t found = name.find(input); //find reference: TA Alexis Daugthery, Zybooks Reference: 4.5

            if(found != string::npos){  //if term found; Reference: TA Alexis Daugthery
                count++;  //increment counter
            }
        }

        //if counter is less than 1
        if(count < 1){

            //list theme does not contain input term
            cout << "No sets found matching that search term" << endl;
        }
        else {
            cout << "Sets matching " << "\"" << input << "\":" << endl;

            //iterate through list to find the sets with the inputed term
            for (unsigned int i = 0; i < legos.size(); i++) {

                //store current set theme
                string names = legos[i].getTheme();

                //find index of term
                size_t founds = names.find(input);  //find reference: TA Alexis Daugthery, Zybooks Reference: 4.5

                if (founds != string::npos) {  //if set theme contains the inputed term; Reference: TA Alexis Daugthery
                    legos[i].displayN();   //print list
                }
            }
        }
    }

    //Part count information
    if(choice == 5) {

        //iterate through the list to add the total number of pieces. Reference: Prof. Fox's Reading Complex data using ifstream lecture
        for(unsigned int i =0; i <legos.size(); i++){
            totalPieces += legos[i].getPieces();
        }

        //divide total number of pieces by total number of sets
        int averagePiece = totalPieces / numSets;

        cout << "Average part count for " << numSets << " sets: " << averagePiece << endl;
    }

    //Price information
    if(choice == 6){
        double totPrice = 0.00;

        //iterate through the list to add the total price. Reference: Prof. Fox's Reading Complex data using ifstream lecture
        for(unsigned int i =0; i <legos.size(); i++){
            totPrice += legos[i].getUSPrice();
        }

        //divide total price by number of sets to get average price
        double averagePrice = totPrice / numSets;
        cout << "Average price for " << numSets << " sets: $" << averagePrice << endl << endl;

        double currentPrice = 0.00;

        //iterate throught he list to find the lowest price
        for(unsigned int i = 0; i<legos.size(); i++){

            if(i==0){  //assign current price as price at index 0
                currentPrice = legos[i].getUSPrice();
            }
            else{
                //if current price is greater than the price at current index
                if(currentPrice > legos[i].getUSPrice()){
                    currentPrice = legos[i].getUSPrice();  //assign current price to price at current index
                }
            }
        }

        //interate through the list to find the index which contains the lowest price
        for(unsigned int i = 0; i<legos.size(); i++){

            //if the lowest price matches the price at the current index and if the number of pieces is smaller than the previous index
            if(currentPrice == legos[i].getUSPrice() && legos[i].getPieces() < legos[i-1].getPieces()){
                index = i;  //save current index
            }
        }

        cout << "Least expensive set: " << endl;
        legos[index].Display();   //print set at current index

        //iterate throught he list to find the greatest price
        for(unsigned int i = 0; i<legos.size(); i++){

            if(i==0){ //assign current price as price at index 0
                currentPrice = legos[i].getUSPrice();
            }
            else{

                //if current price is smaller than the price at current index
                if(currentPrice < legos[i].getUSPrice()){
                    currentPrice = legos[i].getUSPrice(); //assign current price to price at current index
                }
            }
        }

        //interate through the list to find the index which contains the greatest price
        for(unsigned int i = 0; i<legos.size(); i++){

            //if the lowest price matches the price at the current index
            if(currentPrice == legos[i].getUSPrice()){
                index = i;  //save current index
            }
        }

        cout << endl;
        cout << "Most expensive set:" << endl;
        legos[index].Display();

    }

    //Minifigure information
    if(choice == 7){

        //iterate through the list to add the total minifigs. Reference: Prof. Fox's Reading Complex data using ifstream lecture
        for(unsigned int i =0; i <legos.size(); i++){
            totalPieces += legos[i].getMiniFigs();
        }

        //divde total number of minifigs by total number of set to find average number of minifigs
        int averageMinifigs = totalPieces / numSets;

        cout << "Average number of minifigures: " << averageMinifigs << endl << endl;

        int currentPiece = 0;

        //iterate through the list to find the greatest number of minifigs
        for(unsigned int i = 0; i<legos.size(); i++){

            //if current number of minifigs is smaller than the current number of minifigs at the index
            if(currentPiece < legos[i].getMiniFigs()){
                currentPiece = legos[i].getMiniFigs(); //assign current number of minifigs to the number at current index
            }
        }

        //iterate though the list to find the index at which the greatest number of minifigs is
        for(unsigned int i = 0; i<legos.size(); i++){

            //if the greatest number of minifigs matches the number at current index
            if(currentPiece == legos[i].getMiniFigs()){
                index = i; //save index
            }
        }
        cout << "Set with the most minifigures: " << endl;
        legos[index-1].Display();
    }

    //If you bought one of everything...
    if (choice == 8){
        cout << "If you bought one of everything..." << endl;

        //iterate through the list to find the total price, total number of minifigs, and total number of pieces
        //Reference: Prof. Fox's Reading Complex data using ifstream lecture
        for( unsigned int i = 0; i < legos.size(); i++){
            totalPrice += legos[i].getUSPrice();
            numMini += legos[i].getMiniFigs();
            totalPieces += legos[i].getPieces();
        }

        cout << "It would cost: $" << totalPrice << endl;
        cout << "You would have " << totalPieces << " pieces in your collection" << endl;
        cout << "You would have an army of " << numMini << " minifigures!" << endl;
    }

    if(choice == 0){
        return 0;
    }


    return 0;
}