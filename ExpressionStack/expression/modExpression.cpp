//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include "expressions.h"
    
///Constructs an addition expression from a left and right expression
ModExpression::ModExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destroys this expression
ModExpression::~ModExpression()
{
    delete mLeft;
    delete mRight;
}

///Evaluates the expression at the point pX, pY
F32 ModExpression::evaluate(F32 pX, F32 pY)
{
    return fmod(mLeft->evaluate(pX, pY),mRight->evaluate(pX, pY));
}

///Returns a string represenation of the expression
std::string ModExpression::toString()
{
    std::string lString;
    
    lString += "(";
    lString += mLeft->toString();
    lString += " % ";
    lString += mRight->toString();
    lString += ")";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* ModExpression::derivative(VariableExpression* pVariable)
{
    return 0;
}  

///Cleans and minimizes the expression
BaseExpression* ModExpression::clean()
{
    //FIX ME
    
    return new ModExpression(mLeft->clean(), mRight->clean());
}
