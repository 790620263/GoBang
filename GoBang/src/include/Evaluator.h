#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Board.h"
#include "Position.h"

class Evaluator
{
    public:
        virtual int evaluate(Board& b,const int x,const int y,const int playerCode);
        virtual void getBestPosition(Board& b,const int &x,const int &y,const int &playerCode,int &score);
        static Position* getAvailablePosition(Board& b,int &size);
    protected:

    private:
};

#endif // EVALUATOR_H
