#include "../include/DeepEvaluator.h"

//该层玩家走子
int DeepEvaluator::getMin(Board& b, int deep)
{
	if (deep <= 0)
		return evaluate_state(b);

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

		val = getMax(b, deep - 1);

		//unMakeMove
		b.setPlayerCode(plist[i].x, plist[i].y, 0);

		best = min(val, best);
	}
	return best;
}

//该层AI走子
int DeepEvaluator::getMax(Board &b,int deep)
{
	if (deep <= 0)
		return evaluate_state(b);

	int best = INFINITY_INT; int val;

	//generateLegalMove
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);

	//whileMovesLeft
	for (int i = 0; i < psize; i++)
	{
		//makeNextMove
		b.setPlayerCode(plist[i].x, plist[i].y, aiCode);

		val = getMin(b, deep - 1);

		//unMakeMove
		b.setPlayerCode(plist[i].x, plist[i].y, 0);

		best = max(val, best);
	}
	return best;
}
//评价某一步的局面,返回对AI的威胁程度
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
		oppoScore = max(oppoScore, seva.evaluate(b, plist[i].x, plist[i].y, opponentCode));
		

		//seva.evaluate(b, plist[i].x, plist[i].y, aiCode) 以己方优势程度给分，进攻型AI
		myScore = max(myScore, seva.evaluate(b, plist[i].x, plist[i].y, opponentCode));


	}
	delete[] plist;

	return oppoScore-myScore;
}
//评价局面，前瞻deep步
int DeepEvaluator::evaluate_mixmax(Board& b, int deep, int onTurnPlayerCode)
{
	//轮到AI
	if (onTurnPlayerCode == aiCode)
		return getMax(b, deep);
	else
		return getMin(b, deep);
}
