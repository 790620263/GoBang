#ifndef _PATTERNLIST_H_
#define _PATTERNLIST_H_
#include<string>
#include<vector>
using namespace std;
struct Pattern
{
    int index = 6;//¿‡–Õ±‡∫≈ƒ¨»œother
    vector<string> order;
};
class PatternList {
private:

public:
	 static const int PATTERN_NUM = 7;
	 static Pattern list_p[7];
	 static int scoreList[7];

	 static void initPattern();
	 static int getScore(int patternCode);
	 static bool isMatch(string str, int patternCode);
};


#endif // PATTERNLIST_H_

