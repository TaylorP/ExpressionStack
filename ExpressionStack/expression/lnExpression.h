//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef LN_EXPRESSION_H
#define LN_EXPRESSION_H

#include "baseExpression.h"

///A natural log expression that computes log(left), with base e
class LnExpression : public BaseExpression
{
    
public:
    
    ///Constructs a power expression
    LnExpression(BaseExpression* pLeft, BaseExpression* pRight);
    
    ///Destructs the expression
    ~LnExpression();
    
    ///Evaluates this expression, i.e compute mLeft^mRight
    inline virtual float evaluate(float pX, float pY);
    
    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable);  
    
    ///Cleans and minimizes the expression
    virtual BaseExpression* clean();     
};

#endif