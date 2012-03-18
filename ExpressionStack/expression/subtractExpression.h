//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef SUBTRACT_EXPRESSION_H
#define SUBTRACT_EXPRESSION_H

#include "baseExpression.h"

//A subtraction operation
class SubtractExpression : public BaseExpression
{
    
public:

    ///Creates a new subtraction expression
    SubtractExpression(BaseExpression* pLeft, BaseExpression* pRight);

    ///Destroys the expression
    ~SubtractExpression();
    
    ///Evaluates the expression at pX, pY
    inline virtual float evaluate(float pX, float pY);

    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable);
    
    ///Cleans and minimizes the expression
    virtual BaseExpression* clean();    
    
};

#endif