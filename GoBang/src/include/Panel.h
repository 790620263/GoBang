#ifndef _PANEL_H_
#define _PANEL_H_
#include "Board.h"
#include <string>
class Panel
{
private:
public:
    const static int WHITE = 1;
    const static int BLACK = 2;
    void drawBoard(Board& b);
    void drawScore(int x, int y, int sc);
    void printMsg(std::string msg);
    void clear();
    void clearLine(int lineNum);
    void getInput(int& x, int& y,int boardSize);
};
#endif // !_PANEL_H_



