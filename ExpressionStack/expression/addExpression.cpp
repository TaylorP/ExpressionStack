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
float AddExpression::evaluate(float pX, float pY)
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