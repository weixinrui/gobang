//
// Created by wei on 31/10/18.
//

#ifndef GOBANG_GOBANG_H
#define GOBANG_GOBANG_H

#include <iostream>
#include <vector>
using std::cout;
using std::vector;


class Gobang {
private:
    vector< vector<char> > board;
    int Firstplayer, Secondplayer, Draws;
    int SpotsOnBoard;
    char Choice;
public:
    Gobang();
    void reset();
    void printBoard();
    void PromptTurn(bool);
    void printState();
    void printinfo();
    void iferror(int&,int&);
    void ChoiceofChar();
    bool Owin();
    bool Xwin();
    bool detect();
    bool detect_tie();
    inline void clear() {cout<<"\033[2J";}
};

int Add(int, int);


#endif //GOBANG_GOBANG_H
