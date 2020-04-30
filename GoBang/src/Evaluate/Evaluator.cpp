#include "../include/Evaluator.h"
#include "../include/Pattern.h"


Evaluator::Evaluator()
{
}

Evaluator::~Evaluator()
{
}

//2是自己，1是对手,0是没有
int Evaluator::evaluate(Board& b, int x, int y, int playerCode)
{
	int score = 0;
	string toCheck = "";

	int opponentCode;//对手的编号
	if (playerCode == 1)opponentCode = 2;
	else opponentCode = 1;

	for (int axis = 0; axis < 8; axis++)
	{
		//memset(toCheckArr, 0, sizeof(toCheckArr));//重置为0

		//正方向的4个子
		for (int i = 0; i < 4; i++)
		{
			int code = b.getCodeOffsetPosi(x, y, axis, i);
			if (code == -1)//越界了
				code = opponentCode;
			else if (code = opponentCode)
				code = 1;
			else code = 2;

			toCheck.append("" + code);
		}
		//反方向的4个子
		//for (int i = 0; i < 4; i++)
		//{
		//	int code = (*b).getCodeOffsetPosi(x, y, axis + 4, i);
		//	if (code == -1)//越界了
		//		code = opponentCode;
		//	else if (code = opponentCode)
		//		code = 1;
		//	else code = 2;

		//	toCheckArr[5 + i] = code;
		//}
	}

	return score;
}
void Evaluator::getBestPosition(Board& b, int& x, int& y, int& playerCode, int& score)
{
}
//KEY，估值函数，匹配各种棋势
