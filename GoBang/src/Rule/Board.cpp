#include "../include/Board.h"
#include <iostream>
bool Board::setPlayerCode(int x, int y, int playerCode)
{
	if (isInBoard(x, y)) {
		board[x][y] = playerCode;
		return true;
	}
	return false;
}
/*����������̣����� - 1 */
int Board::getPlayerCode(int x, int y)
{
	if (isInBoard(x, y))
		return this->board[x][y];
	else return -1;
}
int Board::getSize() { return size; }

/*���أ�x,y)����axis����ƫ��offset��ı��
����������̣�����-1*/
int Board::getCodeOffsetPosi(int x, int y, int axis, int offset)
{
	int i, j;//i:x��ƫ������j����y��ƫ����
	switch (axis)
	{
	case 0:
		i = 0;
		j = -1;
			break;
	case 1:
		i = 1;
		j = -1;
		break;
	case 2:
		i = 1;
		j = 0;
		break;
	case 3:
		i = 1;
		j = 1;
		break;
	case 4:
		i = 0;
		j = 1;
		break;
	case 5:
		i = -1;
		j = 1;
		break;
	case 6:
		i = -1;
		j = 0;
		break;
	case 7:
		i = -1;
		j = -1;
		break;
	default:
		//throw "�Ƿ���axis";
		std::cout << "�Ƿ���axis" << std::endl;
	}
	x += i * offset;
	y += j * offset;
	if (x >= 0 && x < this->size && y >= 0 && y < this->size)
	{//�����x��y����������
		return board[x][y];
	}
	else
	{//Խ��
		return -1;
	}
}

bool Board::isInBoard(int x, int y)
{
	if (x>=0 &&x < this->size && y>=0 && y < this->size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//void Board::print()
//{
//	for (int x = 0; x < size; x++)
//	{
//		for (int y = 0; y<size; y++)
//		{
//			std::cout<<' ' << board[x][y];
//		}
//		std::cout << std::endl;
//	}
//}

Board::Board()
{
	int board[DefaultSize][DefaultSize]={ 0 };
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			board[x][y] = 0;
		}
	}
}
