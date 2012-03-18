//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include <iostream>
#include "expressions.h"


int main (int argc, const char * argv[])
{

/*    AddExpression* lExpression = new AddExpression(new ModExpression( new NumberExpression(2.4), XVAR), new LnExpression(new TrigExpression(new NumberExpression(3.5), eTan), 0));*/
    
    AddExpression* lExpression = new AddExpression(new PowerExpression(YVAR, new NumberExpression(10.0)), new MultiplyExpression(XVAR, YVAR));
    printf("\n");
    
    lExpression->derivative(XVAR)->printExpression();
    return 0;
}

