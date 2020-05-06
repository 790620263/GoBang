#include "../include/SingleEvaluator.h"
#include "../include/Board.h"
#include "../include/VictoryCheeker.h"
#include <iostream>

SingleEvaluator::SingleEvaluator()
{
   
}

SingleEvaluator::~SingleEvaluator()
{
    //dtor
}



//核心
//评估器，返回代号为playerCode的玩家在该点处的评分（不考虑对手）
int SingleEvaluator::evaluate(Board& b, const int x, const int y, const int playerCode)
{
    if (b.getPlayerCode(x, y) != 0)return -100000000;
    if(VictoryCheeker::have_five(b,x,y,playerCode))return 100000000;//5个子
    
    bool matchLeft = true,matchRight= true;
    int code = 0; int score = 0;

    int matched[SingleEvaluator::SCORE_NUM] = { 0 }; //matched 0,1,2,3...依次对应不匹配，死2，活2，死3...
   
    for (int axis = 0; axis < 8;axis++) {
        for (int index = 0; index < PATTERN_NUM; index++)
        {
            const Pattern &p = patlist[index];//必须用引用，否则构造析构会显著增加CPU负载
            matchLeft = true, matchRight = true;

            //if (x == 9 && y == 7 && p.right == "2200")
            //{
            //    if (axisList[index] == 5)
            //        code = 0;
            //}

            //偏移量从1计数
            //匹配左侧
            for (int i = 1; i <= p.left.size(); i++)
            {
                code = b.getCodeOffsetPosi(x, y,axis, -i);
                if (code != 0) code = code == playerCode ? 2 : 1;
                if (p.left.at(p.left.size() - i) - 48 != code)//前者是char类型！
                {
                    matchLeft = false;
                    break;
                }
            }
            //匹配右侧
            for (unsigned int i = 1; i <= p.right.size(); i++)
            {
                code = b.getCodeOffsetPosi(x, y,axis, i);
               if(code!=0) code = code == playerCode ? 2 : 1;
                if (p.right.at(i-1) -48!= code)//前者是char类型！
                {
                    matchRight = false;
                    break;
                }
            }
            if (matchLeft&&matchRight)
                {
                matched[p.score]++;
                    //break;
                }
        }
    }

    //匹配情况
    //活4，双死4，死4活3  
    score += matched[SCORE_V4] << 13;
    if (matched[SCORE_D4] > 1 || matched[SCORE_V3] > 0 && matched[SCORE_D4] > 0)
        score += 8192;

    score += matched[SCORE_D4] << 12;//死4 2048

    //活2死3、双活2、双死3不拦必输(等同活3）
    if (matched[SCORE_D3] > 0 && matched[SCORE_V3] > 0|| matched[SCORE_V2] > 1 || matched[SCORE_V3] > 1)
    {
        score += 1024;
    }
    if (matched[SCORE_V3] > 0 && matched[SCORE_D3] > 0)
        score += 512;
    //活3  
    score += matched[SCORE_V3] << 10;
    
    //死3 
    score += matched[SCORE_D3] << 6;
    //活2
    score+= 1+matched[SCORE_V3] << 6;
    //死2
    score += matched[SCORE_D2] << 4;


    return score;
}










//兼顾防守，进攻
void SingleEvaluator::getBestPosition(Board& b, int& x,int& y, const int& playerCode, int& score)
{
    int psize = 0;
    Position* plist = Evaluator::getAvailablePosition(b, psize);

    Position atkp, defp;
    int atkScore = -10000000, defScore=-10000000;
    int tmpscore = 0;

    int opponentCode = playerCode == 1 ? 2 : 1;

    for (int i = 0; i < psize; i++)
    {
        tmpscore = evaluate(b, plist[i].x, plist[i].y, playerCode);
        //tmpscore += getScoreByChessNum(b, plist[i].x, plist[i].y);
        //std::cout << "ATK  x,y= " << plist[i].x << '\t' << plist[i].y << "  score= " << tmpscore<< endl;
        if (tmpscore > atkScore)
        {
            atkScore = tmpscore;
            atkp = plist[i];
        }
        tmpscore = evaluate(b, plist[i].x, plist[i].y, opponentCode);
        //tmpscore += getScoreByChessNum(b, plist[i].x, plist[i].y);
        //std::cout << "DEF  x,y= " << plist[i].x << '\t' << plist[i].y << "  score= " << tmpscore << endl;
        if (tmpscore > defScore)
        {
            defScore = tmpscore;
            defp = plist[i];
        }

    }
    delete[] plist;
    if (atkScore >= defScore)
    {
        score = atkScore; 
        x = atkp.x; y = atkp.y;
    }
    else
    {
        score = defScore;
        x = defp.x; y = defp.y;
    }
}

int SingleEvaluator::getScoreByChessNum(Board& b, int x, int y)
{
    int score = 0;
    for (int axis = 0; axis < 8; axis++)
    {
        int count = 0;
        for (int i = 1; i < 5; i++)
        {
            if (b.getCodeOffsetPosi(x, y, axis, i) >0)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        //switch(count)
        score += count;
    }
    return score;
}