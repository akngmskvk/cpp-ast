#ifndef PARSEREXCEPTION_H
#define PARSEREXCEPTION_H

#include <iostream>

using namespace std;

class ParserException : public exception
{
public:
    ParserException(const string& message, size_t pos);
};

#endif // PARSEREXCEPTION_H
