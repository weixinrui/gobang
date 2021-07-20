#include <iostream>
#include <vector>
#include "Gobang.h"
//#include "termcolor.hpp"
using namespace std;
//using namespace termcolor;
int main() {
    Gobang c1;
    c1.printinfo();
    while (c1.detect())
    {
        c1.reset();
        c1.clear();
        c1.printBoard();
        while (1)
        {
            c1.PromptTurn(true);

            //check if the board meets its capacity
            if (c1.detect_tie())
            {
                cout << "Draw!" << endl;
                break;
            }

            c1.clear();//clear screen
            c1.printBoard();
            if (c1.Owin())
            {
                cout << "O player win the game" << endl;
                break;
            }
            c1.PromptTurn(false);

            if (c1.detect_tie())
            {
                cout << "Draw!" << endl;
                break;
            }

            c1.clear();
            c1.printBoard();
            if (c1.Xwin())
            {
                cout << "X player win the game" << endl;
                break;
            }
        }
        c1.ChoiceofChar();
    }
    c1.printState();
    return 0;
}
