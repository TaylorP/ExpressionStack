//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack


#include "baseExpression.h"
#include "addExpression.h"
#include "divideExpression.h"
#include "lnExpression.h"
#include "logExpression.h"
#include "modExpression.h"
#include "multiplyExpression.h"
#include "numberExpression.h"
#include "powExpression.h"
#include "subtractExpression.h"
#include "trigExpression.h"
#include "variableExpression.h"

///Windows does not define a floating point infinity
#ifndef INFINITY
#define INFINITY 10e10f
#endif

///Windows math.h does not have hyperbolic arc sin/cos/tan, so we implment them here
#ifdef WIN32
inline float asinh(float pValue)
{
	float lRet;

	if(pValue > 0)
		lRet = log(pValue + sqrt(pValue * pValue + 1));
	else
		lRet = -log(-pValue + sqrt(pValue * pValue + 1));

	return lRet;
}

inline float acosh(float pValue)
{
	float lRet;

	if(pValue > 0)
		lRet = log(pValue + sqrt(pValue * pValue - 1));
	else
		lRet = -log(-pValue + sqrt(pValue * pValue - 1));

	return lRet;
}

inline float atanh(float pValue)
{
	return 0.5f * log((1.0f + pValue)/(1.0f - pValue));
}
#endif