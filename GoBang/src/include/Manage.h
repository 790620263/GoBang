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

	bool isEnd(int x, int y, int playCode);
	void ai_vs_peo();
	void ai_vs_ai();
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