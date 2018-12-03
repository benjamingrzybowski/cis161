//
//  main.cpp
//  final-program
//
//  Created by Admin on 12/2/18.
//  Copyright © 2018 Admin. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

//constants
const int CAP = 100;
const int MAXCHAR = 101;

//structs

struct inventoryType {
    string modelNo;
    string binNo;
};


//function prototypes
void openFile(ifstream &inFile);
void displayMenu();
char readInput();
void exeCommand(char option, inventoryType storeroom[], int size);
int readData(ifstream &inFile, inventoryType storeroom[]);
void searchModel(inventoryType storerom[], int size);
void searchBin(inventoryType storeroomp[], int size);
void outputData(inventoryType storeroom[], int size);

int main() {
    inventoryType storeRoom[CAP];
    int size = 0;
    char option;
    ifstream inFile;
    openFile(inFile);
    size = readData(inFile, storeRoom);
    outputData(storeRoom, size);
    do{
        displayMenu();
        option = readInput();
        exeCommand(option, storeRoom, size);
    } while(tolower(option) != 'q');
    return 0;
}
//open file
void openFile(ifstream &inFile){
    char fileName[MAXCHAR];
    cout << "Enter the path of the File to open.";
    cin.getline(fileName, MAXCHAR);
    //ignores enter key when the user presses it, otherwise it sits in buffer and will cause issues
    cin.ignore(100, '\n');
    inFile.open(fileName);
    if(!inFile) {
        cout << "terminating program";
        exit(0);
    }
}
//insert data from file to struct array
int readData(ifstream &inFile, inventoryType storeroom[]) {
    int i = 0;
    while(!inFile.eof()){
        inFile >> storeroom[i].modelNo >> storeroom[i].binNo;
        i ++;
    }
    return i;
}
//output data from struct array
void outputData(inventoryType storeroom[], int size){
    for (int i = 0; i < size; i++) {
        cout << setw(10) << storeroom[i].modelNo << endl;
        cout << setw(10) << storeroom[i].binNo << endl;
    }
}
//display meny for user
void displayMenu(){
    cout << "Pick An Option Below" << endl;
    cout << "Enter M to search by model number" << endl;
    cout << "Enter B to search by bin number" << endl;
    cout << "Enter Q to quit program" << endl;
}
//read input from user based on options from menu
char readInput(){
    char input;
    cin.get(input);
    cin.ignore(100, '\n');
    return input;
}
//excute the appropriate command based on user input
void exeCommand(char option, inventoryType storeroom[], int size) {
    if(tolower(option) == 'm') {
        searchModel(storeroom, size);
    } else if (tolower(option) == 'b') {
        searchBin(storeroom, size);
    } else if (tolower(option) == 'q') {
        exit(0);
    } else {
        cout << "Incorrect Input Try again";
    }
}
//search by model number
void searchModel(inventoryType storerom[], int size){
    string query;
    bool found = false;
    cout << "enter model number to search for";
    getline(cin, query);
    for (int x = 0; x < size; x++) {
        if (query == storerom[x].modelNo) {
            cout << "Item Found" << endl;
            cout << storerom[x].modelNo << " " << storerom[x].binNo;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "item not found" << endl;
    }
}
//search by bin number
void searchBin(inventoryType storerom[], int size){
    string query;
    bool found = false;
    cout << "enter model number to search for";
    getline(cin, query);
    for (int x = 0; x < size; x++) {
        if (query == storerom[x].binNo) {
            cout << "Item Found" << endl;
            cout << storerom[x].binNo << " " << storerom[x].modelNo;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "item not found" << endl;
    }
}
