//
//  main.cpp
//  Ep-1
//
//  Created by Yi Tao on 2/17/20.
//  Copyright © 2020 Yi Tao. All rights reserved.
//This project is to gather user input to construct player character
//builds for a role-player game(RPG)

#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>
#include <cstdlib>

enum class player_class {Mega, Warrior, Bowman, Thief};
using namespace std;
struct players{
    string name;
    player_class playerClasses;
//    string classes;
    string sex;
    int gold;
};

void show ();
void add ();
void deletePlayer();
player_class toEnum(const string& str);
string toString(player_class v);

const string fileName = "players.txt";
int main() {
    string command;
    cout << "RPG Start Screen"<<endl;
    cout << "COMMAND MENU" <<endl;
    cout << "show   - Display all players" <<endl
         << "add    - Add a player" << endl
         << "delete - Delete a player" << endl
         << "exit   - Exit program" << endl;
    
    cout << "Command: ";
    cin >> command;
    while(command != "exit")
    {
        if(command == "show")
        {
            show();
        }
        else if(command == "add")
        {
            add();
        }else if(command == "delete")
        {
            deletePlayer();
        }
        cout << "Command: ";
        cin >> command;
    }
}

// show the players in file
void show()
{
    vector <players> playerList;
    struct players player;
    string name;
    string classes;
    string sex;
    // int gold;
    string temp;
    
    ifstream infile(fileName);
    if(infile.fail())
    {
        cout << "Error opening players.txt";
    }
    string line;
  while (getline(infile,line))
  {
        stringstream ss(line);
        
        getline(ss, name,'\t');
        player.name =name;
        
       getline(ss, classes,'\t');
 //       player.classes = classes;
        player.playerClasses = toEnum(classes);
 //      cout << classes<<"|"<< toString(player.playerClasses)<<endl;
        getline(ss, sex, '\t');
        player.sex = sex;
        
        getline(ss,temp,'\t');
        player.gold = stoi(temp);
        playerList.push_back(player);
    }
    //对于有不同数据类型的文件， 可以用getline去分解 对 每个 数据类型的处理
    
  /*  while(infile >> name >> classes >> sex >> gold)
    {
         player.name =name;
         player.classes = classes;
         player.sex = sex;
         player.gold = gold;
         playerList.push_back(player);
    }*/
 //   cout << playerList.size();
    for (int i =0 ; i<playerList.size(); i++)
    {
        cout << left << i+1 << "." << setw(10) << playerList[i].name <<setw(10)<< toString(playerList[i].playerClasses) << setw(5) << playerList[i].sex << setw(5) << playerList[i].gold <<endl;
    }
    infile.close();
}

//add player to the file
void add()
{
    string name;
    string classes;
    char sex;
    int gold;
    
    cout << "Creat a Mage, Warrior, Bowman, or Thief" <<endl;
    cout << "Name: ";
    cin >> name;    //cin会保留name的数据
    cin.clear();
    cout << "classes:";
    cin >> classes;
    cin.clear();
   // 这里注意 要用cin.clear(); 去清除cin里面的classes。
    while(true)
    {
        if(classes == "Mage" || classes == "Warrior" || classes == "Bowman" ||classes == "Thief")
        {
            break;
        }
        else
        {
            cout << " Invalid class, try agian"<<endl;
            cout << "Classes: ";
            cin >> classes;
            cin.clear();
        }
    }
    
    cout << "sex: ";
    cin >>sex;
    cin.clear();
    cout << "gold: ";
    cin >> gold;
    cin.clear();
    
    ofstream ofile(fileName,ios::app);
//    ofile << "\n";
    ofile <<name <<"\t"<<classes <<"\t"<<sex << "\t" <<gold << endl;
    ofile.close();
}

//delter Player from the file and re- read in the new players in file
void deletePlayer()
{
      vector <players> playerList;
       struct players player;
       string name,classes;
       string sex;
//       int gold;
       string temp;
       string line;
    int num;
       ifstream infile(fileName);
       if(infile.fail())
       {
           cout << "Error opening players.txt";
       }
       
    while (getline(infile,line))
     {
           stringstream ss(line);
           
           getline(ss, name,'\t');
           player.name =name;
           
          getline(ss, classes,'\t');
    //       player.classes = classes;
           player.playerClasses = toEnum(classes);
         
           getline(ss, sex, '\t');
           player.sex = sex;
           
           getline(ss,temp,'\t');
           player.gold = stoi(temp);
           playerList.push_back(player);
       }
    infile.close();
    
    cout << "Which one you want to drop?(choose a numeber): ";
    cin >> num;
    cin.clear();
    
    while(num < 1 || num >playerList.size())
    {
        cout << "Out of Range. Try Again!";
        cout << "Which one you want to drop?(choose a numeber): ";
        cin >> num;
        cin.clear();
    }
    
    playerList.erase(playerList.begin()+num-1);
    ofstream ofile(fileName, ios::trunc);
    for(int i =0; i<playerList.size(); i++)
    {
        ofile << playerList[i].name <<"\t"<<toString(playerList[i].playerClasses) <<"\t"<<playerList[i].sex << "\t" <<playerList[i].gold<<"\n";
    }
    ofile.close();
}

//convert string to enum type
player_class toEnum(const string& str)
{
    if(str == "Mage")
        return player_class::Mega;
    else if(str == "Warrior")
        return player_class::Warrior;
    else if(str == "Bowman")
        return player_class::Bowman;
    else
        return player_class::Thief;
    // 如果只用else if 这里会报错： control may reach end of non-void function。要用else，return。
}

// convert enum type to string
string toString(player_class v)
{
    switch(v)
    {
        case player_class::Mega: return "Mage"; break;
        case player_class::Warrior: return "Warrior"; break;
        case player_class::Bowman: return "Bowman"; break;
        case player_class::Thief:return "Thief"; break;
       
    }
}
