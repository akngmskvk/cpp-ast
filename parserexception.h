#ifndef PARSEREXCEPTION_H
#define PARSEREXCEPTION_H

#include <iostream>

using namespace std;

enum ExceptionType
{
    LargeInput,
    NegativeInput,
    UnexpectedInput
};

class ParserException : public exception
{
public:
    ParserException(const string& message, size_t pos, ExceptionType type);
};

#endif // PARSEREXCEPTION_H
