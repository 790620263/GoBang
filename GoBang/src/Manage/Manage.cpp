#include "../include/Manage.h"
#include <iostream>
Manager::Manager()
{
	b = *(new Board());
	panel.drawBoard(b);
}

Manager::~Manager()
{
	//delete &b;
}
//����ʤ���߱��,-1��ʾƽ��,0��ʾδ����
int Manager::play(int x, int y, int playCode,int score)
{
	b.setPlayerCode(x, y, playCode);
	panel.drawBoard(b,x,y);
	panel.drawScore(x, y, score);

	if (VictoryCheeker::isFull(b))
	{//�������ˣ�ƽ��
		panel.printMsg("ƽ��");
		return -1;
	}
	else
	{
		if (VictoryCheeker::have_five(b, x, y, playCode))
		{//���ΪplayerCode�Ļ�ʤ
			if (playCode == Board::BLACK)
			{
				panel.printMsg("�����ʤ");
			}
			else
			{
				panel.printMsg("�����ʤ");
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
	//Ĭ����(���壩����
	while (winner==0)
	{
		panel.getInput(x, y, b);
		winner=play(x, y, Board::WHITE, score);
		//eva.getBestPosition(b, x, y, Panel::BLACK, score);

		if (winner!=0)break;

		eva.getBestPosition(b, x, y, Board::BLACK, score);
		//deva.getBestPosition(b, x, y, Board::BLACK, score);
		play(x, y, Board::BLACK, score);
	}
	return winner;
}

int Manager::ai_vs_ai()
{
	int winner = 0;
	int x=b.getSize()/2, y=b.getSize()/2, score = 0;

	winner= play(x, y, Board::WHITE,score);
	//Ĭ�ϰ�������
	while (winner == 0)
	{
		eva.getBestPosition(b, x, y, Board::BLACK, score);

		//�Ժ���ʹ���������
		//deva.getBestPosition(b, x, y, Board::BLACK, score);

		winner = play(x, y, Board::BLACK, score);

		if (winner != 0)break;

		//��������
		eva.getBestPosition(b, x, y, Board::WHITE, score);
		winner = play(x, y, Board::WHITE, score);
	}
	return winner;
}
