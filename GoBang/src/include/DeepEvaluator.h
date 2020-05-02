#ifndef _DEEPEVALUATOR_H_
#define _DEEPEVALUATOR_H_

#include "SingleEvaluator.h"
class DeepEvaluator :Evaluator
{


public:
	/*int evaluate(Board& b, const int x, const int y, const int playerCode);*/
	void getBestPosition(Board& b, int& x, int& y, const int playerCode, int& score);

private:
	SingleEvaluator seva;

	int aiCode = 2;//ºÚÆå
	const int defaultSearchDeep = 2;

	int peoGo(Board& b, int deep,int big);
	int aiGo(Board& b, int deep);
	int evaluate_state(Board &b);
	int evaluate_minmax(Board &b, int deep);

	void getBestPosi_DeepSearch(Board& b, int& x, int& y, int& score);

	
	
};


#endif // !_DEEPEVALUATOR_H_



