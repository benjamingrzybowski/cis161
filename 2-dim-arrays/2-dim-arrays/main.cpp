//
//  main.cpp
//  2-dim-arrays
//
//  Created by Admin on 11/23/18.
//  Copyright © 2018 Admin. All rights reserved.
//

#include <iostream>

using namespace std;

//constants

const int STUD = 3;
const int QZ = 2;

int main() {
    
    //how a 2 dim array works: array[rows][columns]
    int scores[STUD][QZ];
    
    //gather scores for each student
    for (int i = 0; i < STUD; i++) {
        cout << "Enter score for student " << (i + 1) << ":" << endl;
        for (int x = 0; x < QZ; x++){
            cin >> scores[i][x];
        }
    }
    //print scores out
    for (int i = 0; i < STUD; i++) {
        cout << "Scores for student: " << (i + 1) << ":" << endl;
        for (int x = 0; x < QZ; x++){
            cout << scores[i][x] << " ";
        }
        cout << endl;
    }
    //calculate and print average for each student
    for (int i = 0; i < STUD; i++) {
        int total = 0, average = 0;
        for (int x = 0; x < QZ; x++) {
            total += scores[i][x];
        }
        average = total / QZ;
        cout << "Average for student " << (i + 1) << " : " << average << endl;
    }
    
    return 0;
}
