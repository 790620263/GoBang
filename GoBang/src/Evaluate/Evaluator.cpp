#include "../include/Evaluator.h"
#include "../include/Pattern.h"


Evaluator::Evaluator()
{
}

Evaluator::~Evaluator()
{
}

//2���Լ���1�Ƕ���,0��û��
int Evaluator::evaluate(Board& b, int x, int y, int playerCode)
{
	int score = 0;
	string toCheck = "";

	int opponentCode;//���ֵı��
	if (playerCode == 1)opponentCode = 2;
	else opponentCode = 1;

	for (int axis = 0; axis < 8; axis++)
	{
		//memset(toCheckArr, 0, sizeof(toCheckArr));//����Ϊ0

		//�������4����
		for (int i = 0; i < 4; i++)
		{
			int code = b.getCodeOffsetPosi(x, y, axis, i);
			if (code == -1)//Խ����
				code = opponentCode;
			else if (code = opponentCode)
				code = 1;
			else code = 2;

			toCheck.append("" + code);
		}
		//�������4����
		//for (int i = 0; i < 4; i++)
		//{
		//	int code = (*b).getCodeOffsetPosi(x, y, axis + 4, i);
		//	if (code == -1)//Խ����
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
//KEY����ֵ������ƥ���������
