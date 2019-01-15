//
// Created by wei on 31/10/18.
//
#include <iostream>
#include <vector>
#include "Gobang.h"
using namespace std;
//Used to initialise the chessboard
Gobang::Gobang()
{
    Choice = 'Y';
}
//used to reset chessboard after one round.
void Gobang::reset()
{
    board.resize(9);
    for(size_t i = 0; i != board.size(); i++)
        for(int j=0; j < 9; j++)
            board[i].push_back(' ');
    Firstplayer = 0;
    Secondplayer = 0;
    Draws = 0;
    SpotsOnBoard = 0;
}
void Gobang::printinfo()
{
    cout << "FirstPlayer is represent by O,second by X." << endl;
    cout << "Enter the coordinates for ROWs and Columns" << endl;
    cout << "Strike enter when Done." << endl;
    cout << endl;
}
//used to print chessboard on screen
void Gobang::printBoard()
{
    cout<<endl;
    cout << "    1   2   3   4   5   6   7   8   9" << endl;
    for(size_t i=0; i!= board.size(); i++)
    {
        cout<< i+1 <<"  ";
        for(size_t j=0; j!=board[i].size(); j++)
        {
            cout<<board[i][j]<<" | ";
        }
        cout<<'\n'<<"--|------------------------------------"<<endl;
    }
    cout<<endl<<endl;
}
void Gobang::PromptTurn(bool turn)
{
    int x, y;
    if(turn == true)
    {
        cout << "Turn of the first player(O),enter the coordinates" << endl;
        cout << "Row:";
        cin >> x;
        cout << "Column:";
        cin >> y;
        iferror(x, y);
        board[x-1][y-1] = 'O';
    }
    else
    {
        cout << "Turn of the first player(X),enter the coordinates" << endl;
        cout << "Row:";
        cin >> x;
        cout << "Column:";
        cin >> y;
        iferror(x, y);
        board[x-1][y-1] = 'X';
    }
    SpotsOnBoard++;
}
//used to check whether the position inputted by player legal or not
//if the position is illegal, asking player to input again
void Gobang::iferror(int &x, int &y)
{
    while (1)
    {
        if (x<1 || x>9 || y<1 || y>9 || (board[x - 1][y - 1] == 'O' || board[x - 1][y - 1] == 'X'))
        {
            cout << "This coordinate is not allowed,try again" << endl;
            cout << "row:";
            cin >> x;
            cout << "column:";
            cin >> y;
        }
        else
            break;
    }
}
//if play one more round of not
void Gobang::ChoiceofChar()
{
    cout << endl;
    cout << "Press CAPITAL Y if you want to play again." << endl;
    cout << "Otherwise,press any other letter key to exit the loop." << endl;
    char c;
    cin >> c;
    Choice = c;
}
bool Gobang::detect()
{
    if (Choice == 'Y')
        return true;
    else
        return false;
}

bool Gobang::detect_tie()
{
    if(SpotsOnBoard >= 81)
    {
        Draws++;
        return true;
    }
    else
        return false;
}

//This function is used to check whether o player win or not.
//if x win, return true, else return false
bool Gobang::Owin()
{
    int next[3][2] = {
            {0,1},
            {1,1},
            {1,0}
    };
    int tx, ty, count;
    count = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            count=0;
            if (board[i][j] == 'O')
            {
                count++;
                for (int k = 0; k < 3; k++)
                {
                    tx = i + next[k][0];
                    ty = j + next[k][1];

                    if (tx<0 || tx>9 || ty<0 || ty>9 || board[tx][ty] != 'O')
                        continue;
                    count++;
                    for (int l = 0; l < 3; l++)
                    {
                        tx =tx +  next[k][0];
                        ty =ty +  next[k][1];

                        if (tx<0 || tx>9 || ty<0 || ty>9)
                            break;
                        if (board[tx][ty] != 'O')
                            break;
                        count++;
                    }

                    if (count == 5)
                    {
                        Firstplayer++;
                        return true;
                    }
                }
            }

        }
    }
    return false;
}

//This function is used to check whether x player win or not.
//if x win, return true, else return false
bool Gobang::Xwin()
{
    int next[3][2] = {
            {0,1},
            {1,1},
            {1,0}
    };
    int tx, ty, count;
    count = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            count=0;
            if (board[i][j] == 'O')
            {
                count++;
                for (int k = 0; k < 3; k++)
                {
                    tx = i + next[k][0];
                    ty = j + next[k][1];

                    if (tx<0 || tx>9 || ty<0 || ty>9 || board[tx][ty] != 'O')
                        continue;
                    count++;
                    for (int l = 0; l < 3; l++)
                    {
                        tx =tx +  next[k][0];
                        ty =ty +  next[k][1];

                        if (tx<0 || tx>9 || ty<0 || ty>9)
                            break;
                        if (board[tx][ty] != 'O')
                            break;
                        count++;
                    }


                    if (count == 5)
                    {
                        Secondplayer++;
                        return true;
                    }
                }
            }

        }
    }
    return false;
}
//State printing function
void Gobang::printState()
{
    cout << "The O player have won " << Firstplayer << " times" << endl;
    cout << "The X player have won " << Secondplayer << " times" << endl;
    cout << "There was " << Draws << " draws" << endl;
    cout << "Thanks for using my program" << endl;
}