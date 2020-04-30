#include "../include/Board.h"
#include "../include/VictoryCheeker.h"
#include "../include/Pattern.h"
class Manager
{
public:
	Manager();
	~Manager();

	void onPlay(int x, int y, int playCode)
	{
		if (VictoryCheeker::isFull(b))
		{//棋盘满了，平局

		}
		else
		{
			if (VictoryCheeker::have_five(b, x, y, playCode))
			{//编号为playerCode的获胜

			}
		}
	}
private:
	Board b = *(new Board());
	void init()
	{
		PatternList::initPattern();
	}
};

Manager::Manager()
{
}

Manager::~Manager()
{
}
