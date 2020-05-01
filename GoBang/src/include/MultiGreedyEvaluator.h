#ifndef _MULTIGREEDYEVALUATOR_H_
#define _MULTIGREEDYEVALUATOR_H_

#include "Evaluator.h"
#include "SingleEvaluator.h"
class MultiGreedyEvaluator :Evaluator
{
public:
	int evaluate(Board& b, const int x, const int y, const int playerCode);
	void getBestPosition(Board& b, int& x, int& y, const int& playerCode, int& score);
	
private:
	const int defaultSearchDeep = 3;
	SingleEvaluator seva;
	void getBestPosi_DeepSearch(Board& b, const int x, const int y, const int playerCode,int nowDeep );
	int evaluateNodeValue(Board& b,int playerCode);
};


#endif // !_MULTIGREEDYEVALUATOR_H_


