#include "../include/DeepEvaluator.h"

//�ò��������
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

//�ò�AI����
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
//����ĳһ���ľ���,���ض�AI����в�̶�
int DeepEvaluator::evaluate_state(Board& b)
{
	int oppoScore = 0; int myScore = 0;
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);


	
	int opponentCode = aiCode == 2 ? 1 : 2;

	for (int i = 0; i < psize; i++)
	{
		//����ÿ����ĵ÷�
			//�ȼ򵥷�װһ��singleEvaluator��eva�������Ժ���д����ƥ��
		//�ԶԷ���в�̶ȸ��֣�������AI
		oppoScore = max(oppoScore, seva.evaluate(b, plist[i].x, plist[i].y, opponentCode));
		

		//seva.evaluate(b, plist[i].x, plist[i].y, aiCode) �Լ������Ƴ̶ȸ��֣�������AI
		myScore = max(myScore, seva.evaluate(b, plist[i].x, plist[i].y, opponentCode));


	}
	delete[] plist;

	return oppoScore-myScore;
}
//���۾��棬ǰհdeep��
int DeepEvaluator::evaluate_mixmax(Board& b, int deep, int onTurnPlayerCode)
{
	//�ֵ�AI
	if (onTurnPlayerCode == aiCode)
		return getMax(b, deep);
	else
		return getMin(b, deep);
}
