#include "../include/Manage.h"
#include <iostream>
Manager::Manager()
{
	//b = *(new Board());
	panel.drawBoard(b);
}

Manager::~Manager()
{
	//delete &b;
}
//返回胜利者编号,-1表示平局,0表示未结束
int Manager::play(int x, int y, int playCode,int score)
{
	b.setPlayerCode(x, y, playCode);
	panel.drawBoard(b,x,y);
	panel.drawScore(x, y, score);

	if (VictoryCheeker::isFull(b))
	{//棋盘满了，平局
		panel.printMsg("平局");
		return -1;
	}
	else
	{
		if (VictoryCheeker::have_five(b, x, y, playCode))
		{//编号为playerCode的获胜
			if (playCode == Board::BLACK)
			{
				panel.printMsg("黑棋获胜");
			}
			else
			{
				panel.printMsg("白棋获胜");
			}
			return playCode;
		}
		
	}

	//Sleep(1000);
	return 0;
}

int Manager::ai_vs_peo()
{
	int winner = 0;
	int x, y, score = 0;
	//默认人(白棋）先手
	while (winner==0)
	{
		panel.getInput(x, y, b);
		winner=play(x, y, Board::WHITE, score);
		//eva.getBestPosition(b, x, y, Panel::BLACK, score);

		if (winner!=0)break;

		//eva.getBestPosition(b, x, y, Board::BLACK, score);
		deva.getBestPosition(b, x, y, Board::BLACK, score);
		play(x, y, Board::BLACK, score);
	}
	return winner;
}

int Manager::ai_vs_ai()
{
	int winner = 0;
	int x=b.getSize()/2, y=b.getSize()/2, score = 0;

	winner= play(x, y, Board::WHITE,score);
	//默认白棋先手
	while (winner == 0)
	{
		//eva.getBestPosition(b, x, y, Board::BLACK, score);

		//对黑棋使用深度搜索
		deva.getBestPosition(b, x, y, Board::BLACK, score);

		winner = play(x, y, Board::BLACK, score);

		if (winner != 0)break;

		//单层搜索
		eva.getBestPosition(b, x, y, Board::WHITE, score);
		winner = play(x, y, Board::WHITE, score);
	}
	return winner;
}
