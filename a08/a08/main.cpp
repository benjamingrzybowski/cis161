//
//  main.cpp
//  a08
//
//  Created by Ben Grzybowski on 12/2/18.
//  Copyright © 2018 Admin. All rights reserved.
//  This program will read from a tempurature data file, insert the data into a struct, then it output the highest and lowest tempuratures of the year based on the data in the file.
//  No outside resources required.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//constants
const int CAP = 100;
const int MAXCHAR = 101;

//define struct
struct Tempurature {
    string month;
    double highTemp;
    double lowTemp;
};
//define functions
void openFile(ifstream &inFile);
void loadData(ifstream &inFile, Tempurature temps[], int &size);
Tempurature averageHigh(Tempurature temps[], int size);
Tempurature averageLow(Tempurature temps[], int size);

int main() {
    
    Tempurature monthlyTemps[CAP];
    Tempurature highTemp;
    Tempurature lowTemp;
    int size = 0;
    ifstream inputFile;
    openFile(inputFile);
    loadData(inputFile, monthlyTemps, size);
    highTemp = averageHigh(monthlyTemps, size);
    lowTemp = averageLow(monthlyTemps, size);
    cout << "The high temp of the year was in the month of " << highTemp.month << " at a tempurature of " << highTemp.highTemp << endl;
    cout << "The low temp of the year was in the month of " << lowTemp.month << " at a tempurature of " << lowTemp.lowTemp << endl;
    return 0;
}
//open file
void openFile(ifstream &inFile){
    char fileName[MAXCHAR];
    cout << "Enter the path of the File to open: ";
    cin.getline(fileName, MAXCHAR);
    //ignores enter key when the user presses it, otherwise it sits in buffer and will cause issues
    cin.ignore(100, '\n');
    inFile.open(fileName);
    if(!inFile) {
        cout << "terminating program, invalid file path";
        exit(0);
    }
}
//read from file into struct array
void loadData(ifstream &inFile, Tempurature temps[], int &size) {
    int i = 0;
    while(!inFile.eof()){
        inFile >> temps[i].month >> temps[i].highTemp >> temps[i].lowTemp;
        i ++;
    }
    size = i;
}
//find the highest tempurature and cooresponding month
Tempurature averageHigh(Tempurature temps[], int size){
    int currentHigh = 0;
    int month = 0;
    for(int x = 0; x < size; x++) {
        if (temps[x].highTemp > currentHigh) {
            currentHigh = temps[x].highTemp;
            month = x;
        }
    }
    return temps[month];
}
//find the lowest tempurature and cooresponding month
Tempurature averageLow(Tempurature temps[], int size){
    int currentLow = 0;
    int month = 0;
    currentLow = temps[0].lowTemp;
    for(int x = 0; x < size; x++) {
        if (temps[x].lowTemp < currentLow) {
            currentLow = temps[x].lowTemp;
            month = x;
        }
    }
    return temps[month];
}
