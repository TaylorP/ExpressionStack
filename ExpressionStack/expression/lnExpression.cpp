//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include "expressions.h"
    
///Constructs a power expression
LnExpression::LnExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destructs the expression
LnExpression::~LnExpression()
{
    delete mLeft;
    delete mRight;
}

///Evaluates this expression, i.e compute mLeft^mRight
F32 LnExpression::evaluate(F32 pX, F32 pY)
{
    return log(mLeft->evaluate(pX,pY));
}


///Returns a string represenation of the expression
std::string LnExpression::toString()
{
    std::string lString;
    
    lString += "ln(";
    lString += mLeft->toString();
    lString += ")";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* LnExpression::derivative(VariableExpression* pVariable)
{
    DivideExpression* lDivisionPart = new DivideExpression( new NumberExpression(1.0), mLeft);
    
    return new MultiplyExpression(lDivisionPart, mLeft->derivative(pVariable));
}    

///Cleans and minimizes the expression
BaseExpression* LnExpression::clean()
{
    NumberExpression* lNumPart = dynamic_cast<NumberExpression*>(mLeft->clean());
    
    if(lNumPart && lNumPart->isOne())
        return new NumberExpression(0.0f);
    
    return new LnExpression(mLeft->clean(), 0);
}

