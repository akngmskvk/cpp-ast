#include "parser.h"

//#define DEBUG_FUNCTION 1

Parser::Parser(string inputStr)
{
    m_text = inputStr;
    m_index = 0;
}

void Parser::parseTest()
{
    getToken();
    expression();
}

int Parser::toIntFromChar(char value)
{
    return ((int)(value) - 48);
}

void Parser::expression()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    term();
    expression1();
}

void Parser::expression1()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    switch (m_token.Type)
    {
        case Plus:
            getToken();
            term();
            expression1();
            break;
        case Minus:
            getToken();
            term();
            expression1();
            break;
        default:
            break;
    }
}

void Parser::term()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    factor();
    term1();
}

void Parser::term1()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    switch (m_token.Type)
    {
        case Mul:
            getToken();
            factor();
            term1();
            break;
        case Div:
            getToken();
            factor();
            term1();
            break;
        default:
            break;
    }
}

void Parser::factor()
{
#ifdef DEBUG_FUNCTION
     cout << "Beginnig of the " << __FUNCTION__ << endl;
#endif

    switch (m_token.Type)
    {
        case LeftParenthesis:
            getToken();
            expression();
            match(')');
            break;
        case Minus:
            getToken();
            factor();
            break;
        case Number:
            getToken();
            break;
        default:
            // unexpected token is explored
#ifdef DEBUG_FUNCTION
            cout << "Error in " << __FUNCTION__ << endl;
#endif
            throw ParserException(m_text, m_index);
            break;
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
        throw ParserException(m_text, m_index);
    }
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
        throw ParserException(m_text, m_index);
    }
}
