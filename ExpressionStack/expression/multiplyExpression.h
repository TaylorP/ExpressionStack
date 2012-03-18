//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef MULTIPLY_EXPRESSION_H
#define MULTIPLY_EXPRESSION_H

#include "baseExpression.h"

///A multiplication expression class
class MultiplyExpression : public BaseExpression
{
    
public:

    ///Constructs a new multiplication expression from a left and right expression
    MultiplyExpression(BaseExpression* pLeft, BaseExpression* pRight);
    
    ///Destructs this multiplication expression
    ~MultiplyExpression();

    ///Evaluates the expression at the point pX, pY
    inline virtual float evaluate(float pX, float pY);
    
    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable);   
    
    ///Cleans and minimizes the expression
    virtual BaseExpression* clean();     
};

#endif