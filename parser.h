#ifndef PARSER_H
#define PARSER_H

#include <iostream>

#include "astdefines.h"
#include "astnode.h"
#include "parserexception.h"

using namespace std;

class Parser
{
public:
    Parser(string inputStr);
    ASTNode* parseTest();

private:
    int toIntFromChar(char value);

    ASTNode* expression();
    ASTNode* expression1();
    ASTNode* term();
    ASTNode* term1();
    ASTNode* factor();
    void match(char expectedValue);

    ASTNode* createNode(ASTNodeType nodeType, ASTNode* leftChild, ASTNode* rightChild);
    ASTNode* createNumberNode(int nodeValue);

    void getToken();

public:
    Token m_token;
    string m_text;
    size_t m_index;

};

#endif // PARSER_H
