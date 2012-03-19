//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack


#include "expressions.h"

///Constructs a new expression
BaseExpression::BaseExpression()
{
    mLeft = mRight = 0;
}

///Constructs an expression from two sides
BaseExpression::BaseExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destroys an expression
BaseExpression::~BaseExpression()
{
    if(mLeft)
        delete mLeft;
    
    if(mRight)
        delete mRight;
}


///Prints the expression to the console
void BaseExpression::printExpression()
{
    printf("%s",toString().c_str());
}    