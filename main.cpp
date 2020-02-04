#include <QCoreApplication>
#include <iostream>
#include <string>

#include "parser.h"

using namespace std;

void test(string text)
{
    Parser m_parser(text);
    try
    {
        m_parser.parseTest();
        cout << "\"" << text << "\" -->\t OK" << endl;
    }
    catch (ParserException& ex)
    {
        cout << "\"" << text << "\" -->\t NOK" << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test("1+2+123+4");
    test("1*2*3*4");
    test("1-2-3-4");
    test("1/2/3/4");
    test("1*2+3*4");
    test("1+2*3+4");
    test("(1+2)*(3+4)");
    test("1+(2*3)*(4+5)");
    test("1+(2*3)/4+5");
    test("5/(4+3)/2");
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
