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
    int code;
    int score = 0;
    for (int axis = 0; axis < 8; axis++) {//@TODO:
        //leftAvailable = 0;
        //rightAvailable = 0;
        //for (int i = 0; i < arrSize; i++)
        //{
        //    left[i] = b.getCodeOffsetPosi(x, y, axis, i);
        //    leftAvailable++;
        //}
        matchNoPattern = true;
        for (int index = 0; index < PATTERN_NUM; index++)
        {
            Pattern p = patlist[index];
            matchLeft = true, matchRight = true;

            //偏移量从1计数
            for (int i = 1; i <= p.left.size(); i++)
            {
                if (code != 0) code = code == playerCode ? 2 : 1;
                code = code == playerCode ? 2 : 1;
                if (p.left.at(p.left.size() - i) - 48 != code)//前者是char类型！
                {
                    matchLeft = false;
                    break;
                }
            }
            if (x == 0 && y == 0 && p.right == "2200"&&axis==4)
            {
                code = 0;
            }
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
            if (matchLeft) 
                if (matchRight)
                {
                    score += p.score;
                    matchNoPattern = false;
                    break;
                }
        }
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
    if (atkScore > defScore)
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
        for (int i = 1; i < 6; i++)
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