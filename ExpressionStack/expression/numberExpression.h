//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef NUMBER_EXPRESSION_H
#define NUMBER_EXPRESSION_H

#include "baseExpression.h"

///A numeric expression that simply evaluates to it's assigned float value
class NumberExpression : public BaseExpression
{
    
protected:
    
    ///The value of this numeric expression
    float mValue;

public:

    ///Constructs a new numeric expression from a float value
    NumberExpression(float pValue);

    ///Destructs this numeric expression
    ~NumberExpression();

    ///Returns the numeric value of this expression
    inline virtual float evaluate(float pX, float pY);

    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable); 
};

#endif