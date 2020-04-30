#ifndef _PATTERNLIST_H_
#define _PATTERNLIST_H_
#define SCORE_V4 10000000
#define SCORE_D4 1000000
#define SCORE_V3 100000
#define SCORE_V2 10000
#define SCORE_D3 8000
#define SCORE_D2 1000
#define SCORE_OTHERS 100
#include<string>
struct Pattern
{
	string left;
	string right;
	int score = 0;
};
//*为当前位置，0为空位，1为对方，2为我方
Pattern patlist[]=
{
	struct Pattern { left = ""; right = "22220"; score = SCORE_V4 }，//_●●●●_

	struct Pattern { left = ""; right = "22221"; score = SCORE_D4 }，//_●●●●○
	struct Pattern { left = "2"; right = "222"; score = SCORE_D4 }，//●_●●●
	struct Pattern { left = "22"; right = "22*22"; score = SCORE_D4 }，// ●●_●●
	
	struct Pattern { left = ""; right= "2220",score = SCORE_V3 }，//_●●●_
	struct Pattern { left = ""; right = "20220"; score = SCORE_V3 }，//_●_●●_
	struct Pattern { left = "02"; right = "220"; score = SCORE_V3 }，
	struct Pattern { left = "02022"; right = ""; score = SCORE_V3 }，

	struct Pattern { left = ""; right = "*2221"; score = SCORE_D3 }，//_●●●○
	struct Pattern { left = ""; right = "20221"; score = SCORE_D3 }，//_●_●●○
	struct Pattern { left = "02";right = "221"; score = SCORE_D3 }，
	struct Pattern { left = ""; right = "22021"; score = SCORE_D3 }，//_●●_●○
	struct Pattern { left = "022"; right = "21"; score = SCORE_D3 }，
	struct Pattern { left = "2"; right = "022"; score = SCORE_D3 }，//●_ _●●
	struct Pattern { left = "20"; right = "22"; score = SCORE_D3 }，
	struct Pattern { left = "2"; right = "202"; score = SCORE_D3 }，//●_●_●

	struct Pattern { left = ""; ritht = "02200"; score = SCORE_V2 }，//_ _●●_ _
	struct Pattern { left = "2"; order = "2200"; score = SCORE_V2 }，
	struct Pattern { left = ""; right = "2020"; score = SCORE_V2 }，//_●_● _
	struct Pattern { left = "02"; right = "20"; score = SCORE_V2 }，
	struct Pattern { left = ""; right = "20020"; score = SCORE_V2 }，//_●_ _●_
	struct Pattern { left = "02"; right = "020"; score = SCORE_V2 }，

	struct Pattern { left = ""; right = "00221"; score = SCORE_D2 }，//_ _ _●●○
	struct Pattern { left = "0"; right = "0221"; score = SCORE_D2 }，
	struct Pattern { left = "00"; right = "221"; score = SCORE_D2 }，
	struct Pattern { left = ""; right = "02021"; score = SCORE_D2 }，//_ _●_●○
	struct Pattern { left = "0"; right = "2021"; score = SCORE_D2 }，
	struct Pattern { left = "002"; right = "21"; score = SCORE_D2 }，
	struct Pattern { left = ""; right = "20021"; score = SCORE_D2 }，//_●_ _●○
	struct Pattern { left = "02"; right = "021"; score = SCORE_D2 }，
	struct Pattern { left = "020"; right = "21"; score = SCORE_D2 }，
	struct Pattern { left = "2"; right = "002"; score = SCORE_D2 }，//●_ _ _●
	struct Pattern { left = "20"; right = "02"; score = SCORE_D2 }，


}
#endif // PATTERNLIST_H_

