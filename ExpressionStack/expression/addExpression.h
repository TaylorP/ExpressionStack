//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef ADD_EXPRESSION_H
#define ADD_EXPRESSION_H

#include "baseExpression.h"

///Addition operation in the expression tree. Adds two expressions together.
class AddExpression : public BaseExpression
{
	
public:

    ///Constructs an addition expression from a left and right expression
    AddExpression(BaseExpression* pLeft, BaseExpression* pRight);

    ///Destroys this expression
    ~AddExpression();

    ///Evaluates the expression at the point pX, pY
    virtual float evaluate(float pX, float pY);
    
    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable);
    
};

#endif