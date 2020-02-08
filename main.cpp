//  Created by Yi Tao on 1/26/20.
//  Copyright © 2020 Yi Tao. All rights reserved.
//
/* This program is to analyse the strength of the password:A hard password
 * has at least 4 digits, at least 3 punctuation characters, and at least
 * 8 letters of the alphabet of which at least 2 are uppercase.
 * A medium password has at least 2 digits, at least 1 punctuation character,
 * and at least 5 letters of the alphabet of which at least 1 is uppercase.
 * All other passwords are weak.*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string password;
    int count_punct = 0,count_digits = 0,count_alpha = 0,count_uppercase = 0;
    cout << "Password Analyzer"<< endl << endl
    << "Enter password:  ";
    cin  >> password;
    cout << endl;
    
    for(char c : password)
    {
        if(isdigit(c))
            count_digits++;
        else if(isalpha(c)){
            count_alpha++;
            if(isupper(c))
                count_uppercase++;
        }
        else
            count_punct++;
    }
    
    if(count_digits >=4 && count_punct >=3 && count_alpha >=8 && count_uppercase >=2)
        cout << "Strength: Hard" << endl << endl;
    else if(count_digits >=2 && count_punct >=1 && count_alpha >=5 && count_uppercase >=1)
        cout<< "Strength: Medium" << endl <<endl;
    else
        cout<<"Strength: Weak" << endl << endl;
    
    cout << "Bye!" << endl << endl ;
    
    
    
    return 0;
}
