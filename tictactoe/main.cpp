//  Created by Yi Tao on 2/14/20.
//  Copyright © 2020 Yi Tao. All rights reserved.
/* This project is a two_player Tic Tac Toe game.  I will use an arrya of STL arrays to store the Tic Tac toe grid. And le the user picks an invalid row or collowmn or a cell that's arlready taken, display an error message. If thre is a winner, the game should display a message and end.  */

#include <iostream>
#include <stdlib.h>
#include <array>
#include <typeinfo>

using namespace std;

void printBoard();
void playerInput();
bool checkWin();

char turn;
bool draw;
char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

int main() {
    cout << "Welcome to Tic Tac Toe"<<endl;
    turn = 'X';
    
    while (!checkWin())
    {
        printBoard();
        playerInput();
        checkWin();
    }
    if( turn == 'O' && !draw)
    {
        printBoard();
        cout << "X Wins! "<< endl << "Game Over!" << endl;
    }
    else if(turn == 'X' && !draw)
    {
        printBoard();
        cout << "O Wins!"<<endl << "Game Over !"<<endl;
    }
    else
    {
        printBoard();
        cout <<"It's a draw! Game over"<<endl;
    }
    
    return 0;
}

// print how the board of the tic tac toe
void printBoard()
{
    cout << "+---+---+---+" << endl ;
  //  cout << "|     |     |      |" << endl;
    cout << "| "<<board[0][0] << " | " << board[0][1] << " | " << board[0][2]<< " | " <<endl;
    cout << "+---+---+---+" << endl;
    cout << "| "<<board[1][0] << " | " << board[1][1] << " | " << board[1][2]<< " | " <<endl;
    cout << "+---+---+---+" << endl;
    cout << "| "<<board[2][0] << " | " << board[2][1] << " | " << board[2][2]<< " | " <<endl;
    cout << "+---+---+---+" << endl <<endl;
}

// get player's input
void playerInput()
{
    int rowChoice=0;
    int colChoice = 0;
    if (turn == 'X')
    {
        cout << "X's turn: " << endl;
    }
    else if(turn == 'O')
    {
        cout << "O's turn: "<<endl;
    }
      
        cout << "Pick a row (1,2,3): " ;
    //test if number is valid
        while(!(cin >> rowChoice) || rowChoice <1 ||rowChoice>3)
        {
            cout << "Invalid number! Try agian: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    
        cout << "Pick a column(1,2,3): ";
    
        while(!(cin >> colChoice) || colChoice <1 ||colChoice>3)
              {
                  cout << "Invalid number! Try agian: " << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(),'\n');
              }
          
    
// put the x or o in the board
    if (turn == 'X' && board[rowChoice-1][colChoice-1] != 'X' && board[rowChoice-1][colChoice-1] != 'O')
    {
        board[rowChoice-1][colChoice-1] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[rowChoice-1][colChoice-1] != 'X' && board[rowChoice-1][colChoice-1] != 'O')
    {
        board[rowChoice-1][colChoice-1] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "The cell you chose is used! Try agian\n";
        playerInput();
    }
}

// check which player win
bool checkWin()
{


    for(int i =0; i<3; i++)         //check if x win or o win
    {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] !=' '&& board[i][1] != ' ' && board[i][2] !=' ' )
           || (board[0][i] == board[1][i] && board[1][i]==board[2][i] && board[0][i] !=' '&& board[1][i] != ' ' && board[2][i] !=' ')
           || (board [0][0] == board[1][1] &&board[1][1]==board[2][2] && board[0][0] != ' '&& board[1][1] !=' '&& board[2][2] != ' ' )
           ||(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] !=' '&& board[1][1] != ' ' && board[2][0] !=' '))
        {
            return true;
        }
    }
    
    //check if draw
    for (int i =0; i<3; i++)
    {
        for(int j =0; j<3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;               // check if it is the end of the game
            }
        }
    }
    draw = true;
    return true;
}
