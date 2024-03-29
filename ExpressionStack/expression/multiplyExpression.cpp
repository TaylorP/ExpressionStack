//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack


#include "expressions.h"
    
///Constructs a new multiplication expression from a left and right expression
MultiplyExpression::MultiplyExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destructs this multiplication expression
MultiplyExpression::~MultiplyExpression()
{
    delete mLeft;
    delete mRight;
}

///Evaluates the expression at the point pX, pY
F32 MultiplyExpression::evaluate(F32 pX, F32 pY)
{
    return mLeft->evaluate(pX, pY) * mRight->evaluate(pX, pY);
}

///Returns a string represenation of the expression
std::string MultiplyExpression::toString()
{
    std::string lString;
    
    lString += "(";
    lString += mLeft->toString();
    lString += " * ";
    lString += mRight->toString();
    lString += ")";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* MultiplyExpression::derivative(VariableExpression* pVariable)
{
    NumberExpression* lNumPart = dynamic_cast<NumberExpression*>(mLeft);
    
    if(lNumPart)
    {
        return new MultiplyExpression(mLeft, mRight->derivative(pVariable));
    }
    
    
    lNumPart = dynamic_cast<NumberExpression*>(mRight);
    if(lNumPart)
    {
        return new MultiplyExpression(mRight, mLeft->derivative(pVariable));
    }
    
    BaseExpression* lLeft = new MultiplyExpression(mLeft->derivative(pVariable), mRight);
    BaseExpression* lRight = new MultiplyExpression(mLeft, mRight->derivative(pVariable));
    
    return new AddExpression(lLeft, lRight);
}     

///Cleans and minimizes the expression
BaseExpression* MultiplyExpression::clean()
{
    NumberExpression* lNumPartR = dynamic_cast<NumberExpression*>(mRight->clean());
    NumberExpression* lNumPartL = dynamic_cast<NumberExpression*>(mLeft->clean());
    
    if((lNumPartR && lNumPartR->isZero()) || (lNumPartL && lNumPartL->isZero()))
        return new NumberExpression(0.0f);
    
    if(lNumPartR && lNumPartR->isOne())
        return mLeft->clean();
    
    if(lNumPartL && lNumPartL->isOne())
        return mRight->clean();   
    
    return new MultiplyExpression(mLeft->clean(), mRight->clean());
}
