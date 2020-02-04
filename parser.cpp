#include "parser.h"

//#define DEBUG_FUNCTION 1

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
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    ASTNode* termNode = term();
    ASTNode* expression1Node = expression1();

    return createNode(OperatorPlus, termNode, expression1Node);
}

ASTNode* Parser::expression1()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    ASTNode* termNode;
    ASTNode* expression1Node;

    switch (m_token.Type)
    {
        case Plus:
        {
            getToken();
            termNode = term();
            expression1Node = expression1();

            return createNode(OperatorPlus, expression1Node, termNode);
        }
        case Minus:
        {
            getToken();
            termNode = term();
            expression1Node = expression1();

            return createNode(OperatorMinus, expression1Node, termNode);
        }
        default:
            break;
    }

    return createNumberNode(0);
}

ASTNode* Parser::term()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    ASTNode* factorNode = factor();
    ASTNode* term1Node = term1();

    return createNode(OperatorMul, factorNode, term1Node);
}

ASTNode* Parser::term1()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    ASTNode* factorNode;
    ASTNode* term1Node;

    switch (m_token.Type)
    {
        case Mul:
        {
            getToken();
            factorNode = factor();
            term1Node = term1();

            return createNode(OperatorMul, term1Node, factorNode);
        }
        case Div:
        {
            getToken();
            factorNode = factor();
            term1Node = term1();

            return createNode(OperatorDiv, term1Node, factorNode);
        }
        default:
            break;
    }

    return createNumberNode(1);
}

ASTNode* Parser::factor()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    ASTNode* node;

    switch (m_token.Type)
    {
        case LeftParenthesis:
        {
            getToken();
            node = expression();
            match(')');

            return node;
        }
        case Minus:
        {
            getToken();
            // negative input is explored
            throw ParserException(m_text, m_index, NegativeInput);
            factor();
            break;
        }
        case Number:
        {
            int value = m_token.Value;
            getToken();
            // large input is explored
            if (m_token.Type == Number)
            {
                throw ParserException(m_text, m_index, LargeInput);
            }

            return createNumberNode(value);
        }
        default:
        {
            // unexpected token is explored
#ifdef DEBUG_FUNCTION
            cout << "Error in " << __FUNCTION__ << endl;
#endif
            throw ParserException(m_text, m_index, UnexpectedInput);
            break;
        }
    }
}

void Parser::match(char expectedValue)
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    if (m_text.at(m_index-1) == expectedValue)
    {
        getToken();
    }
    else
    {
        // unexpected token is explored
#ifdef DEBUG_FUNCTION
        cout << "Error in " << __FUNCTION__ << endl;
        cout << "Expected token \"" << expectedValue << "\" at position " << m_index << endl;
#endif
        throw ParserException(m_text, m_index, UnexpectedInput);
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
    node->setNodeType(NumberValue);
    node->setNodeValue(nodeValue);

    return node;
}

void Parser::getToken()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

     // check for end of the text
     if (m_index == m_text.size())
     {
         m_token.Type = EndOfText;
         return;
     }

#ifdef DEBUG_FUNCTION
    cout << "Value in " << __FUNCTION__ << " is " << m_text.at(m_index) << endl;
#endif

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
        m_token.Type = Number;
        m_token.Value = toIntFromChar(m_text.at(m_index));
        m_index++;
        return;
    }

    m_token.Type = Error;

    // check if there is an operator or paranthesis at the current index
    switch (m_text[m_index])
    {
        case '+':
            m_token.Type = Plus;
            break;
        case '-':
            m_token.Type = Minus;
            break;
        case '*':
            m_token.Type = Mul;
            break;
        case '/':
            m_token.Type = Div;
            break;
        case '(':
            m_token.Type = LeftParenthesis;
            break;
        case ')':
            m_token.Type = RightParenthesis;
            break;
        default:
            break;
    }

    if (m_token.Type != Error)
    {
        m_token.Symbol = m_text.at(m_index);
        m_index++;
    }
    else
    {
        // unexpected token is explored
#ifdef DEBUG_FUNCTION
        cout << "Error in " << __FUNCTION__ << endl;
#endif
        throw ParserException(m_text, m_index, UnexpectedInput);
    }
}
