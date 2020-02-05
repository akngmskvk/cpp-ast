#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "astnode.h"
#include "evaluatorexception.h"

class Evaluator
{
public:
    Evaluator();
    double evaluateTree(ASTNode* astRoot);
    int evaluate(ASTNode* astRoot);
};

#endif // EVALUATOR_H
