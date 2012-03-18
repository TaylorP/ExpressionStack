//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include "expressions.h"

///Creates a new subtraction expression
SubtractExpression::SubtractExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destroys the expression
SubtractExpression::~SubtractExpression()
{
    delete mLeft;
    delete mRight;
}

///Evaluates the expression at pX, pY
float SubtractExpression::evaluate(float pX, float pY)
{
    return mLeft->evaluate(pX, pY) - mRight->evaluate(pX, pY);
}

///Returns a string represenation of the expression
std::string SubtractExpression::toString()
{
    std::string lString;
    
    lString += "(";
    lString += mLeft->toString();
    lString += " - ";
    lString += mRight->toString();
    lString += ")";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* SubtractExpression::derivative(VariableExpression* pVariable)
{
    return new SubtractExpression(mLeft->derivative(pVariable), mRight->derivative(pVariable));
} 