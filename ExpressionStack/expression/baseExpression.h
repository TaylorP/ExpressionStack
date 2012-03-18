//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef BASE_EXPRESSION_H
#define BASE_EXPRESSION_H

#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
#include <sstream>

class VariableExpression;

///The base expression class from which all other expression types are derived
class BaseExpression
{
    
protected:
    
    ///The left hand side of the expression, either another expression, a variable or a number
    BaseExpression* mLeft;
    
    ///The right hand side of the expression
    BaseExpression* mRight;

public:

    ///Constructs a new expression
    BaseExpression()
    {
        mLeft = mRight = 0;
    }

    ///Constructs an expression from two sides
    BaseExpression(BaseExpression* pLeft, BaseExpression* pRight)
    {
        mLeft = pLeft;
        mRight = pRight;
    }

    ///Destroys an expression
    ~BaseExpression()
    {
        if(mLeft)
            delete mLeft;
        
        if(mRight)
            delete mRight;
    }

    
    ///Evaluates the expression at the point pX, pY
    inline virtual float evaluate(float pX, float pY) = 0;

    ///Prints the expression to the console
    virtual void printExpression()
    {
        printf("%s",toString().c_str());
    }
    
    ///Returns a string representation of the expression
    virtual std::string toString() = 0;
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable) = 0;
    
    ///Cleans and minimizes the expression
    virtual BaseExpression* clean() = 0;
};

#endif