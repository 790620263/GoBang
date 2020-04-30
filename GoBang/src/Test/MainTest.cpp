#include "../include/Board.h"
#include "../include/STD.h"
#include "../include/Pattern.h"
using namespace std;
Board getB(int size);
int main()
{
	/*TEST VictoryCheeker*/
	/*int size = 5;
	Board b = getB(size);
	//std::cout << "1Ó®ÁËÂð" << VictoryCheeker::have_five(b, 4, 1, 1);
	std::cout << "1:Ó®ÁËÂð" << VictoryCheeker::isVictory(b, 1)<<endl;
	std::cout << "2:Ó®ÁËÂð" << VictoryCheeker::isVictory(b, 2) << endl;*/


	/*TEST PatternList*/
	PatternList::initPattern();
	string toCheck = "00122";
	for (int i = 0; i < PatternList::PATTERN_NUM; i++)
	{
		if (PatternList::isMatch(toCheck, i))
		{
			cout << "toCheckÆ¥Åä : " << PatternList::list_p[i].index << endl;
		}
	}

}
Board getB(int size)
{
	Board b = *new Board(size);

	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size; y++)
		{
			int code = 0;
			std::cin >>code;
			//cin.ignore(1, '\n');
			b.setPlayerCode(x, y, code);
		}
		cin.ignore(1, '\n');
	}
	b.print();
	return b;
}
