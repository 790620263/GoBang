#ifndef _PATTERNLIST_H_
#define _PATTERNLIST_H_
#define SCORE_V4 10000000;
#define SCORE_D4 1000000;
#define SCORE_V3 100000;
#define SCORE_V2 10000;
#define SCORE_D3 8000;
#define SCORE_OTHERS 1000;
#include<string>
struct Pattern
{
	string order;
	int score = 0;
};
//*为当前位置，0为空位，1为对方，2为我方
Pattern patlist[]=
{
	struct Pattern{order="*22220"，score = SCORE_V4 }，//_●●●●_

	struct Pattern{order = "*22221"，score = SCORE_D4}，//_●●●●○
	struct Pattern{order = "2*222"，score = SCORE_D4}，//●_●●●
	struct Pattern{order = "22*22"，score = SCORE_D4}，// ●●_●●
	
	struct Pattern{order = "*2220"，score = SCORE_V3}，//_●●●
	
}
#endif // PATTERNLIST_H_

