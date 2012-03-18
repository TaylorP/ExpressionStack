//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef POWER_EXPRESSION_H
#define POWER_EXPRESSION_H

#include "baseExpression.h"

///A exponent expression that raises the left side to the power of the right side
class PowerExpression : public BaseExpression
{
    
public:

    ///Constructs a power expression
    PowerExpression(BaseExpression* pLeft, BaseExpression* pRight);

    ///Destructs the expression
    ~PowerExpression();

    ///Evaluates this expression, i.e compute mLeft^mRight
    inline virtual float evaluate(float pX, float pY);

    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable);
};

#endif