#ifndef _VICTORYCHEEKER_H_
#define _VICTORYCHEEKER_H_
#include "Board.h"
class VictoryCheeker
{
public:
	VictoryCheeker();
	~VictoryCheeker();
	static bool isFull(Board &b);
	static bool isVictory(Board &b, int playerCode);
	static bool have_five(Board &b, int x, int y, int playerCode);
private:
	static int how_many(Board &b, int x, int y, int playerCode, int xplus, int yplus);
};

#endif // _VICTORYCHEEKER_H_
