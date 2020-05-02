#ifndef SINGLEEVALUATOR_H
#define SINGLEEVALUATOR_H
#include "STD.h"
#include "Evaluator.h"


class SingleEvaluator : public Evaluator
{
    public:
        SingleEvaluator();
        virtual ~SingleEvaluator();
		//返回代号为playerCode的玩家在该点处的评分（不考虑对手）
        int evaluate(Board& b, const int x, const int y, const int playerCode);
        void getBestPosition(Board& b, int& x, int& y,const int& playerCode, int& score);
    protected:
		struct Pattern
		{
			string left;
			string right;
			int score = 0;
		};
		//static const int  SCORE_V5 = 1000000000;
		static const int  SCORE_V4 = 6;
		static const int  SCORE_D4 = 5;
		static const int  SCORE_V3 = 4;
		static const int  SCORE_D3 = 3;
		static const int  SCORE_V2 = 2;
		static const int  SCORE_D2 = 1;
		static const int  SCORE_OTHERS = 0;

		static const int SCORE_NUM = 7;
		static const int  PATTERN_NUM = 37;

		//*为当前位置,0为空位,1为对方,2为我方
		//此列表中，自上而下匹配优先级递减
		const Pattern patlist[PATTERN_NUM] =
		{
			  { "", "22220", SCORE_V4 },//_●●●●_

			  { "", "22221", SCORE_D4 },//_●●●●○
			  { "2", "222", SCORE_D4 },//●_●●●
			  { "22", "22", SCORE_D4 },// ●●_●●

			  { "", "2220",SCORE_V3 },//_●●●_
			  { "02", "220", SCORE_V3 },//_●_●●_
			  { "02022", "", SCORE_V3 },
			  { "", "20220", SCORE_V3 },

			  { "", "2221", SCORE_D3 },//_●●●○
			   { "02","221", SCORE_D3 },//_●_●●○
			  { "", "20221", SCORE_D3 },
			  { "", "22021", SCORE_D3 },//_●●_●○
			  { "022", "21", SCORE_D3 },
			  { "20", "22", SCORE_D3 },//●_ _●●
			  { "2", "022", SCORE_D3 },
			  { "2", "202", SCORE_D3 },//●_●_●

			  { "0", "2200", SCORE_V2 },//_ _●●_ _
			  { "", "02200", SCORE_V2 },
			  { "", "22000", SCORE_V2 },//_ ●●_ _ _
			  { "022", "00", SCORE_V2 },
			  { "0220", "0", SCORE_V2 },
			   { "02200", "", SCORE_V2 },
			  { "", "2020", SCORE_V2 },//_●_● _
			  { "02", "20", SCORE_V2 },
			   { "02", "020", SCORE_V2 },//_●_ _●_
			  { "", "20020", SCORE_V2 },

			   { "00", "221", SCORE_D2 },//_ _ _●●○
			  { "0", "0221", SCORE_D2 },
			 { "", "00221", SCORE_D2 },

			  { "", "02021", SCORE_D2 },//_ _●_●○
			  { "0", "2021", SCORE_D2 },
			  { "002", "21", SCORE_D2 },
			  { "", "20021", SCORE_D2 },//_●_ _●○
			  { "02", "021", SCORE_D2 },
			  { "020", "21", SCORE_D2 },
			  { "2", "002", SCORE_D2 },//●_ _ _●
			  { "20", "02", SCORE_D2 },


		};

    private:
		int getScoreByChessNum(Board& b, int x, int y);
};

#endif // SINGLEEVALUATOR_H
