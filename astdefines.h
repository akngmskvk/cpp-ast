#ifndef ASTDEFINES_H
#define ASTDEFINES_H

enum TokenType
{
   Number,
   Plus,
   Minus,
   Mul,
   Div,
   EndOfText,
   LeftParenthesis,
   RightParenthesis,
   Error
};

struct Token
{
   TokenType    Type;
   int          Value;
   char         Symbol;

   Token():Type(Error), Value(0), Symbol(0)
   {}
};

enum ASTNodeType
{
    Undefined,
    NumberValue,
    OperatorPlus,
    OperatorMinus,
    OperatorMul,
    OperatorDiv
};

#endif // ASTDEFINES_H
