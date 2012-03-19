//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include "expressions.h"

///Constructs a power expression
PowerExpression::PowerExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destructs the expression
PowerExpression::~PowerExpression()
{
    delete mLeft;
    delete mRight;
}

///Evaluates this expression, i.e compute mLeft^mRight
F32 PowerExpression::evaluate(F32 pX, F32 pY)
{
    return pow(mLeft->evaluate(pX, pY),mRight->evaluate(pX, pY));
}

///Returns a string represenation of the expression
std::string PowerExpression::toString()
{
    std::string lString;
    
    lString += "(";
    lString += mLeft->toString();
    lString += "^";
    lString += mRight->toString();
    lString += ")";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* PowerExpression::derivative(VariableExpression* pVariable)
{
    NumberExpression* lNumPart = dynamic_cast<NumberExpression*>(mRight);
    if(lNumPart)
    {
        BaseExpression* lOutside = new MultiplyExpression(mRight, new PowerExpression(mLeft, new SubtractExpression(mRight, new NumberExpression(1.0))));
        
        return new MultiplyExpression(lOutside, mLeft->derivative(pVariable));
    }
    
     lNumPart = dynamic_cast<NumberExpression*>(mLeft);
     if(lNumPart)
     {
         return new MultiplyExpression(new MultiplyExpression(this, new LnExpression(mLeft,0)),mRight->derivative(pVariable));
     }
    
    //FIX ME: Extra cases for x^x or whatnot
    return 0;
}  

///Cleans and minimizes the expression
BaseExpression* PowerExpression::clean()
{
    NumberExpression* lNumPart = dynamic_cast<NumberExpression*>(mRight);
    
    if(lNumPart && lNumPart->isZero())
        return new NumberExpression(1.0);
    
    if(lNumPart && lNumPart->isOne())
        return mLeft->clean();
    
    lNumPart = dynamic_cast<NumberExpression*>(mLeft);
    
    if(lNumPart && lNumPart->isZero())
        return new NumberExpression(0.0);
    
    if(lNumPart && lNumPart->isOne())
        return new NumberExpression(1.0); 
    
    return new PowerExpression(mLeft->clean(), mRight->clean());
}
