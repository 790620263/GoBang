#include "../include/DeepEvaluator.h"
#include "../include/STD.h"
#include <iostream>
//�ò��������,һ�������ڸò����
int DeepEvaluator::peoGo(Board& b, int deep)
{
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

		if(val)

		//unMakeMove
		b.setPlayerCode(plist[i].x, plist[i].y, 0);

		best = max(val, best);
	}
	delete[] plist;

	return best;
}

//�ò�AI����
int DeepEvaluator::aiGo(Board &b,int deep)
{
	if (deep <= 0)
		return evaluate_state(b);

	int best = -INFINITY_INT; int val;

	//generateLegalMove
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);

	//whileMovesLeft
	for (int i = 0; i < psize; i++)
	{
		//makeNextMove
		b.setPlayerCode(plist[i].x, plist[i].y, aiCode);

		val = peoGo(b, deep - 1);

		//unMakeMove
		b.setPlayerCode(plist[i].x, plist[i].y, 0);

		best = max(val, best);
	}
	delete[] plist;

	return best;
}
//����ĳһ���ľ���,���ض��ҷ��Ļ��ᣨ4�ӵȣ�
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
		oppoScore =oppoScore+ seva.evaluate(b, plist[i].x, plist[i].y, opponentCode);
		

		seva.evaluate(b, plist[i].x, plist[i].y, aiCode); //�Լ������Ƴ̶ȸ��֣�������AI
		myScore = myScore+seva.evaluate(b, plist[i].x, plist[i].y, aiCode);

		/*std::cout << "MYSCORE\t" << myScore << "\tOppoScore\t" << oppoScore<<std::endl;*/
	}
	
	//std::cout <<(*plist).x<<"\t"<< (*plist).y<< "\tMYSCORE\t" << myScore << "\tOppoScore\t" << oppoScore<<std::endl;
	
	delete[] plist;
	return -oppoScore+myScore;
}
//���۾��棬ǰհdeep��
int DeepEvaluator::evaluate_minmax(Board& b, int deep)
{
	//�ֵ�AI
	return aiGo(b, deep);
}

void DeepEvaluator ::getBestPosi_DeepSearch(Board& b, int& x, int& y, int& score)
{
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);
	x = plist[0].x; y = plist[0].y;//�ȳ�ʼ��һ��
	for (int i = 0; i < psize; i++)
	{

		//makeNextMove
		//b.setPlayerCode(plist[i].x, plist[i].y, aiCode);
		int s = evaluate_minmax(b, defaultSearchDeep);
		//int s = evaluate_state(b);

		//b.setPlayerCode(plist[i].x, plist[i].y, 0);


		if (score < s)
		{
			score =s;
			x = plist[i].x; y = plist[i].y;
		}
	}
	delete[] plist;
}

void DeepEvaluator::getBestPosition(Board& b, int& x, int& y, const int playerCode, int& score)
{
	//�˴���playerCode��Ϊ����
	aiCode = playerCode;
	getBestPosi_DeepSearch(b, x, y, score);
}