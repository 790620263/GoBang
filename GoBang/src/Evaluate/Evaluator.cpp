#include "../include/Evaluator.h"
#include "../include/Pattern.h"


Evaluator::Evaluator()
{
}

Evaluator::~Evaluator()
{
}

//2是自己，1是对手,0是没有
int Evaluator::evaluate(const Board& b, const int x, const int y, const int playerCode)
{
	return 0;
}
void Evaluator::getBestPosition(const Board& b, const int& x, const int& y, const int& playerCode, int& score)
{
}
//KEY，估值函数，匹配各种棋势
