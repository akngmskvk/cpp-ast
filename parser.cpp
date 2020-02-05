#include "parser.h"

Parser::Parser(string inputStr)
{
    m_text = inputStr;
    m_index = 0;
}

ASTNode* Parser::parseTest()
{
    getToken();

    return expression();
}

int Parser::toIntFromChar(char value)
{
    return ((int)(value) - 48);
}

ASTNode* Parser::expression()
{
    ASTNode* termNode = term();
    ASTNode* expression1Node = expression1();

    return createNode(ASTNodeType::OperatorPlus, termNode, expression1Node);
}

ASTNode* Parser::expression1()
{
    ASTNode* termNode;
    ASTNode* expression1Node;

    switch (m_token.Type)
    {
        case TokenType::Plus:
        {
            getToken();
            termNode = term();
            expression1Node = expression1();

            return createNode(ASTNodeType::OperatorPlus, expression1Node, termNode);
        }
        case TokenType::Minus:
        {
            getToken();
            termNode = term();
            expression1Node = expression1();

            return createNode(ASTNodeType::OperatorMinus, expression1Node, termNode);
        }
        default:
            break;
    }

    return createNumberNode(0);
}

ASTNode* Parser::term()
{
    ASTNode* factorNode = factor();
    ASTNode* term1Node = term1();

    return createNode(ASTNodeType::OperatorMul, factorNode, term1Node);
}

ASTNode* Parser::term1()
{
    ASTNode* factorNode;
    ASTNode* term1Node;

    switch (m_token.Type)
    {
        case TokenType::Mul:
        {
            getToken();
            factorNode = factor();
            term1Node = term1();

            return createNode(ASTNodeType::OperatorMul, term1Node, factorNode);
        }
        case TokenType::Div:
        {
            getToken();
            factorNode = factor();
            term1Node = term1();

            return createNode(ASTNodeType::OperatorDiv, term1Node, factorNode);
        }
        default:
            break;
    }

    return createNumberNode(1);
}

ASTNode* Parser::factor()
{
    ASTNode* node;

    switch (m_token.Type)
    {
        case TokenType::LeftParenthesis:
        {
            getToken();
            node = expression();
            match(')');

            return node;
        }
        case TokenType::Minus:
        {
            getToken();
            // negative input is explored
            throw ParserException(m_text, m_index, ParserExceptionType::NegativeInput);
            factor();
            break;
        }
        case TokenType::Number:
        {
            int value = m_token.Value;
            getToken();
            // large input is explored
            if (m_token.Type == TokenType::Number)
            {
                throw ParserException(m_text, m_index, ParserExceptionType::LargeInput);
            }

            return createNumberNode(value);
        }
        default:
        {
            // unexpected token is explored
            throw ParserException(m_text, m_index, ParserExceptionType::UnexpectedInput);
            break;
        }
    }
}

void Parser::match(char expectedValue)
{
    if (m_text.at(m_index-1) == expectedValue)
    {
        getToken();
    }
    else
    {
        // unexpected token is explored
        throw ParserException(m_text, m_index, ParserExceptionType::UnexpectedInput);
    }
}

ASTNode* Parser::createNode(ASTNodeType nodeType, ASTNode *leftChild, ASTNode *rightChild)
{
    ASTNode* node = new ASTNode;
    node->setNodeType(nodeType);
    node->setLeftChild(leftChild);
    node->setRightChild(rightChild);

    return node;
}

ASTNode* Parser::createNumberNode(int nodeValue)
{
    ASTNode* node = new ASTNode;
    node->setNodeType(ASTNodeType::NumberValue);
    node->setNodeValue(nodeValue);

    return node;
}

void Parser::getToken()
{
     // check for end of the text
     if (m_index == m_text.size())
     {
         m_token.Type = TokenType::EndOfText;
         return;
     }

    // skip whitespaces
    while (isspace(m_text.at(m_index)))
    {
        m_index++;
    }

    m_token.Value = 0;
    m_token.Symbol = 0;

    // check if there is a digit at the current index
    if(isdigit(m_text.at(m_index)))
    {
        m_token.Type = TokenType::Number;
        m_token.Value = toIntFromChar(m_text.at(m_index));
        m_index++;
        return;
    }

    m_token.Type = TokenType::Error;

    // check if there is an operator or paranthesis at the current index
    switch (m_text[m_index])
    {
        case '+':
            m_token.Type = TokenType::Plus;
            break;
        case '-':
            m_token.Type = TokenType::Minus;
            break;
        case '*':
            m_token.Type = TokenType::Mul;
            break;
        case '/':
            m_token.Type = TokenType::Div;
            break;
        case '(':
            m_token.Type = TokenType::LeftParenthesis;
            break;
        case ')':
            m_token.Type = TokenType::RightParenthesis;
            break;
        default:
            break;
    }

    if (m_token.Type != TokenType::Error)
    {
        m_token.Symbol = m_text.at(m_index);
        m_index++;
    }
    else
    {
        // unexpected token is explored
        throw ParserException(m_text, m_index, ParserExceptionType::UnexpectedInput);
    }
}
