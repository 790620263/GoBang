#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Board.h"

class Evaluator
{
    public:
        static int evaluate(const Board& b,const int x,const int y,const int playerCode);
        static void getBestPosition(const Board& b,const int &x,const int &y,const int &playerCode,int &score);
    protected:

    private:
};

#endif // EVALUATOR_H
