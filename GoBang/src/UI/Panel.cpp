#include "../include/Panel.h"
#include <iostream>
#include<iomanip>
#include<sstream>
using namespace std;


Panel::Panel()
{
	setColor(15, 0);
}
/*//int����0-15,15�ף�0��*/
void Panel::setColor(int background, int foreground)
{
	//WORD wr1 = 0xf0;//������ɫ���ԣ���һλΪ����ɫ���ڶ�λΪǰ��ɫ
	WORD wr1 = background << 4 + foreground;
	SetConsoleTextAttribute(hOut, wr1);
}

void Panel::drawBoard(Board &b) {
	clear();
	int size = b.getSize();

	cout << setw(5) << '\\';
	for (int x = 0; x < size; x++)
	{
		cout << setw(5) << x;
	}
	cout <<'\n'<< endl;
	for (int y = 0; y < size; y++)
	{
		cout << setw(5) << y;
		for (int x = 0; x < size; x++)
		{
			cout << setw(5);
			switch (b.getPlayerCode(x, y))
			{
			case 0:
				cout << '+';
				break;
			case WHITE:
				cout << "��";
				break;
			default :
				cout << "��";
				break;
			}
		}
		cout<<'\n' << endl;
	}
}
void Panel::drawScore(int x,int y,int score) {
	cout << "����λ�ã�" << setw(5) << x << setw(5) << y << '\t' << "��Score= " << score << endl;
}
void Panel::printMsg(std::string msg)
{
	cout << msg << endl;
}
void Panel::clear() {
	//system("cls");
}
void Panel::clearLine(int lineNum) {
	for (int i = 0; i < lineNum; i++)
	{
		cout << "\r" << "\b" << '\r';
	}
	
}
void Panel::getInput(int& x, int& y,Board &b)
{
	
	while (true)
	{
		try
		{
			cout << "��������������,�м��Կո������ע�ⷶΧ: x,y = ";
			cin >> x >> y;
			cin.clear();
			while (cin.get() != '\n')
				continue;

			if (x >= b.getSize() || x < 0 || y >= b.getSize() || y < 0)
			{
				clearLine(1);
				cout << "�Ƿ����롣";
				continue;
			}
			if (b.getPlayerCode(x, y) != 0)
			{
				clearLine(1);
				cout << "�ô��Ѿ������ˡ�";
				continue;
			}
			break;
		}
		catch (exception& e)
		{
			clearLine(1);
			cout << "�Ƿ����롣";
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
	}
	
	

	
}