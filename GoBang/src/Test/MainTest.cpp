#include "../include/Manage.h"
#include <iostream>
int main()
{
	Manager m;
	//m.ai_vs_peo();
	int bwin = 0, wwin = 0, nowin = 0;
	for (int i = 0; i < 100; i++)
	{
		int code= m.ai_vs_ai();
		if (code == -1)
		{
			nowin++;
		}
		else if (code == 1)
		{
			wwin++;
		}
		else bwin++;
			m.resetBoard();
	}
	std::cout << "ºÚ" << bwin << "  °×" << wwin << "  Æ½" << nowin;
}