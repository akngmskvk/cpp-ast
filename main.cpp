#include <QCoreApplication>
#include <iostream>
#include <string>

#include "evaluator.h"
#include "parser.h"

using namespace std;

void test(string text)
{
    Parser m_parser(text);
    try
    {
        ASTNode* node = m_parser.parseTest();

        try
        {
            Evaluator evalutor;
            cout << "⚫ " << text << " = " << evalutor.evaluate(node) << endl;
        }
        catch (EvaluatorException& ex)
        {

        }

        // print the representation of AST
//        node->print2D();
        delete node;
    }
    catch (ParserException& ex)
    {

    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test("(4 + 5 * (7 - 3)) - 2");
    test("4+5+7/2");
    test("10 + 1");
    test("-10");

    cout << endl << endl;

    test("3 + (7-2) * 4 / 2");
    test("12 - 1");
    test("1.5 + 2");
    test("2 + (-1)");
    test("1*5+1+1");
    test("8/(2*2)+3");
    test("130");
    test("-130");
    test("   2*9/3");
    test("2**2");
    test("M2 +4");
    test("9");

    return a.exec();
}
