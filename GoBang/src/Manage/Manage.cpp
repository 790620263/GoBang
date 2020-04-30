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

bool Manager::isEnd(int x, int y, int playCode)
{

	if (VictoryCheeker::isFull(b))
	{//�������ˣ�ƽ��
		panel.printMsg("ƽ��");
		return true;
	}
	else
	{
		if (VictoryCheeker::have_five(b, x, y, playCode))
		{//���ΪplayerCode�Ļ�ʤ
			if (playCode == Panel::BLACK)
			{
				panel.printMsg("�����ʤ");
			}
			else
			{
				panel.printMsg("�����ʤ");
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
	//Ĭ��������
	while (!end)
	{
		panel.getInput(x, y, b);

		b.setPlayerCode(x, y, Panel::BLACK);
		//eva.getBestPosition(b, x, y, Panel::BLACK, score);
		score = eva.evaluate(b, x, y, Panel::BLACK);
 		panel.drawBoard(b);
		panel.drawScore(x, y, score);

		end = isEnd(x, y, Panel::BLACK);

		eva.getBestPosition(b, x, y, Panel::WHITE, score);
		
		b.setPlayerCode(x, y, Panel::WHITE);
		panel.drawBoard(b);
		panel.drawScore(x, y, score);

		end = isEnd(x, y, Panel::WHITE);
	}
}

void Manager::ai_vs_ai()
{

}
