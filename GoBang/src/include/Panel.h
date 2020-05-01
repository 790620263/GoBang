#ifndef _PANEL_H_
#define _PANEL_H_
#include "Board.h"
#include "STD.h"
class Panel
{
private:
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
public:
    Panel();
    const static int WHITE = 1;
    const static int BLACK = 2;

    void setColor(int background, int foreground);

    void drawBoard(Board& b, int newX, int newY);
    void drawBoard(Board& b);
    void drawScore(int x, int y, int sc);
    void printMsg(std::string msg);
    void clear();
    void clearLine(int lineNum);
    void getInput(int& x, int& y,Board &b);
};
#endif // !_PANEL_H_



