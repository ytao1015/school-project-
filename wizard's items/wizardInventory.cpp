//  wizardInventory.cpp
//  wizardItems
//
//  Created by Yi Tao on 2/2/20.
//  Copyright © 2020 Yi Tao. All rights reserved.
//

#include "wizardInventory.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;



namespace wizardInventory
{
int count = 0;
// walk function
     void walk(){
        string fileName = "wizard_all_items.txt";
        string ofileName = "wizard_items.txt";
        vector <string> allItems;
        vector <string> items;
        int second = time(0);
        srand(second);
        int i;
    //    int r = 0;
         
        // set up a read stream
        ifstream inputFile(fileName);//open the file
        if(inputFile.is_open()) //if the file is open
        {
            string line;
  //          cin.ignore();
            while (!inputFile.eof()) // while it is not the end of the file
            {
                getline(inputFile,line);
                
             //   cout << line << endl;
       //         cout << "Before add line"<< allItems.size()<<endl;
                allItems.push_back(line);  //read file into vector items.
      //          cout << "After add line" << allItems.size()<<endl;
     //           cout << allItems[r]<<endl;
     //           r++;
            }
                  
        }
            inputFile.close();
               // get a random number between 0-3
            i = rand() % (allItems.size()-1);
         //why the allItem.size  = 10?
     //         cout << allItems.size() << endl;
         // set up a vector to take the user's grab thing
        char choice;
      
        cout<<"While walking down a path, you see " << allItems[i] <<"." << endl<< "Do you want to grab it?(y/n): ";
        cin >> choice;
        if(tolower(choice) == 'y' )
        {
            //build the file
            ofstream outputFile;
            outputFile.open(ofileName,ios::app);
            
            //read the output file
            ifstream inputFile2;
            inputFile2.open(ofileName);
            if(inputFile2) //if the file is open
            {
               string line2;
                while (!inputFile2.eof()) // while it is not the end of the file
                {
                        getline(inputFile2,line2);
                        items.push_back(line2);
                }
                            
            
                if( items.size()<=4) // check if the output file have 4 items in there
                {
           
                    if(outputFile)
                    {
                       outputFile << allItems[i] <<endl;
                
                    }
                }
                else
                {
                    cout << "Your pakage is full"<<endl;
                }
        }
            outputFile.close();
            inputFile2.close();
        }
         
       
    }
    // show function read from the file wizard_items.txt
    void show()
    {
        string ofileName = "wizard_items.txt";
        string line;
        int i = 1;
        ifstream input_file;
        input_file.open(ofileName);
        if(input_file){
            while(getline(input_file,line))
            {
                cout << i << "." << "\t" << line << endl;
                i++;
            }
           
        }
        input_file.close();
    }
//drop function
    void drop()
    {
        //read the 4 items into a vector "items"
        string ofileName = "wizard_items.txt";
        string line;
        vector <string> items;
        int number,i;
        
        //open the file "Wizard_items.txt"
        ifstream input_file;
        input_file.open(ofileName);
        
        if(input_file){
            while(getline(input_file,line))
            {
                items.push_back(line);
                       
            }
            input_file.close();
        }
       // for(i = 0; i<4;i++)
        //{
          //  cout << items[i] << endl;
          //  cout <<"I am here"<<endl;
       // }
        
        cout << "which one you want to drop?";
        cin >> number;
       if( number <= items.size() )
       {
           cout << "You droped " << items[number-1] << "." << endl;
           
           items. erase(items.begin()+number-1);
        
     //      for(i = 0; i<4;i++)
       //        {
         //          cout << items[i] << endl;
                
           //    }
      //     cout << items.size();
        
           ofstream outputFile;
           outputFile.open(ofileName);
        
           if(outputFile)
           {
            for(i = 0; i<items.size();i++)
            outputFile << items[i]<< endl;
           }
       }
       else
       {
           cout << "Your pick is out of range."<<endl;
       }
        
        
    }

//exit function
    void exit()
    {
      
        cout << "Bye!" << endl;
    }

}

