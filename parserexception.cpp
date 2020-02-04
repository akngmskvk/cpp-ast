#include "parserexception.h"

ParserException::ParserException(const string &message, size_t pos, ExceptionType type)
{
    switch (type)
    {
        case ExceptionType::LargeInput:
            cout << "The input '" << message << "' is invalid (literal is too large)" << endl;
            break;
        case ExceptionType::NegativeInput:
            cout << "The input '" << message << "' is invalid (either negative literal or unary minus)" << endl;
            break;
        case ExceptionType::UnexpectedInput:
            cout << "The input '" << message << "' is invalid (unexpected token)" << endl;
            break;
        default:
            break;
    }
}
