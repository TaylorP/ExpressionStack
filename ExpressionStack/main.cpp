//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#include <iostream>

#ifdef __APPLE__
#include "expressions.h"
#else
#include "expression/expressions.h"
#endif

int main (int argc, const char * argv[])
{
    
    BaseExpression *mult = new MultiplyExpression(new TrigExpression(new MultiplyExpression(XVAR, new NumberExpression(5.0)), eTan),new PowerExpression(YVAR, new NumberExpression(2.0f)));
    
    printf("f(x,y) = ");
    mult->printExpression();

	printf("\n\n");
	printf("d/dx = ");
	mult->derivative(XVAR)->clean()->printExpression();
	printf("\n\n");
	printf("d/dy = ");
	mult->derivative(YVAR)->clean()->printExpression();
	printf("\n\n");
	printf("gradient at 4,5 = (%f,%f)", mult->derivative(XVAR)->evaluate(4.0f,5.0f), mult->derivative(YVAR)->evaluate(4.0f,5.0f));
	int hack;
	scanf("%i",&hack);
    
    return 0;
}

