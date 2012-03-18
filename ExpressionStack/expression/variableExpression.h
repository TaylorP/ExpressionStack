//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef VARIABLE_EXPRESSION_H
#define VARIABLE_EXPRESSION_H

#include "baseExpression.h"

//An expression that can contain a variable representation, in this case x or y
class VariableExpression : public BaseExpression
{
protected:

    //The variable type, x=true and y= false
    bool mVariable;

public:

    //Constructs a new VariableExpression
    VariableExpression(bool pVariable);

    //Destroys this variable expression
    ~VariableExpression();

    //Evaluates this variable expressions
    inline virtual float evaluate(float pX, float pY);

    ///Returns a string represenation of the expression
    virtual std::string toString();
    
    ///Returns a new expression containing the derivative of this expression
    virtual BaseExpression* derivative(VariableExpression* pVariable);
    
};

//Global X and Y variables, since we only really need one instance of each
static VariableExpression* gXVar = new VariableExpression(true);
static VariableExpression* gYVar = new VariableExpression(false);

//Defines to make them easy to access and see
#define XVAR gXVar
#define YVAR gYVar

#endif