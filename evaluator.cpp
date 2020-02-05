#include "evaluator.h"

Evaluator::Evaluator()
{

}

double Evaluator::evaluateTree(ASTNode *astRoot)
{
    if (astRoot == NULL)
    {
        throw EvaluatorException();
    }
    if (astRoot->getNodeType() == ASTNodeType::NumberValue)
    {
        return astRoot->getNodeValue();
    }
    else
    {
        double v1 = evaluateTree(astRoot->getLeftChild());
        double v2 = evaluateTree(astRoot->getRightChild());

        switch (astRoot->getNodeType())
        {
            case ASTNodeType::OperatorPlus:
            {
                return v1 + v2;
            }
            case ASTNodeType::OperatorMinus:
            {
                return v1 - v2;
            }
            case ASTNodeType::OperatorMul:
            {
                return v1 * v2;
            }
            case ASTNodeType::OperatorDiv:
            {
                return v1 / v2;
            }
            default:
                break;
        }
    }

    throw EvaluatorException();
}

int Evaluator::evaluate(ASTNode *astRoot)
{
    if (astRoot == NULL)
    {
        throw EvaluatorException();
    }

    return (int)(evaluateTree(astRoot));
}
