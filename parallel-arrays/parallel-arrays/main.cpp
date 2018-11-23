//
//  main.cpp
//  parallel-arrays
//
//  Created by Admin on 11/22/18.
//  Copyright © 2018 Admin. All rights reserved.
//
// Open file, place contents of file into parallel arrays, calculate totals and percentages

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//CONSTANTS

const int MAXCHAR = 101;
const int CAP = 100;


//FUNCTIONS

void openFile(ifstream &inFile);
int readFile(ifstream &inFile, string names[], int votes[]);
void calculateTotal(int size, string names[], int votes[]);



int main() {
    string names[CAP];
    int votes[CAP] = {0};
    int size = 0;
    ifstream inFile;
    //Open file
    openFile(inFile);
    //Read file and add contents to arrays
    size = readFile(inFile, names, votes);
    //Calculate totals and percentages
    calculateTotal(size, names, votes);
}

void openFile(ifstream &inFile) {
    
    char fileName[MAXCHAR];
    cout << "enter file to open: ";
    cin.get(fileName, MAXCHAR);
    
    inFile.open(fileName);
    if(!inFile) {
        cout << "Failed to open file";
        exit(0);
    }
}

int readFile(ifstream &inFile, string names[], int votes[]) {
    
    int size = 0;
    while(!inFile.eof()) {
        inFile >> names[size] >> votes[size];
        size++;
    }
    return size;
}

void calculateTotal(int size, string names[], int votes[]) {
    
    int total = 0, x;
    double percent;
    //gathering the total number of votes
    for (x = 0; x < size; x++) {
        total += votes[x];
    }
    cout << total <<endl;
    //determining percentages of each candidates votes
    for (x = 0; x < size; x++) {
        //note where paratheneses are here: static cast ends at [x]
        percent = (static_cast<double>(votes[x])/total) * 100;
        cout << fixed << showpoint << setprecision(2);
        cout << left << setw(15) << names[x] << " got " << percent << "% of the votes. " << endl;
    }
}
