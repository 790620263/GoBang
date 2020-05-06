#include "../include/Evaluator.h"
#include<cstdlib>
#include<ctime>

//2是自己，1是对手,0是没有
int Evaluator::evaluate(Board& b, const int x, const int y, const int playerCode)
{
	return 0;
}
void Evaluator::getBestPosition(Board& b, int& x, int& y, const int& playerCode, int& score)
{
}

//返回可行位置（（（（（（注意删除plist！！！！！））））
Position* Evaluator::getAvailablePosition(Board& b,int &size)
{
	int boardSize = b.getSize();

	size = 0;
	Position* plist = new Position[boardSize*boardSize];

	for (int x = 0; x < boardSize; x++)
	{
		for (int y = 0; y < boardSize; y++)
		{
			int code = b.getPlayerCode(x, y);
			if (code != 0)
			{//周围5*5可行
				for(int i=-2;i<3;i++)
					for (int j = -2; j < 3; j++)
					{
						int tmpx = x + i, tmpy = y + j; 
						bool notexist = true;
						if (b.getPlayerCode(tmpx, tmpy) == 0) {
							for (int k = 0; k < size; k++)
							{
								if (plist[k].x == tmpx && plist[k].y == tmpy) 
								{ notexist = false; break; }
							}
							if (notexist)
							{
								plist[size] = Position{ tmpx,tmpy };
								size++;
							}

						}
					}
				
			}
			//if (code == 0)plist[size] = Position{ x,y };
		}
	}

	srand(time(NULL));
	int rnd;
	for (int i = 0; i < size; i++)
	{
		rnd = rand() % size;
		Position tmpp = plist[i];
		plist[i] = plist[rnd];
		plist[rnd] = tmpp;
	}

	return plist;
}
//返回长度为8的数组
//void Evaluator::getRandomAxisList(int list[8])
//{
//	srand(time(NULL));
//	int rnd; bool isExist = false;
//	for (int i = 0; i < 8; i++)
//	{
//		do {
//			isExist = false;
//			rnd = rand() % 8;
//			for (int j = 0; j < i; j++)
//			{
//				if (list[j] == rnd) {
//					isExist = true; break;
//				}
//			}
//		} while (isExist);
//		list[i] = rnd;
//		
//	}
//}
//KEY，估值函数，匹配各种棋势
