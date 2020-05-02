#include "../include/MultiGreedyEvaluator.h"
#include "../include/VictoryCheeker.h"
#include <map>


void MultiGreedyEvaluator::getBestPosition(Board& b,  int& x,  int& y, const int playerCode, int& score)
{
	//此处的playerCode记为电脑
	aiCode= playerCode;
	getBestPosi_DeepSearch(b, x, y, score);
}
//评估局面得分

//void MultiGreedyEvaluator::getBestPosi_DeepSearch(Board& b, int &x, int &y, const int playerCode, int nowDeep, int& score)
//{
//	//达到搜索深度，或已经获胜
//	if (nowDeep == defaultSearchDeep || VictoryCheeker::have_five(b,x,y,playerCode))//|| VictoryCheeker::isFull(b))
//	{
//		//score=seva.evaluate(b, x, y, playerCode);//进攻性AI
//		seva.getBestPosition(b, x, y, playerCode, score);//调用singleEvaluator的评估函数
//
//		//如果获胜的越快，则该策略越好。
//		score += score << (defaultSearchDeep - nowDeep);
//		return;
//	}
//
//	int psize;
//	Position* plist = Evaluator::getAvailablePosition(b, psize);
//
//	int opponentCode = playerCode == 1 ? 2 : 1;//对手的编号
//	int tmp_score,tmp_score2,tmp_x,tmp_y;
//
//	score = -1000000;
//	nowDeep++;
//	for (int i = 0; i < psize; i++)
//	{
//		Position& p = plist[i];
//
//		//获得子状态：
//		b.setPlayerCode(p.x, p.y, playerCode);
//		//将子状态传给自身，获得该子状态的评分
//		getBestPosi_DeepSearch(b, tmp_x, tmp_y, opponentCode, nowDeep, tmp_score);
//		seva.getBestPosition(b, tmp_x, tmp_y, opponentCode, tmp_score2);
//		tmp_score += tmp_score2;
//
//		
//
//		//将score设置为最大的评分。
//		if (tmp_score > score)
//		{
//			score = tmp_score;
//			x = tmp_x; y = tmp_y;
//		}
//
//		//还原Board：（使用引用，从头到尾只需要一个Board对象，这样可以避免构造、析构新的Board，可以显著提高效率）
//		b.setPlayerCode(p.x, p.y, 0);
//	}
//
//}

void MultiGreedyEvaluator::getBestPosi_DeepSearch(Board& b, int& x, int& y,int &score)
{
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);

	for (int i = 0; i < psize; i++)
	{
		int tmp_score = evaluate_state_tree(b, 1, aiCode);
		if (score < tmp_score)
		{
			score = tmp_score;
			x = plist[i].x; y = plist[i].y;
		}
	}
	delete[] plist;
}

//全模式匹配的方法过于耗时，无法应对多轮搜索//(对AI越有利，得分越大）
int MultiGreedyEvaluator::fastEvaluate_state(Board& b,const int playerCode)
{
	
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);

	int max=-100000000; int score = 0;
	int opponentCode = playerCode == 1 ? 2 : 1;//对手的编号

	for (int i = 0; i < psize; i++)
	{
		//评估每个点的得分
		//先简单封装一些singleEvaluator的eva方法，以后再写快速匹配
		score = seva.evaluate(b, plist[i].x, plist[i].y, playerCode) + seva.evaluate(b, plist[i].x, plist[i].y, opponentCode);

		max = max(max, score);
	}

	delete[] plist;

	if (playerCode == aiCode)return max;
	else return -max;
}

int MultiGreedyEvaluator::evaluate_state_tree(Board& b, int nowDeep, const int playerCode)
{

	int opponentCode = playerCode == 1 ? 2 : 1;//对手的编号

	//达到搜索深度，或已经获胜
	if (nowDeep == defaultSearchDeep||VictoryCheeker::have_five(b,playerCode) )//|| VictoryCheeker::isFull(b))
	{
		int score = fastEvaluate_state(b, playerCode);
		//如果获胜的越快，则该策略越好。
		score += score << (defaultSearchDeep - nowDeep);
		return score;
	}
	nowDeep++;


	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);


	int sub_score, score, tmp_x, tmp_y;


	if (playerCode == aiCode)//我方走棋
	{
		score = -100000000;
		for (int i = 0; i < psize; i++)
		{
			Position& p = plist[i];

			//获得子状态：
			b.setPlayerCode(p.x, p.y, playerCode);

			//将子状态传给自身，获得该子状态的评分
			sub_score = evaluate_state_tree(b, nowDeep, opponentCode);

			//返回得分最大的走法(对AI越有利，得分越大）
			if (sub_score > score)
			{
				score = sub_score;
			}

			//还原Board：（使用引用，从头到尾只需要一个Board对象，这样可以避免构造、析构新的Board，可以显著提高效率）
			b.setPlayerCode(p.x, p.y, 0);
		}
	}
	else//对方走棋
	{
		score = 100000000;
		for (int i = 0; i < psize; i++)
		{
			Position& p = plist[i];

			//获得子状态：
			b.setPlayerCode(p.x, p.y, playerCode);

			//将子状态传给自身，获得该子状态的评分
			sub_score = evaluate_state_tree(b, nowDeep, opponentCode);

			//返回得分最小的走法(对AI越有利，得分越大）
			if (sub_score < score)
			{
				score = sub_score;
			}

			//还原Board：（使用引用，从头到尾只需要一个Board对象，这样可以避免构造、析构新的Board，可以显著提高效率）
			b.setPlayerCode(p.x, p.y, 0);
		}
	}

	delete[] plist;
	return score;
}
