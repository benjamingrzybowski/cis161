//
//  main.cpp
//  reverse-string
//
//  Created by Admin on 11/22/18.
//  Copyright © 2018 Admin. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//global variables
int MAX = 101;

int getLen(char list[]);

int main() {
    
    char list1[MAX];
    string name = "Ben Grzybowski";
    int y, len;
    //how to use strcpy, cannot put variables as second parameter, causes an error
    strcpy(list1, "testing");
    
    cout << "enter a message: ";
    cin.get(list1, MAX);
    cout << "the length of your message is: " << getLen(list1) << endl;
    
    len = getLen(list1);
    
    for (y = len - 1; y >= 0; y--) {
        cout << list1[y];
    }
    
    return 0;
}


int getLen(char list[]) {
    int x = 0;
    while (list[x] != '\0') {
        x++;
    } return x;
}
