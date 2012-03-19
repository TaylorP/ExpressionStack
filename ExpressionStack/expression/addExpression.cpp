//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//3D Graphing Calculator Project

#include "expressions.h"

///Constructs an addition expression from a left and right expression
AddExpression::AddExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destroys this expression
AddExpression::~AddExpression()
{
    delete mLeft;
    delete mRight;
}

///Evaluates the expression at the point pX, pY
F32 AddExpression::evaluate(F32 pX, F32 pY)
{
    return mLeft->evaluate(pX, pY) + mRight->evaluate(pX, pY);
}

///Returns a string represenation of the expression
std::string AddExpression::toString()
{
    std::string lString;
    
    lString += "(";
    lString += mLeft->toString();
    lString += " + ";
    lString += mRight->toString();
    lString += ")";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* AddExpression::derivative(VariableExpression* pVariable)
{
    return new AddExpression(mLeft->derivative(pVariable), mRight->derivative(pVariable));
}

///Cleans and minimizes the expression
BaseExpression* AddExpression::clean()
{
    NumberExpression* lNumPart = dynamic_cast<NumberExpression*>(mRight->clean());
    
    if(lNumPart && lNumPart->isZero())
        return mLeft->clean();
    
    lNumPart = dynamic_cast<NumberExpression*>(mLeft->clean());
    if(lNumPart && lNumPart->isZero())
        return mRight->clean();
    
    return new AddExpression(mLeft->clean(), mRight->clean());
}