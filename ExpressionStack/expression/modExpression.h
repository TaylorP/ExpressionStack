//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef MOD_EXPRESSION_H
#define MOD_EXPRESSION_H

#include "baseExpression.h"

///Modulo operation in the expression tree. Computes left % right.
class ModExpression : public BaseExpression
{
	
public:
    
    ///Constructs an addition expression from a left and right expression
    ModExpression(BaseExpression* pLeft, BaseExpression* pRight);
    
    ///Destroys this expression
    ~ModExpression();
    
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