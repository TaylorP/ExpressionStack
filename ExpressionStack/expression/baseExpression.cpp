//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack


#include "expressions.h"

///Constructs a new expression
BaseExpression::BaseExpression()
{
    mLeft = mRight = 0;
}

///Constructs an expression from two sides
BaseExpression::BaseExpression(BaseExpression* pLeft, BaseExpression* pRight)
{
    mLeft = pLeft;
    mRight = pRight;
}

///Destroys an expression
BaseExpression::~BaseExpression()
{
    if(mLeft)
        delete mLeft;
    
    if(mRight)
        delete mRight;
}


///Prints the expression to the console
void BaseExpression::printExpression()
{
    printf("%s",toString().c_str());
}    

///Evaluates the expression at the Point2F coordinate
F32 BaseExpression::evaluate(Point2F& pPoint)
{
    return evaluate(pPoint.x, pPoint.y);
}

///Evaluates the gradient at the point pX, pY
Vector2F BaseExpression::gradient(F32 pX, F32 pY)
{
	BaseExpression* t = derivative(XVAR);
    return Vector2F(
                    derivative(XVAR)->evaluate(pX, pY), 
                    derivative(YVAR)->evaluate(pX, pY)
                    );
}

///Evaluates the gradient at the Point2F coordinate
Vector2F BaseExpression::gradient(Point2F& pPoint)
{
    return Vector2F(
                    derivative(XVAR)->evaluate(pPoint), 
                    derivative(YVAR)->evaluate(pPoint));
}