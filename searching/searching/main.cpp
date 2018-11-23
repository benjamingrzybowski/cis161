//
//  main.cpp
//  searching
//
//  Created by Admin on 11/21/18.
//  Copyright © 2018 Admin. All rights reserved.
//
// Search for a number in an array

#include <iostream>
using namespace std;

bool search(int list[], int MAX);

int main() {

    int CAP = 10, list[CAP], x;
    char opt;
    
    cout << "enter list numbers: ";
    for (x = 0; x < CAP; x++) {
        cin >> list[x];
    }
    
    cout << "the numbers you listed: " << endl;
    for (x = 0; x < CAP; x++) {
        cout << list[x] << " ";
    }
    
    do {
        if (search(list, CAP) == true) {
            cout << "Number Found" << endl;
        } else {
            cout << "Number not found" << endl;
        }
        cout << "cotinue searching? (y/n): ";
        cin >> opt;
    } while (tolower(opt) == 'y');
}

bool search(int list[], int MAX) {
    int searchNum = 0, x = 0;
    cout << "enter number to search for: ";
    cin >> searchNum;
    for (x = 0; x < MAX; x++) {
        if (list[x] == searchNum) {
            return true;
        }
    } return false;
}

