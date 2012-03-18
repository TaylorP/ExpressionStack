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

bool NumberExpression::isZero()
{
    if(fabs(mValue) < 0.0000001f)
        return true;
    
    return false;
}

bool NumberExpression::isOne()
{
    if(fabs(mValue-1) < 0.0000001f)
        return true;
    
    return false;
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

///Cleans and minimizes the expression
BaseExpression* NumberExpression::clean()
{
    //FIX ME - is this all we need here?
    
    return new NumberExpression(mValue);
}


