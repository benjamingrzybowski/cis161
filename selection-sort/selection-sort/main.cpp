//
//  main.cpp
//  selection-sort
//
//  Created by Admin on 11/22/18.
//  Copyright © 2018 Admin. All rights reserved.
//
// Sort an array with smallest first, also has code for largest first commented out

#include <iostream>

using namespace std;

void square();

void sorting(int list[]);

const int MAX = 10;

int main() {

    int list[MAX] = {12, 14, 56, 89, 87, 98, 32, 45, 82, 73}, x;
    
    cout << "Unsorted list" << endl;
    for (x = 0; x < MAX; x++) {
        cout << list[x] << " ";
    }
    cout << endl;
    cout << "sorted list: " << endl;
    sorting(list);
    for (x = 0; x < MAX; x++) {
        cout << list[x] << " ";
    }
}

void sorting(int list[]) {
    int smallIndex = 0, loc = 0, temp = 0, i;
    
    for (i = 0; i < MAX - 1; i++) {
        //find smallest number in list
        smallIndex = i;
        for (loc = i + 1; loc < MAX; loc++) {
        //smallest to largest
            if(list[loc] < list[smallIndex]) {
                smallIndex = loc;
            }
        //largest to smallest
            //if(list[smallIndex] < list[loc]) {
            //smallIndex = loc;
        //}
        //swap numbers i and smallIndex
            temp = list[smallIndex];
            list[smallIndex] = list[i];
            list[i] = temp;
        }
    }
}


//pattern making function
void square () {
    int x = 10, y = 8, i, j;
    
    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
