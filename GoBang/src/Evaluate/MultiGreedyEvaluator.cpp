#include "../include/MultiGreedyEvaluator.h"
#include <map>


void MultiGreedyEvaluator::getBestPosition(Board& b,  int& x,  int& y, const int& playerCode, int& score)
{
}

int MultiGreedyEvaluator::evaluate(Board& b, const int x, const int y, const int playerCode)
{

	return 0;
}

void MultiGreedyEvaluator::getBestPosi_DeepSearch(Board& b, const int x, const int y, const int playerCode, int nowDeep)
{
	if (nowDeep < defaultSearchDeep)
	{
		//int opponentCode = playerCode == 1 ? 2 : 1;
		int val = 0;
		Position* plist; int psize;
		plist = seva.getAvailablePosition(b, psize);

		map<Position, int> pval;

		for (int i = 0; i < psize; i++)
		{
			b.setPlayerCode(plist[i].x, plist[i].y, playerCode);

			val = evaluateNodeValue(b, playerCode);
			pval.insert(pair<Position,int>(plist[i],val));

			b.setPlayerCode(plist[i].x, plist[i].y, 0);//还原棋盘
			
		}

		nowDeep++;
	}
}

int MultiGreedyEvaluator::evaluateNodeValue(Board& b,const int playerCode)
{
	//利用SingleEvaluator的getBestPosition函数获得该情况下的最高得分
	int notneed, score;
	seva.getBestPosition(b, notneed, notneed, playerCode, score);
	return 0;
}
