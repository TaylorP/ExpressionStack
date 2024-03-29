//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef POINT_2F_H
#define POINT_2F_H

#ifdef __APPLE__
#include "types.h"
#else
#include "..\types.h"
#endif

///Basic structure for holding an ordered pair of data.
typedef struct
{
	///The x component of the point
	F32 x;

	///The y component of the point
	F32 y;

} Point2F;

#endif