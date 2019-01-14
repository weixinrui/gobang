#include <iostream>
#include "Gobang.h"
using namespace std;
int main() {
    Gobang c1;

    c1.printinfo();
    while (c1.detect())
    {
        c1.reset();
        c1.printBoard();
        while (1)
        {
            c1.PromptTurnO();
            c1.printBoard();
            if (c1.Owin())
            {
                cout << "O player win the game" << endl;
                break;
            }
            c1.PromptTurnX();
            c1.printBoard();
            if (c1.Xwin())
            {
                cout << "X player win the game" << endl;
                break;
            }
            if (c1.detect1())
            {
                cout << "Draw!" << endl;
                break;
            }
        }
        c1.ChoiceofChar();
    }
    c1.printState();
    getchar();
    getchar();
    return 0;
}