//  main.cpp
//  CalculateSale
//
//  Created by Yi Tao on 2/2/20.
//  Copyright © 2020 Yi Tao. All rights reserved.
/* This program is to read a txt file to show the
 * user monthly sales and afford yearly summary of the sale.
 */

#include <iostream>
#include <fstream>

using namespace std;
int main() {
    char letter;
    string filename = "monthly_sales.txt";
    
    cout << "Monthly Sales" << endl << endl;
    cout << "COMMAND MENU" << endl;
    cout << "m - View monthly sales" << endl
         << "y - View yearly summary" <<endl
         << "x - Exit program" << endl << endl;
    // ger user's command
    while (true)
    {
        
        cout << "Command: ";
        cin  >> letter;
        if( tolower(letter) == 'm')
         {
            ifstream  input_file;
            input_file.open(filename);
             string monthes;
             double quantity;
             
            if(input_file)
            {
                cout << "\nMONTHLY SALES" << endl;
                cout << right << fixed << setprecision(2);
                while (input_file >> monthes >> quantity)
                {
                     cout << monthes << setw(15) << quantity <<'\n';
                }
                input_file.close();
            }
                
            continue;
                    
            }
            else if (tolower (letter) == 'y')
            {
                ifstream  input_file;
                input_file.open(filename);
                string monthes;
                int total_monthes = 0;
                double average;
                double total = 0.0;
                double quantity;
                if(input_file)
                {
                    cout << "\nYEARLY SUMMARY" << endl ;
                    while(input_file >> monthes >> quantity)
                    {
                        total += quantity;
                        total_monthes++;
                    }
                    average = total / total_monthes;
                    cout << fixed << setprecision(2);
                    cout <<"Yearly total:     " << right <<setw(14)<< total << endl;
                    cout <<"Monthly average:  " << right<< setw(14)<< average << endl;
                }
                continue;
            }
            else if(tolower(letter) == 'x')
            {
                cout << "\nBye!" << endl <<endl;
                break;
                
            }
            else
            {
                cout << "\nInvalid command. Try again."<< endl ;
                continue;
                
            }
        

    }
    return 0;
}
