#include "../include/Panel.h"
#include <iostream>
#include<iomanip>
using namespace std;


void Panel::drawBoard(Board &b) {
	clear();
	int size = b.getSize();

	cout << setw(5) << '\\';
	for (int x = 0; x < size; x++)
	{
		cout << setw(5) << x;
	}
	cout << endl;
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
				cout << '○';
				break;
			case BLACK :
				cout << '●';
			}
		}
	}
}
void Panel::drawScore(int x,int y,int score) {
	cout << "落子位置：" << setw(5) << x << setw(5) << y << "，Score= " << score << endl;
}
void Panel::printMsg(std::string msg)
{
	cout << msg << endl;
}
void Panel::clear() {
	system("cls");
}
void Panel::clearLine(int lineNum) {
	for (int i = 0; i < lineNum; i++)
	{
		cout << '\r' << '\b'<<'\r';
	}
}
void Panel::getInput(int& x, int& y,int boardSize)
{
	cout << "请输入落子坐标,中间以空格隔开: x,y = ";
	cin >> x >> y;
	cin.ignore(100, '\n');
	cout << endl;
	while (x >= boardSize || x < 0 || y >= boardSize || y < 0)
	{
		clearLine(1);
		cout<<endl<< "格式错误。请重新输入落子坐标,中间以空格隔开: x,y = ";
		cin >> x >> y;
		cin.ignore(100, '\n');
		cout << endl;
	}

}