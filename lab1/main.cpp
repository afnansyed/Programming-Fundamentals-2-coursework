#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

int main(){

    //Prompt the user for a title for data
    string titleForData;
    cout << "Enter a title for the data:" << endl;
    getline(cin, titleForData);
    cout << "You entered: " << titleForData << endl;

    //Prompt the user for the header of columns 1
    string column1;
    string column2;
    cout << "Enter the column 1 header:" << endl;
    getline(cin, column1);
    cout << "You entered: " << column1 << endl;

    //Prompt the user for the header of columns 2
    cout << "Enter the column 2 header:" << endl;
    getline(cin, column2);
    cout << "You entered: " << column2 << endl;

    //declare variables
    vector<string> dataString;
    vector<int> dataInteger;
    string dataPoint;
    int comma = 0;
    int secondComma = 0;
    string firstString;
    string secondString;
    int number = 0;

    while(dataPoint != "-1") {

        //Prompt the user for data points
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, dataPoint);

        if (dataPoint == "-1"){ //if user inputs -1, break loop
            break;
        }

        comma = dataPoint.find(','); //find position of comma in the data point. Reference: Zybooks textbook 4.5 and T.A explaination in lab session

        //Perform error checking for the data point entries
        if(comma == string:: npos){   //If entry has no comma. Reference: T.A explaination in lab session
            cout << "Error: No comma in string." << endl;
        }

        firstString = dataPoint.substr(0,comma); //save first half of the data point in a string. Reference: Zybooks textbook 4.5
        secondString = dataPoint.substr(comma + 1);  //save second half of the data point in a second string. Reference: T.A explaination in lab session

        secondComma = secondString.find(','); //find if there is another comma in the second string
        if(secondComma != string::npos){ //if there is a comma in the second string, output error
            cout << "Error: Too many commas in input." << endl;
        }

        else if(comma != string::npos){ //if there is no more commas
            try {
                number = stoi(secondString); //convert string to int using try/catch. Reference: Zybooks textbook 15.1 and T.A explaination in lab session

                cout << "Data string: " << firstString << endl;
                cout << "Data integer: " << number << endl;

                dataString.push_back(firstString); //save first half of the data point in a vector string
                dataInteger.push_back(number); //save second half of the data point in a vector int

            }
            catch (invalid_argument &e) {
                cout << "Error: Comma not followed by an integer." << endl; //if stoi throws an invalid argument, output error
            }
        }

    }

    //print out formatted table titles. Reference: Zybooks textbook 12.1
    cout << endl;
    cout << setw(33) << right << titleForData << endl;
    cout << setw(20) << left << column1 << "|";
    cout << setw(23) << right << column2 << endl;
    cout << "--------------------------------------------" << endl;

    //print out data points into formatted table. Reference: Zybooks textbook 12.1 and T.A explaination in lab session
    for(int i = 0; i < dataString.size(); i++){
        cout << setw(20) << left << dataString[i] <<"|";
        cout << setw(23) << right << dataInteger[i] << endl;
    }

    cout << endl;

    //print out data points as a formatted histogram. Reference: Zybooks textbook 12.1 and T.A explaination in lab session
    for(int i = 0; i < dataString.size(); i++) {
        cout << setw(20) << right << dataString[i] << " ";
        for(int j =0; j < dataInteger[i]; j++){
            cout << "*" ;
        }
        cout << endl;
    }

    return 0;
}