#include "../include/VictoryCheeker.h"

VictoryCheeker::VictoryCheeker()
{
}

VictoryCheeker::~VictoryCheeker()
{
}

bool VictoryCheeker::isFull(Board &b)
{
	int availablePosi = 0;
	for (int x = 0;x<b.getSize();x++)
	{
		for (int y = 0; y <b.getSize(); y++)
		{
			if (b.getPlayerCode(x,y) == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool VictoryCheeker::isVictory(Board &b,int playerCode)
{
	for (int x = 0; x < b.getSize(); x++)
	{
		for (int y = 0; y < b.getSize(); y++)
		{
			if (have_five(b, x, y, playerCode))
				return true;
		}
	}
	return false;
}

bool VictoryCheeker::have_five(Board &b, int x, int y, int playerCode)
{
	if (b.getPlayerCode(x, y) != playerCode)return false;
	for (int i = -1; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (i != 0 || j != 0)
			{
				if (how_many(b, x, y, playerCode, i, j)+how_many(b, x, y, playerCode, -i, -j)-1>=5)
					return true;
			}
		}
	}
	return false;
}
int VictoryCheeker::how_many(Board &b,int x, int y, int playerCode,int xplus,int yplus)
{
	int score = 1;
	for (int i = 0; i < 5; i++)
	{
		x += xplus;
		y += yplus;
		if (b.isInBoard(x, y))
		{
			if (b.getPlayerCode(x, y) == playerCode)
			{
				score++;
			}else break;
		}
	}
	return score;
}
