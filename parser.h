#ifndef PARSER_H
#define PARSER_H

#include <iostream>

#include "astdefines.h"

using namespace std;

class Parser
{
public:
    Parser(string inputStr);
    void parseTest();

private:
    int toIntFromChar(char value);

    void expression();
    void expression1();
    void term();
    void term1();
    void factor();
    void match(char expectedValue);

    void getToken();

public:
    Token m_token;
    string m_text;
    size_t m_index;

};

#endif // PARSER_H
