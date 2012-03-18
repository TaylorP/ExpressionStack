//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack


#include "expressions.h"

    
///Constructs a new multiplication expression from a left and right expression
TrigExpression::TrigExpression(BaseExpression* pLeft, OperatorType pTrigFunction)
{
    mLeft = pLeft;
    mTrigFunction = pTrigFunction;
}

///Destructs this multiplication expression
TrigExpression::~TrigExpression()
{
    delete mLeft;
}

///Evaluates the expression at the point pX, pY
float TrigExpression::evaluate(float pX, float pY)
{
    float lLeft = mLeft->evaluate(pX,pY);
    float lVal = 0.0f;
    
    switch(mTrigFunction)
    {
        case eSin:
            lVal = sin(lLeft);
            break;
            
        case eCos:
            lVal = cos(lLeft);
            break;
            
        case eTan:
            lVal = tan(lLeft);
            break;
            
            
        case eASin:
            lVal = asin(lLeft);
            break;
            
        case eACos: 
            lVal = acos(lLeft);
            break;
            
        case eATan:
            lVal = atan(lLeft);
            break;
            
        default:
            break;
            
    }
    
    return lVal;
}

///Returns a string representation of this expression
std::string TrigExpression::toString()
{
    std::string lStrRep;
    
    switch(mTrigFunction)
    {
        case eSin:
            lStrRep = "sin(";
            break;
            
        case eCos:
            lStrRep = "cos(";
            break;
            
        case eTan:
            lStrRep = "tan(";
            break;
            
            
        case eASin:
            lStrRep = "asin(";
            break;
            
        case eACos: 
            lStrRep = "acos(";
            break;
            
        case eATan:
            lStrRep = "atan(";
            break;
            
        default:
            break;
            
    }
    
    lStrRep += mLeft->toString();
    lStrRep += ")";
    
    return lStrRep;
}