//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef TRIG_EXPRESSION_H
#define TRIG_EXPRESSION_H

#include "baseExpression.h"

enum OperatorType
{
    eSin,
    eCos,
    eTan,
    
    eASin,
    eACos,
    eATan,
    
    eSinH,
    eCosH,
    eTanH,
    
    eASinH,
    eACosH,
    eATanH
    
};

///A trig expression class
class TrigExpression : public BaseExpression
{
    
protected:
    
    OperatorType mTrigFunction;
    
    
public:
    
    ///Constructs a new multiplication expression from a left and right expression
    TrigExpression(BaseExpression* pLeft, OperatorType pTrigFunction);
    
    ///Destructs this multiplication expression
    ~TrigExpression();
    
    ///Evaluates the expression at the point pX, pY
    inline virtual float evaluate(float pX, float pY);
      
    ///Returns a string representation of this expression
    virtual std::string toString();
};

#endif