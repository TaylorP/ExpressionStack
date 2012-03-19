//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include <iostream>
#include "expressions.h"


int main (int argc, const char * argv[])
{
    
    BaseExpression *mult = new MultiplyExpression(XVAR, new NumberExpression(5.0));
    
    
    mult->printExpression();
    
    return 0;
}

