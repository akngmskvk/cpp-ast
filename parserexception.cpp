#include "parserexception.h"

ParserException::ParserException(const string &message, size_t pos, ParserExceptionType type)
{
    switch (type)
    {
        case ParserExceptionType::LargeInput:
            cout << "The input '" << message << "' is invalid (literal is too large)" << endl;
            break;
        case ParserExceptionType::NegativeInput:
            cout << "The input '" << message << "' is invalid (either negative literal or unary minus)" << endl;
            break;
        case ParserExceptionType::UnexpectedInput:
            cout << "The input '" << message << "' is invalid (unexpected token)" << endl;
            break;
        default:
            break;
    }
}
