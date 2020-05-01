#ifndef _MANAGE_H_
#define _MANAGE_H_
#include "Board.h"
#include "VictoryCheeker.h"
#include "Panel.h"
#include "Evaluator.h"
#include "SingleEvaluator.h"
class Manager
{
public:
	Manager();
	~Manager();

	int play(int x, int y, int playCode,int score);
	int ai_vs_peo();
	int ai_vs_ai();
private:
	Board b;
	Panel panel;
	SingleEvaluator eva;
	//void init()
	//{
	//	PatternList::initPattern();
	//}
};

#endif