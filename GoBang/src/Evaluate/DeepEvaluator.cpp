#include "../include/DeepEvaluator.h"
#include "../include/STD.h"
#include "../include/VictoryCheeker.h"
#include <iostream>
#include <climits>
/*
	if (deep <= 0)
		cout << "ERROR  END IN PEOGO" << endl;

	int opponentCode = aiCode == 2 ? 1 : 2;

	int best = -INFINITY_INT; int val;

	//generateLegalMove
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);

	//whileMovesLeft
	for (int i = 0; i < psize; i++)
	{
		//makeNextMove
		b.setPlayerCode(plist[i].x, plist[i].y, opponentCode);

		val = aiGo(b, deep - 1);

		//unMakeMove
		b.setPlayerCode(plist[i].x, plist[i].y, 0);

		if (val <= big)return -INFINITY_INT;

		best = max(val, best);
	}
	delete[] plist;

	return best;
*/

//选择最小值
int DeepEvaluator::peoGo(Board& b, int deep, int big, int min)
{
	int opponentCode = aiCode == 2 ? 1 : 2;
	isOver = VictoryCheeker::have_five(b, opponentCode);
	if (deep <= 0||isOver)
		return evaluate_state(b);


	int best = INT_MAX; int val;

	//generateLegalMove
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);

	//whileMovesLeft
	for (int i = 0; i < psize; i++)
	{
		//makeNextMove
		b.setPlayerCode(plist[i].x, plist[i].y, opponentCode);

		val = aiGo(b, deep - 1,big,best);//big

		//unMakeMove
		b.setPlayerCode(plist[i].x, plist[i].y, 0);

		if (val < big)return big;

		best = min(val, best);
	}
	delete[] plist;

	return best;
}

//该层AI走子
int DeepEvaluator::aiGo(Board &b,int deep, int big, int min)
{
	isOver = VictoryCheeker::have_five(b, aiCode);
	if (deep <= 0 || isOver)
		return evaluate_state(b);

	int best = INT_MIN; int val;

	//generateLegalMove
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);

	//whileMovesLeft
	for (int i = 0; i < psize; i++)
	{
		//makeNextMove
		b.setPlayerCode(plist[i].x, plist[i].y, aiCode);

		val = peoGo(b, deep - 1,best,min);//min

		//unMakeMove
		b.setPlayerCode(plist[i].x, plist[i].y, 0);

		if (val > min)return min;
		best = max(val, best);
	}
	delete[] plist;

	return best;
}
//评价某一步的局面,返回对我方的机会（4子等）
int DeepEvaluator::evaluate_state(Board& b)
{
	int oppoScore = 0; int myScore = 0;
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);



	int opponentCode = aiCode == 2 ? 1 : 2;

	for (int i = 0; i < psize; i++)
	{
		//评估每个点的得分
			//先简单封装一下singleEvaluator的eva方法，以后再写快速匹配
		//以对方威胁程度给分，保守型AI
		oppoScore =oppoScore+ seva.evaluate(b, plist[i].x, plist[i].y, opponentCode);


		seva.evaluate(b, plist[i].x, plist[i].y, aiCode); //以己方优势程度给分，进攻型AI
		myScore = myScore+seva.evaluate(b, plist[i].x, plist[i].y, aiCode);

		/*std::cout << "MYSCORE\t" << myScore << "\tOppoScore\t" << oppoScore<<std::endl;*/
	}

	//std::cout <<(*plist).x<<"\t"<< (*plist).y<< "\tMYSCORE\t" << myScore << "\tOppoScore\t" << oppoScore<<std::endl;

	delete[] plist;
	return myScore-oppoScore;
}
//评价局面，前瞻deep步
//int DeepEvaluator::evaluate_minmax(Board& b, int deep)
//{
//	//轮到AI
//	return aiGo(b, deep);
//}

void DeepEvaluator ::getBestPosi_DeepSearch(Board& b, int& x, int& y, int& score)
{
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);
	x = plist[0].x; y = plist[0].y;//先初始化一下

	int tmpScore = INT_MAX;
	for (int i = 0; i < psize; i++)
	{

		//makeNextMove
		b.setPlayerCode(plist[i].x, plist[i].y, aiCode);

		tmpScore = peoGo(b, defaultSearchDeep, INT_MIN, INT_MAX);

		b.setPlayerCode(plist[i].x, plist[i].y, 0);


		if (score < tmpScore)
		{
			score =tmpScore;
			x = plist[i].x; y = plist[i].y;
		}
	}
	delete[] plist;
}

void DeepEvaluator::getBestPosition(Board& b, int& x, int& y, const int playerCode, int& score)
{
	//此处的playerCode记为电脑
	aiCode = playerCode;
	getBestPosi_DeepSearch(b, x, y, score);
}
