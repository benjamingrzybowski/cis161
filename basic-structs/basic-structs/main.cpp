//
//  main.cpp
//  basic-structs
//
//  Created by Admin on 12/1/18.
//  Copyright © 2018 Admin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
//declaring a structure and defining it's properties
//declare structs to be used in other structs before they are used
struct Address {
    string street;
    string houseNum;
    string city;
    string state;
    string zip;
};

struct Date {
    int day;
    int month;
    int year;
};
//notice nested structs Address and Date
struct StudentType {
    string fname;
    string lname;
    string stdID;
    Address studAdd;
    Date joinDate;
    Date quitDate;
    double gpa;
};

int main(int argc, const char * argv[]) {
//create new instances of the above defined struct
    StudentType pcc, psu;
 
    cout << "enter first name";
    getline(cin, pcc.fname);
    cout << "enter last name";
    getline(cin, pcc.lname);
    cout << "enter id";
    getline(cin, pcc.stdID);
    cout << "enter city";
    getline(cin, pcc.studAdd.city);
    cout << "enter state";
    getline(cin, pcc.studAdd.state);
    cout << "enter house number";
    getline(cin, pcc.studAdd.houseNum);
    cout << "enter street name";
    getline(cin, pcc.studAdd.street);
    cout << "enter join date (m/d/y)";
    cin >> pcc.joinDate.month;
    cin >> pcc.joinDate.day;
    cin >> pcc.joinDate.year;
    cout << "enter GPA";
    cin >> pcc.gpa;
    
    pcc = psu;

    cout << psu.fname << " " << psu.lname << " " << psu.stdID << " " << psu.joinDate.day << "/" << psu.joinDate.month << "/" << psu.joinDate.year << " " << psu.gpa; 
    
    return 0;
}
