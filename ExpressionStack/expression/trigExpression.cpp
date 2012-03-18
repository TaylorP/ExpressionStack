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
            
            
        case eCsc:
            lVal = 1.0/sin(lLeft);
            break;
            
        case eSec: 
            lVal = 1.0/cos(lLeft);
            break;
            
        case eCot:
            lVal = 1.0/tan(lLeft);
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
            
        case eCsc:
            lStrRep = "csc(";
            break;
            
        case eSec: 
            lStrRep = "sec(";
            break;
            
        case eCot:
            lStrRep = "cot(";
            break;       
            
        default:
            break;
            
    }
    
    lStrRep += mLeft->toString();
    lStrRep += ")";
    
    return lStrRep;
}

///Returns a new expression containing the derivative of this expression
BaseExpression* TrigExpression::derivative(VariableExpression *pVariable)
{
    BaseExpression* lTrigPart;
    switch(mTrigFunction)
    {
        case eSin:
            lTrigPart = new TrigExpression(mLeft, eCos);
            break;
            
        case eCos:
            lTrigPart = new MultiplyExpression( new NumberExpression(-1.0), new TrigExpression(mLeft, eSin));
            break;
            
        case eTan:
           lTrigPart = new PowerExpression(new TrigExpression(mLeft, eSec), new NumberExpression(2.0));
            break;
            
        default:
            return 0;
            break;
            
    }
    
    return new MultiplyExpression(lTrigPart, mLeft->derivative(pVariable));
}


///Cleans and minimizes the expression
BaseExpression* TrigExpression::clean()
{
    return new TrigExpression(mLeft->clean(), mTrigFunction);
}