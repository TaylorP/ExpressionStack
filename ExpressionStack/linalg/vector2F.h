//Copyright Marmoset Software, 2012
//Written by Taylor Petrick
//
//Expression Stack

#ifndef VECTOR_2F_H
#define VECTOR_2F_H

#include <math.h>
#include "point2F.h"

///Basic structure for holding a cartesian vector in R2
struct Vector2F : public Point2F
{
	///The default constructor; constructs a zero vector 
	Vector2F()
	{
		x = 0.0f;
		y = 0.0f;
	}

	///Constructs a Vector2F with both components equal to the parameter pValue
	Vector2F(F32 pValue)
	{
		x = pValue;
		y = pValue;
	}

	///Constructs a Vector2F from two parameters pX and pY
	Vector2F(F32 pX, F32 pY)
	{
		x = pX;
		y = pY;
	}

	///Constructs a Vector2F from another Vector2F
	Vector2F(const Vector2F &pVector)
	{
		x = pVector.x;
		y = pVector.y;
	}	

	///Constructs a Vector2F from a F32 pointer
	Vector2F(const F32* pVector)
	{
		x = pVector[0];
		y = pVector[1];
	}

	///Zeroes the Vector2F
	inline void zero()
	{
		x = 0.0;
		y = 0.0;
	}
	
	///The binary addition operator between two Vector2Fs
	inline Vector2F operator+(const Vector2F& pRight) const
	{
		Vector2F lOut(*this);
		
		return lOut += pRight;
	}

	///The binary subtraction operator between two Vector2Fs
	inline Vector2F operator-(const Vector2F& pRight) const
	{
		Vector2F lOut(*this);
		
		return lOut -= pRight;
	}
	
	///The compound addition operator between two Vector2Fs
	inline Vector2F& operator+=(const Vector2F& pRight)
	{
		x += pRight.x;
		y += pRight.y;
		
		return *this;
	}
	
	///The compound subtraction operator between two Vector2Fs
	inline Vector2F& operator-=(const Vector2F& pRight)
	{
		x -= pRight.x;
		y -= pRight.y;
		
		return *this;
	}

	///The binary multiplication operator
	inline Vector2F operator*(const F32& pRight) const
	{
		Vector2F lOut(*this);
		
		return lOut *= pRight;
	}

	///The compound multiplication operator
	inline Vector2F& operator*=(const F32& pRight)
	{
		x = x * pRight;
		y = y * pRight;
		
		return *this;
	}

	///The binary division operator
	inline Vector2F operator/(const F32& pRight) const
	{
		Vector2F lOut(*this);
		
		return lOut /= pRight;
	}

	///The compound division operator
	inline Vector2F& operator/=(const F32& pRight)
	{
		x = x / pRight;
		y = y / pRight;
		
		return *this;
	}	
		
	///The array access operator at index pIndex
	inline F32& operator[](const S32& pIndex)
	{
		return ptr()[pIndex];
	}	
	
	///The assignment operator for arrays of type F32
	inline Vector2F& operator=(const F32* pArray)
	{
		x = pArray[0];
		y = pArray[1];

		return *this;
	}			

	///The sign swap operator on a single Vector2F
	inline friend Vector2F operator-(const Vector2F& pRight) 
	{ 
		return Vector2F(-pRight.x, -pRight.y); 
	}

	///The equality test operator between two Vector2F instances
	inline friend bool operator==(const Vector2F& pLeft, const Vector2F& pRight)
	{
		if((pLeft.x == pRight.x) && (pLeft.y == pRight.y))
		{
			if(pLeft.lenSquared() == pRight.lenSquared())
			{
				return true;
			}
		}

		return false;
	}

	///The inequality test operator between two Vector2F instances
	inline friend bool operator!=(const Vector2F& pLeft, const Vector2F& pRight)
	{
		return !(pLeft==pRight);
	}	

	///The greater than operator for comparing the magnitutude of Vector2F pLeft with the F32 pRight 
	inline friend bool operator>(const Vector2F& pLeft, const F32& pRight)
	{
		return pLeft.lenSquared() > (pRight*pRight);
	}		

	///The greater than or equal to operator for comparing the magnitutude of Vector2F pLeft with the F32 pRight 
	inline friend bool operator>=(const Vector2F& pLeft, const F32& pRight)
	{
		return pLeft.lenSquared() >= (pRight*pRight);
	}	
	
	///The less than operator for comparing the magnitutude of Vector2F pLeft with the F32 pRight 
	inline friend bool operator<(const Vector2F& pLeft, const F32& pRight)
	{
		return pLeft.lenSquared() < (pRight*pRight);
	}	
	
	///The less than or equal to operator for comparing the magnitutude of Vector2F pLeft with the F32 pRight 
	inline friend bool operator<=(const Vector2F& pLeft, const F32& pRight)
	{
		return pLeft.lenSquared() <= (pRight*pRight);
	}							

	///Sets the components of this Vector2F to pX and pY
	inline void set(F32 pX, F32 pY)
	{
		x = pX;
		y = pY;
	}

	///Returns a pointer to this Vector2F; e.g. an array of it's components
	inline F32* ptr()
	{
		return (F32*)this;
	}

	///Returns the length of the vector squared
	inline F32 lenSquared() const
	{
		return x*x + y*y;
	}

	///Returns the length of the vector
	inline F32 len()
	{
		return sqrt( lenSquared() );
	}

	///Normalizes the vector
	inline void normalize()
	{
		F32 lLength = len();

		x /= lLength;
		y /= lLength;
	}

	///Returns a normalized copy of this vector
	inline Vector2F normalized()
	{
		Vector2F lVector(*this);

		lVector.normalize();

		return lVector;
	}

	///Returns the dot product of this vector and another Vector2F pVector
	inline F32 dot(Vector2F pVector)
	{
		return (x * pVector.x) + (y * pVector.y);
	}

	///Returns the angle between this vector's components
	inline F32 getAngle()
	{
		return (F32)atan2(x, y);
	}

	///Finds the angle between this Vector2F and another Vector2F pVector
	inline F32 getAngleBetween(Vector2F& pVector)
	{
		F32 lDistance, lDot;
    
		lDistance = len() * pVector.len();

		if( lDistance == 0.0f ) 
			return 0;
    
		lDot = dot(pVector) / lDistance;
    
		if(lDot > 1.0f)  
			lDot =  1.0f;
		else if(lDot < -1.0f)  
			lDot = -1.0f;
    
		return (F32)acos( lDot );
	}

	///Rotates this Vector2F by pAngle radians
	inline Vector2F& rotate(F32 pRadians)
	{
		F32 lSin = (F32)sin(pRadians);
		F32 lCos = (F32)cos(pRadians);
		F32 lX = x;
		F32	lY = y;

		x  = (lCos * lX) - (lSin * lY);
		y  = (lCos * lY) + (lSin * lX);

		return *this;
	}

};

#endif