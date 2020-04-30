#ifndef _MANAGE_H_
#define _MANAGE_H_
#include "Board.h"
#include "VictoryCheeker.h"
#include "../include/Panel.h"

class Manager
{
public:
	Manager();
	~Manager();

	bool isEnd(int x, int y, int playCode);
	void ai_vs_peo();
	void ai_vs_ai();
private:
	Board b;
	Panel panel;
	//void init()
	//{
	//	PatternList::initPattern();
	//}
};

#endif