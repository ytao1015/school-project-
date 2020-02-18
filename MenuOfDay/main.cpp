//  main.cpp
//  MenuOfDay
//
//  Created by Yi Tao on 2/3/20.
//  Copyright © 2020 Yi Tao. All rights reserved.

/* This program is to read the menu.txt file in to the system.
 * And then show the user different day have different menue.
 * The user can typing "exit to exit the system."
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;
    
struct MenuItem{
    string name;
    int price;
    string associatedDay;
};

int main() {
    string fileName = "menu.txt";
    string line;
    string name,day,temp;
    int price;
    
    ifstream infile;
    infile.open(fileName);
    vector<MenuItem> menus;          //vector
    struct MenuItem items;          //struct
    
    if(infile.fail()){
        cout << "Error opening menu file"<< endl;
        return 0;
    }
    // read file into a struct vector
    string priceString;
    while (getline(infile,line)){
        // read file line by line
        stringstream ss(line);
        // use tab as a seperator
        getline(ss, name, '\t');
        getline(ss, priceString, '\t');
        price = stoi(priceString);      // change price type from string to int
        getline(ss,temp,'\t');
        for(int a = 0; a< temp.size();a++)
        {
            if(!isspace(temp[a]))
            {
                day += temp[a];
            }
        }
        //put the items in sturct
        items.name = name;
        items.price = price;
        items.associatedDay = day;
//      cout << day;
        day.clear();
        //put items in to vector menus.
        menus.push_back(items);
    }
    infile.close();
//cout << menus.size()<<endl;

    cout << "Menu of the Day" << endl;
    cout << endl;
    cout << "COMMAND MENU"<<endl;
    cout << "Specify the day using the three-letter format(mon, tue, wed, thu, fri, sat, sun).Or, enter ’exit’ to exit." << endl << endl;
    
    string inputDay;
    int j;
    while(true)
    {
        cout << "Day: " ;
        cin >> inputDay;
    
        if(inputDay != "exit"){
            for (j = 0; j<menus.size();j++)
            {
   //    cout << menus[j].associatedDay;
                if(menus[j].associatedDay == inputDay)
                {
                    cout << left<< setw(18)<< menus[j].name <<right << setw(10)<< menus[j].price <<endl;
                }
            }
        }
        else
        {
            cout << "Bye!";
            break;
        }
    }
 
    return 0;
}

