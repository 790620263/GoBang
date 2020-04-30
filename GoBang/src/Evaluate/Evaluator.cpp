#include "../include/Evaluator.h"


//2是自己，1是对手,0是没有
int Evaluator::evaluate(Board& b, const int x, const int y, const int playerCode)
{
	return 0;
}
void Evaluator::getBestPosition(Board& b, const int& x, const int& y, const int& playerCode, int& score)
{
}
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
			{//周围3*3可行
				for(int i=-1;i<2;i++)
					for (int j = -1; j < 2; j++)
					{
						if (i != 0 || j != 0)
						{
							int tmpx = x + i, tmpy = y + j; 
							bool notexist = true;
							if (b.getPlayerCode(tmpx, tmpy) == 0) {
								for (int k = 0; k < size; k++)
								{
									if (plist[k].x == tmpx && plist[k].y == tmpy) { notexist = false; break; }
								}
								if (notexist)
								{
									plist[size] = Position{ tmpx,tmpy };
									size++;
								}
							}
						}
					}
				
			}
			//if (code == 0)plist[size] = Position{ x,y };
		}
	}
	return plist;
}
//KEY，估值函数，匹配各种棋势
