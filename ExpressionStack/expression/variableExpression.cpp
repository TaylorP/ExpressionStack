//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include "expressions.h"
    
//Constructs a new VariableExpression
VariableExpression::VariableExpression(bool pVariable)
{
    mVariable = pVariable;
}

//Destroys this variable expression
VariableExpression::~VariableExpression()
{
}

//Evaluates this variable expressions
F32 VariableExpression::evaluate(F32 pX, F32 pY)
{
    //Return pX if this is an x variable, or pY if this a y
    if(mVariable)
        return pX;
    else
        return pY;
}

///Returns a string represenation of the expression
std::string VariableExpression::toString()
{
    std::string lString;
    
    if(mVariable)
        lString = "x";
    else
        lString = "y";
    
    return lString;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* VariableExpression::derivative(VariableExpression* pVariable)
{
    if(pVariable == this)
    {
        return new NumberExpression(1.0);
    }
    else
    {
        return new NumberExpression(0.0);
    }
}


///Cleans and minimizes the expression
BaseExpression* VariableExpression::clean()
{
    return this;
}
    