#include "../include/Pattern.h"
#include "../include/STD.h"

//初始化
Pattern PatternList::list_p[7];
int PatternList::scoreList[7]={0};
//2是自己，1是对手,0是没有
void PatternList::initPattern()
{
    //0:活4,1:死4,2:活3，3:活2，4:死3，5:死2，6:其他
	Pattern v4, d4, v3, v2, d3, d2, other;


	v4.index = 0;
	v4.order.push_back("022220");//_●●●●_

	d4.index = 1;
	d4.order.push_back("022221");//_●●●●○
	d4.order.push_back("20222");//●_●●●
	d4.order.push_back("22022");// ●●_●●

	v3.index = 2;
	v3.order.push_back("02220");//_●●●_
	v3.order.push_back("020220");//_●_●●_

	v2.index = 3;
	v2.order.push_back("002200");//_ _●●_ _
	v2.order.push_back("02020");//_●_● _
	v2.order.push_back("020020");//_●_ _●_

	d3.index = 4;
	d3.order.push_back("02221");//_●●●○
	d3.order.push_back("020221");//_●_●●○
	d3.order.push_back("022021");//_●●_●○
	d3.order.push_back("20022");//●_ _●●
	d3.order.push_back("20202");//●_●_●
	d3.order.push_back("1022201");//○_●●●_○

	d2.index = 5;
	d2.order.push_back("000221");//_ _ _●●○
	d2.order.push_back("002021");//_ _●_●○
	d2.order.push_back("020021");//_●_ _●○
	d2.order.push_back("20002");//●_ _ _●


	PatternList::list_p[0] = v4;
	PatternList::list_p[1] = d4;
	PatternList::list_p[2] = v3;
	PatternList::list_p[3] = v2;
	PatternList::list_p[4] = d3;
	PatternList::list_p[5] = d2;
	PatternList::list_p[6] = other;

	scoreList[0] = 8000;
	scoreList[1] = 5000;
	scoreList[2] = 4000;
	scoreList[3] = 3000;
	scoreList[4] = 2000;
	scoreList[5] = 1000;
	scoreList[6] = 100;
}

int PatternList::getScore(int patternCode)
{
	return scoreList[patternCode];
}

bool PatternList::isMatch(string str, int patternCode)
{
	//较小的一个
	bool isMatch = true;
	for (int j = 0; j < list_p[patternCode].order.size(); j++) {
		const string &order = list_p[patternCode].order.at(j);
		int limit = str.size() <order.size() ? str.size() : order.size();
		int index = str.find_first_of(order.at(0));
		for (int i = 0; i < limit; i++)
		{
			if (str.at(i + index) != order.at(i))
				isMatch = false;
		}
		if(isMatch)return true;
	}
	return false;
}
