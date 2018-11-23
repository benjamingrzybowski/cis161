//
//  main.cpp
//  week9
//
//  Created by Admin on 11/21/18.
//  Copyright © 2018 Admin. All rights reserved.
// Find the largest number in an Array
//

#include <iostream>
using namespace std;

int main() {
    
    int CAP = 10;
    int list1[CAP], x, largest;
    
    cout << "Insert Numbers: ";
    for (x = 0; x < CAP; x++) {
        cin >> list1[x];
    }
    
    cout << "You entered the following numbers: " << endl;
    for (x = 0; x < CAP; x++) {
        cout << list1[x] << endl;
    }
    
    largest = 0;
    for (x = 0; x < CAP; x++) {
        if(largest < list1[x]) {
            largest = list1[x];
        }
    }
    cout << "The largest number entered was: " << largest;
    
    
    return 0;
}
