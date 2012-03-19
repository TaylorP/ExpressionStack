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
    F32 mValue;

public:

    ///Constructs a new numeric expression from a float value
    NumberExpression(F32 pValue);

    ///Destructs this numeric expression
    ~NumberExpression();

    ///Returns the numeric value of this expression
    inline virtual F32 evaluate(F32 pX, F32 pY);
    
    ///Returns true if this number is zero.
    inline virtual bool isZero();
    
    ///Returns true if this number is one.
    inline virtual bool isOne();   

    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable); 
    
    ///Cleans and minimizes the expression
    virtual BaseExpression* clean();    
};

#endif