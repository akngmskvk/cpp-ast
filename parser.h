#ifndef PARSER_H
#define PARSER_H

#include <iostream>

#include "astdefines.h"

using namespace std;

class Parser
{
public:
    Parser(string inputStr);

private:
    int toIntFromChar(char value);
    void getToken();

public:
    Token m_token;
    string m_text;
    size_t m_index;

};

#endif // PARSER_H
