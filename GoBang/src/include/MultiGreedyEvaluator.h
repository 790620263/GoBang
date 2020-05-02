#ifndef _MULTIGREEDYEVALUATOR_H_
#define _MULTIGREEDYEVALUATOR_H_

#include "Evaluator.h"
#include "SingleEvaluator.h"
class MultiGreedyEvaluator :Evaluator
{
public:
	
	void getBestPosition(Board& b, int& x, int& y, const int playerCode, int& score);
	
private:
	const int defaultSearchDeep = 2;
	int aiCode = 2;
	SingleEvaluator seva;

	void getBestPosi_DeepSearch(Board& b, int& x, int& y, int &score);
	int fastEvaluate_state(Board& b, const int playerCode);//考虑playeCode=2的利益。黑棋2
	int evaluate_state_tree(Board& b, int nowDeep, const int playerCode);
};


#endif // !_MULTIGREEDYEVALUATOR_H_


