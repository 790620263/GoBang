#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "Board.h"

class Evaluator
{
    public:
        Evaluator();
        virtual ~Evaluator();
        int evaluate(Board& b,int x,int y,int playerCode);
        void getBestPosition(Board& b,int &x,int &y,int &playerCode,int &score);
    protected:

    private:
};

#endif // EVALUATOR_H
