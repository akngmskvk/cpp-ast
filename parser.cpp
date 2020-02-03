#include "parser.h"

Parser::Parser(string inputStr)
{
    m_text = inputStr;
    m_index = 0;
}

int Parser::toIntFromChar(char value)
{
    return ((int)(value) - 48);
}

void Parser::getToken()
{
    // skip whitespaces
    while (isspace(m_text.at(m_index)))
    {
        m_index++;
    }

    m_token.Value = 0;
    m_token.Symbol = 0;

    // check for end of the text
    if (m_index == m_text.size())
    {
        m_token.Type = EndOfText;
        return;
    }

    // check if there is a digit at the current index
    if(isdigit(m_text.at(m_index)))
    {
        m_token.Type = Number;
        m_token.Value = toIntFromChar(m_text.at(m_index));
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
        // Unexpected input is explored
        // TODO:
        // Implement errow throwing mechanism

        cout << "Unexpected input is explored. ERROR!" << endl;
    }
}


