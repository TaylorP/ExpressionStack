//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include "expressions.h"

///Constructs a power expression
LogExpression::LogExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destructs the expression
LogExpression::~LogExpression()
{
    delete mLeft;
    delete mRight;
}

///Evaluates this expression, i.e compute mLeft^mRight
float LogExpression::evaluate(float pX, float pY)
{
    return log10(mLeft->evaluate(pX,pY));
}

///Returns a string represenation of the expression
std::string LogExpression::toString()
{
    std::string lString;
    
    lString += "log(";
    lString += mLeft->toString();
    lString += ")";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* LogExpression::derivative(VariableExpression* pVariable)
{
    DivideExpression* lDivisionPart = new DivideExpression( new NumberExpression(1.0), mLeft);
    DivideExpression* lLnPart       = new DivideExpression( new NumberExpression(1.0), new LnExpression( new NumberExpression(1.0), 0));
    
    return new MultiplyExpression(new MultiplyExpression(lDivisionPart, lLnPart), mLeft->derivative(pVariable));
}      

///Cleans and minimizes the expression
BaseExpression* LogExpression::clean()
{
    NumberExpression* lNumPart = dynamic_cast<NumberExpression*>(mLeft->clean());
    
    if(lNumPart && lNumPart->isOne())
        return new NumberExpression(0.0f);
    
    return new LogExpression(mLeft->clean(), 0);
}

