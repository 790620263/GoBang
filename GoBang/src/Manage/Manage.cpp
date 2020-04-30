#include "../include/Manage.h"

Manager::Manager()
{
	//b = *(new Board());
	panel.drawBoard(b);
}

Manager::~Manager()
{
	//delete &b;
}

bool Manager::isEnd(int x, int y, int playCode)
{

	if (VictoryCheeker::isFull(b))
	{//棋盘满了，平局
		panel.printMsg("平局");
		return true;
	}
	else
	{
		if (VictoryCheeker::have_five(b, x, y, playCode))
		{//编号为playerCode的获胜
			if (playCode == Panel::BLACK)
			{
				panel.printMsg("黑棋获胜");
			}
			else
			{
				panel.printMsg("白棋获胜");
			}
			return true;
		}
		
	}
	return false;
}

void Manager::ai_vs_peo()
{
	bool end = false;
	int x, y, score = 0;
	//默认人先手
	while (!end)
	{
		panel.getInput(x, y, b);

		b.setPlayerCode(x, y, Panel::BLACK);
		panel.drawBoard(b);
		panel.drawScore(x, y, score);

		end = isEnd(x, y, Panel::BLACK);

		Evaluator::getBestPosition(b,x,y,Panel::WHITE,score)
		b.setPlayerCode(x, y, Panel::BLACK);
		panel.drawBoard(b);
		panel.drawScore(x, y, score);
	}
}

void Manager::ai_vs_ai()
{

}
