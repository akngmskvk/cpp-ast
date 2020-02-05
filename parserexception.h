#ifndef PARSEREXCEPTION_H
#define PARSEREXCEPTION_H

#include <iostream>

using namespace std;

enum ParserExceptionType
{
    LargeInput,
    NegativeInput,
    UnexpectedInput
};

class ParserException : public exception
{
public:
    ParserException(const string& message, size_t pos, ParserExceptionType type);
};

#endif // PARSEREXCEPTION_H
