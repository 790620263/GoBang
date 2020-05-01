#include "../include/SingleEvaluator.h"
#include "../include/Board.h"
#include "../include/Pattern.h"
#include <iostream>
SingleEvaluator::SingleEvaluator()
{
    //ctor
}

SingleEvaluator::~SingleEvaluator()
{
    //dtor
}
int SingleEvaluator::evaluate(Board& b, const int x, const int y, const int playerCode)
{
    if (b.getPlayerCode(x, y) != 0)return -100000000;
    //const int arrSize = 5;
    //char left[arrSize] = { 0 };
    //int leftAvailable = 0;int rightAvailable = 0;
    //int leftLimit = 5; int rightLimit = 5;

    bool matchLeft = true,matchRight= true, matchNoPattern = true;
    int code=0;
    int score = 0;
    for (int axis = 0; axis < 8; axis++) {
        matchNoPattern = true;
        for (int index = 0; index < PATTERN_NUM; index++)
        {
            Pattern p = patlist[index];
            matchLeft = true, matchRight = true;

            if (x == 9 && y == 7 && p.right == "2200")
            {
                if (axis == 5)
                    code = 0;
            }

            //偏移量从1计数
            //匹配左侧
            for (int i = 1; i <= p.left.size(); i++)
            {
                code = b.getCodeOffsetPosi(x, y, axis, -i);
                if (code != 0) code = code == playerCode ? 2 : 1;
                if (p.left.at(p.left.size() - i) - 48 != code)//前者是char类型！
                {
                    matchLeft = false;
                    break;
                }
            }
            //匹配右侧
            for (int i = 1; i <= p.right.size(); i++)
            {
                code = b.getCodeOffsetPosi(x, y, axis, i);
               if(code!=0) code = code == playerCode ? 2 : 1;
                if (p.right.at(i-1) -48!= code)//前者是char类型！
                {
                    matchRight = false;
                    break;
                }
            }
            if (matchLeft&&matchRight)
                {
                    score += p.score;
                    matchNoPattern = false;
                    break;
                }
        }
        //全都不匹配
        if (matchNoPattern) 
            score += SCORE_OTHERS;
   
    }
    return score;
}

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
        tmpscore += getScoreByChessNum(b, plist[i].x, plist[i].y);
        std::cout << "ATK  x,y= " << plist[i].x << '\t' << plist[i].y << "  score= " << tmpscore<< endl;
        if (tmpscore > atkScore)
        {
            atkScore = tmpscore;
            atkp = plist[i];
        }
        tmpscore = evaluate(b, plist[i].x, plist[i].y, opponentCode);
        tmpscore += getScoreByChessNum(b, plist[i].x, plist[i].y);
        std::cout << "DEF  x,y= " << plist[i].x << '\t' << plist[i].y << "  score= " << tmpscore << endl;
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