#include "parserexception.h"

ParserException::ParserException(const string &message, size_t pos)
{
    cout << "Unexpected token in \"" << message << "\" character of \"" << message.at(pos) << "\" at positon " << pos << endl;;
}
