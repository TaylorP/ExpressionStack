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


#ifdef __APPLE__
#include "vector2F.h"
#include "types.h"
#else
#include "..\types.h"
#include "..\linalg\vector2F.h"
#endif

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
    BaseExpression();

    ///Constructs an expression from two sides
    BaseExpression(BaseExpression* pLeft, BaseExpression* pRight);

    ///Destroys an expression
    ~BaseExpression();

    
    ///Evaluates the expression at the point pX, pY
    inline virtual F32 evaluate(F32 pX, F32 pY) = 0;
    
    ///Evaluates the expression at the Point2F coordinate
    inline virtual F32 evaluate(Point2F& pPoint);
    
    ///Evaluates the gradient at the point pX, pY
    inline virtual Vector2F gradient(F32 pX, F32 pY);
    
    ///Evaluates the gradient at the Point2F coordinate
    inline virtual Vector2F gradient(Point2F& pPoint);
    
    
    ///Find the critical points, assuming the function is unbounded
    //inline virtual Point2F* criticalPoints();
    
    ///Find the critical points, assuming the function is bounded by set of expressions in pBounds
    //inline virtual Point2F* criticalPoints(BaseExpression** pBounds);

    
    ///Prints the expression to the console
    virtual void printExpression();
    
    ///Returns a string representation of the expression
    virtual std::string toString() = 0;

    
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable) = 0;
    
    ///Returns a minimized copy of the expression
    virtual BaseExpression* clean() = 0;

    
    ///Creates an addition expression
    BaseExpression* operator+(BaseExpression *pRight) const;    
};

#endif