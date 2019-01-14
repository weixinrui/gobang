//
// Created by wei on 31/10/18.
//

#ifndef GOBANG_GOBANG_H
#define GOBANG_GOBANG_H


class Gobang {
private:
    char board[9][9];
    int Firstplayer, Secondplayer, Draws;
    int SpotsOnBoard;
    char Choice;
public:
    Gobang();
    void reset();
    void printBoard();
    void PromptTurnO();
    void PromptTurnX();
    void printState();
    void printinfo();
    void iferror(int&,int&);
    void ChoiceofChar();
    bool Owin();
    bool Xwin();
    bool detect();
    bool detect1();
};


#endif //GOBANG_GOBANG_H
