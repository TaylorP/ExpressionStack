//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef LOG_EXPRESSION_H
#define LOG_EXPRESSION_H

#include "baseExpression.h"

///A log expression that computes log(left), with base 10
class LogExpression : public BaseExpression
{
    
public:
    
    ///Constructs a power expression
    LogExpression(BaseExpression* pLeft, BaseExpression* pRight);
    
    ///Destructs the expression
    ~LogExpression();
    
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