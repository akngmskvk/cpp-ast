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
        cout << text << " ... OK" << endl;
    }
    catch (errc)
    {
        cout << text << " ... NOK" << endl;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test("1+2+3+4");
    test("1*2*3*4");
    test("1-2-3-4");
    test("1/2/3/4");
    test("1*2+3*4");
    test("1+2*3+4");
    test("   1*2,5");

    return a.exec();
}
