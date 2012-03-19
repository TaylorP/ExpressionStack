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
F32 SubtractExpression::evaluate(F32 pX, F32 pY)
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


///Cleans and minimizes the expression
BaseExpression* SubtractExpression::clean()
{
    NumberExpression* lNumPart = dynamic_cast<NumberExpression*>(mRight->clean());
    
    if(lNumPart && lNumPart->isZero())
        return mLeft->clean();
    
    lNumPart = dynamic_cast<NumberExpression*>(mLeft->clean());
    if(lNumPart && lNumPart->isZero())
        return mRight->clean();
    
    return new AddExpression(mLeft->clean(), mRight->clean());
}
