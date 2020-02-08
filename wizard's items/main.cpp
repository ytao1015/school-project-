//  main.cpp
//  wizardItems
//  Created by Yi Tao on 2/2/20.
//  Copyright © 2020 Yi Tao. All rights reserved.
/* This project is to use the file which named wizard_all_items.txt as a
 * base to let the user be the wizard to pick up the treasures that
 * they want to carry. Every wizard can only carry 4 items. User can
 * use show to check the whole bag and exit to exit the game*/

#include <iostream>
#include "wizardInventory.hpp"


using namespace std;
using namespace wizardInventory;

int main() {

    cout << "Wizard Inventory" << endl;
        
    cout << "COMMAND MENU" <<endl
    << "walk - Walk down the path" <<endl
    << "show - Show all items" << endl
    << "drop - Drop an item " << endl
    << "exit - Exit program" << endl;
    
    string command;

    while (true)
    {
        cout << "Command: ";
        cin >> command;
    
        if(command == "walk")
        {
            walk();
            
        }
        else if (command == "show")
        {
            show();
        
        }
        else if (command == "drop")
        {
            drop();
        }
        else if (command == "exit")
        {
            exit();
            break;
        }
        else
        {
            cout << "Wrong command. Try again! " << endl;
        }
 
    }
    return 0;
}
