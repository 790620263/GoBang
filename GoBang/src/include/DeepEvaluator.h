#ifndef _DEEPEVALUATOR_H_
#define _DEEPEVALUATOR_H_

#include "SingleEvaluator.h"
class DeepEvaluator :Evaluator
{


public:
	int evaluate(Board& b, const int x, const int y, const int playerCode);
	void getBestPosition(Board& b, const int& x, const int& y, const int& playerCode, int& score);

private:
	SingleEvaluator seva;

	int aiCode = 2;//ºÚÆå
	int getMin(Board& b, int deep);
	int getMax(Board& b, int deep);
	int evaluate_state(Board &b);
	int evaluate_mixmax(Board &b, int deep, int onTurnPlayerCode);

	
};


#endif // !_DEEPEVALUATOR_H_



