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
		{//�������ˣ�ƽ��

		}
		else
		{
			if (VictoryCheeker::have_five(b, x, y, playCode))
			{//���ΪplayerCode�Ļ�ʤ

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
