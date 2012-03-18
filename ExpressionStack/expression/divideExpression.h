//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef DIVIDE_EXPRESSION_H
#define DIVIDE_EXPRESSION_H

#include "baseExpression.h"

class SubtractExpression;
class MultiplyExpression;

///A division expression class
class DivideExpression : public BaseExpression
{
    
public:

    ///Constructs a new division expression from a left and right side
    DivideExpression(BaseExpression* pLeft, BaseExpression* pRight);

    ///Destroys this division expression
    ~DivideExpression();

    ///Evaluates the expression at pX,pY, and returns infinity when dividing by 0
    inline virtual float evaluate(float pX, float pY);
    
    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable); 
};

#endif