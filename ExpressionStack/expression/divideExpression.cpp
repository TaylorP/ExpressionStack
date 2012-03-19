//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//3D Graphing Calculator Project

#include "expressions.h"

///Constructs a new division expression from a left and right side
DivideExpression::DivideExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destroys this division expression
DivideExpression::~DivideExpression()
{
    delete mLeft;
    delete mRight;
}

///Evaluates the expression at pX,pY, and returns infinity when dividing by 0
F32 DivideExpression::evaluate(F32 pX, F32 pY)
{
    F32 lRight = mRight->evaluate(pX, pY);
    
    if(lRight == 0)
        return INFINITY;

    return mLeft->evaluate(pX, pY) / lRight;
}

///Returns a string represenation of the expression
std::string DivideExpression::toString()
{
    std::string lString;
    
    lString += "(";
    lString += mLeft->toString();
    lString += " / ";
    lString += mRight->toString();
    lString += ")";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* DivideExpression::derivative(VariableExpression* pVariable)
{
    return new DivideExpression(
                                new SubtractExpression(new MultiplyExpression(mLeft->derivative(pVariable),mRight), new MultiplyExpression(mLeft,mRight->derivative(pVariable))), new PowerExpression(mRight, new NumberExpression(2.0)));
}   


///Cleans and minimizes the expression
BaseExpression* DivideExpression::clean()
{
    NumberExpression* lNumPart = dynamic_cast<NumberExpression*>(mRight->clean());
    
    if(lNumPart && lNumPart->isOne())
        return mLeft->clean();
    
    lNumPart = dynamic_cast<NumberExpression*>(mLeft->clean());
    if(lNumPart && lNumPart->isZero())
        return new NumberExpression(0.0);
    
    return new DivideExpression(mLeft->clean(), mRight->clean());
}
