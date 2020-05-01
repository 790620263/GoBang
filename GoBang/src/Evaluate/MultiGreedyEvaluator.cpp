#include "../include/MultiGreedyEvaluator.h"



void MultiGreedyEvaluator::getBestPosition(Board& b, const int& x, const int& y, const int& playerCode, int& score)
{
}

int MultiGreedyEvaluator::evaluate(Board& b, const int x, const int y, const int playerCode)
{

	return 0;
}

int MultiGreedyEvaluator::evaluateWithDeep(Board& b, const int x, const int y, const int playerCode, int nowDeep)
{
	int opponentCode = playerCode == 1 ? 2 : 1;
	int score = 0;
	Position* plist; int psize;
	plist=seva.getAvailablePosition(b, psize);


	if (nowDeep < defaultSearchDeep)
	{
		score+=


	}
}

int MultiGreedyEvaluator::evaluateNodeValue(Board& b,const int playerCode)
{
	//利用SingleEvaluator的getBestPosition函数获得该情况下的最高得分
	int notneed, score;
	seva.getBestPosition(b, notneed, notneed, playerCode, score);
	return 0;
}
