//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include "expressions.h"

///Constructs a new numeric expression from a float value
NumberExpression::NumberExpression(float pValue)
{
    mLeft = 0;
    mRight = 0;
    mValue = pValue;
}

///Destructs this numeric expression
NumberExpression::~NumberExpression()
{
    
}

///Returns the numeric value of this expression
float NumberExpression::evaluate(float pX, float pY)
{
    return mValue;
}

///Returns a string represenation of the expression
std::string NumberExpression::toString()
{
    std::string lString;
    std::stringstream  ss;
    ss << mValue;
    ss >> lString;    
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* NumberExpression::derivative(VariableExpression* pVariable)
{
    return new AddExpression(mLeft->derivative(pVariable), mRight->derivative(pVariable));
}   