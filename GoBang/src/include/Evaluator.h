#ifndef EVALUATOR_H
#define EVALUATOR_H


class Evaluator
{
    public:
        Evaluator();
        virtual ~Evaluator();
        int evaluate(int x,int y,int playerCode);
        void getBestPosition(int &x,int &y,int &playerCode,int &score);
    protected:

    private:
};

#endif // EVALUATOR_H
