#ifndef PARSER_H
#define PARSER_H

#include <iostream>

#include "astdefines.h"
#include "parserexception.h"

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

//class ParserException : public exception
//{
//public:
//    ParserException(const string& message, int pos);
//    int m_pos;
//    string m_message;

//};

#endif // PARSER_H
