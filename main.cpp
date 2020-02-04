#include <QCoreApplication>
#include <iostream>
#include <string>

#include "parser.h"

using namespace std;

int evaluator(ASTNode* ast)
{
    if (ast == NULL)
    {
        cout << "Null error" << endl;
        return -1;
    }
    if (ast->getNodeType() == NumberValue)
    {
        return ast->getNodeValue();
    }
    else
    {
        int v1 = evaluator(ast->getLeftChild());
        int v2 = evaluator(ast->getRightChild());

        switch (ast->getNodeType())
        {
            case OperatorPlus:
            {
                return v1 + v2;
            }
            case OperatorMinus:
            {
                return v1 - v2;
            }
            case OperatorMul:
            {
                return v1 * v2;
            }
            case OperatorDiv:
            {
                cout << "Div exp is " << v1 << " / " << v2 << " = " << v1/v2 << endl;
                return v1 / v2;
            }
            default:
                break;
        }
    }

    return -1;
}

void test(string text)
{
    Parser m_parser(text);
    try
    {
        ASTNode* node = m_parser.parseTest();
        cout << "\"" << text << "\" -->\t OK --> Result: " << evaluator(node) << endl;

        delete node;
    }
    catch (ParserException& ex)
    {
//        cout << "\"" << text << "\" -->\t NOK" << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test("4+5+7/2");
    test("(4 + 5 * (7 - 3)) - 2");
    test("10 + 1");
    test("-10");
    cout << endl;
    cout << endl;

    test("1+2+3+4");
    test("1*2*3*4");
    test("1-2-3-4");
    test("1/2/3/4");
    test("1*2+3*4");
    test("1+2*3+4");
    test("(1+2)*(3+4)");
    test("1+(2*3)*(4+5)");
    test("1+(2*3)/4+5");
    test("5/(4+3,4)/2");
    test("1 + 2.5");
    test("125");
    test("-1");
    test("-1+(-2)");
    test("-1+(-2.0)");

    test("   1*2,5");
    test("   1*2.5e2");
    test("M1 + 2.5");
    test("1 + 2&5");
    test("1 * 2.5.6");
    test("1 ** 2.5");
    test("*1 / 2.5");

    return a.exec();
}
