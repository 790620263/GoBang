#include "../include/MultiGreedyEvaluator.h"
#include "../include/VictoryCheeker.h"
#include <map>


void MultiGreedyEvaluator::getBestPosition(Board& b,  int& x,  int& y, const int playerCode, int& score)
{
	//�˴���playerCode��Ϊ����
	aiCode= playerCode;
	getBestPosi_DeepSearch(b, x, y, score);
}
//��������÷�

//void MultiGreedyEvaluator::getBestPosi_DeepSearch(Board& b, int &x, int &y, const int playerCode, int nowDeep, int& score)
//{
//	//�ﵽ������ȣ����Ѿ���ʤ
//	if (nowDeep == defaultSearchDeep || VictoryCheeker::have_five(b,x,y,playerCode))//|| VictoryCheeker::isFull(b))
//	{
//		//score=seva.evaluate(b, x, y, playerCode);//������AI
//		seva.getBestPosition(b, x, y, playerCode, score);//����singleEvaluator����������
//
//		//�����ʤ��Խ�죬��ò���Խ�á�
//		score += score << (defaultSearchDeep - nowDeep);
//		return;
//	}
//
//	int psize;
//	Position* plist = Evaluator::getAvailablePosition(b, psize);
//
//	int opponentCode = playerCode == 1 ? 2 : 1;//���ֵı��
//	int tmp_score,tmp_score2,tmp_x,tmp_y;
//
//	score = -1000000;
//	nowDeep++;
//	for (int i = 0; i < psize; i++)
//	{
//		Position& p = plist[i];
//
//		//�����״̬��
//		b.setPlayerCode(p.x, p.y, playerCode);
//		//����״̬����������ø���״̬������
//		getBestPosi_DeepSearch(b, tmp_x, tmp_y, opponentCode, nowDeep, tmp_score);
//		seva.getBestPosition(b, tmp_x, tmp_y, opponentCode, tmp_score2);
//		tmp_score += tmp_score2;
//
//		
//
//		//��score����Ϊ�������֡�
//		if (tmp_score > score)
//		{
//			score = tmp_score;
//			x = tmp_x; y = tmp_y;
//		}
//
//		//��ԭBoard����ʹ�����ã���ͷ��βֻ��Ҫһ��Board�����������Ա��⹹�졢�����µ�Board�������������Ч�ʣ�
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

//ȫģʽƥ��ķ������ں�ʱ���޷�Ӧ�Զ�������//(��AIԽ�������÷�Խ��
int MultiGreedyEvaluator::fastEvaluate_state(Board& b,const int playerCode)
{
	
	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);

	int max=-100000000; int score = 0;
	int opponentCode = playerCode == 1 ? 2 : 1;//���ֵı��

	for (int i = 0; i < psize; i++)
	{
		//����ÿ����ĵ÷�
		//�ȼ򵥷�װһЩsingleEvaluator��eva�������Ժ���д����ƥ��
		score = seva.evaluate(b, plist[i].x, plist[i].y, playerCode) + seva.evaluate(b, plist[i].x, plist[i].y, opponentCode);

		max = max(max, score);
	}

	delete[] plist;

	if (playerCode == aiCode)return max;
	else return -max;
}

int MultiGreedyEvaluator::evaluate_state_tree(Board& b, int nowDeep, const int playerCode)
{

	int opponentCode = playerCode == 1 ? 2 : 1;//���ֵı��

	//�ﵽ������ȣ����Ѿ���ʤ
	if (nowDeep == defaultSearchDeep||VictoryCheeker::have_five(b,playerCode) )//|| VictoryCheeker::isFull(b))
	{
		int score = fastEvaluate_state(b, playerCode);
		//�����ʤ��Խ�죬��ò���Խ�á�
		score += score << (defaultSearchDeep - nowDeep);
		return score;
	}
	nowDeep++;


	int psize;
	Position* plist = Evaluator::getAvailablePosition(b, psize);


	int sub_score, score, tmp_x, tmp_y;


	if (playerCode == aiCode)//�ҷ�����
	{
		score = -100000000;
		for (int i = 0; i < psize; i++)
		{
			Position& p = plist[i];

			//�����״̬��
			b.setPlayerCode(p.x, p.y, playerCode);

			//����״̬����������ø���״̬������
			sub_score = evaluate_state_tree(b, nowDeep, opponentCode);

			//���ص÷������߷�(��AIԽ�������÷�Խ��
			if (sub_score > score)
			{
				score = sub_score;
			}

			//��ԭBoard����ʹ�����ã���ͷ��βֻ��Ҫһ��Board�����������Ա��⹹�졢�����µ�Board�������������Ч�ʣ�
			b.setPlayerCode(p.x, p.y, 0);
		}
	}
	else//�Է�����
	{
		score = 100000000;
		for (int i = 0; i < psize; i++)
		{
			Position& p = plist[i];

			//�����״̬��
			b.setPlayerCode(p.x, p.y, playerCode);

			//����״̬����������ø���״̬������
			sub_score = evaluate_state_tree(b, nowDeep, opponentCode);

			//���ص÷���С���߷�(��AIԽ�������÷�Խ��
			if (sub_score < score)
			{
				score = sub_score;
			}

			//��ԭBoard����ʹ�����ã���ͷ��βֻ��Ҫһ��Board�����������Ա��⹹�졢�����µ�Board�������������Ч�ʣ�
			b.setPlayerCode(p.x, p.y, 0);
		}
	}

	delete[] plist;
	return score;
}
