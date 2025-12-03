/*************************************************************
 * 1. Name:
 *      -Hayden Olson & Mason Allen-
 * 2. Assignment Name:
 *      Practice 04: Angle Class
 * 3. Assignment Description:
 *      A class to represent an angle
 * 4. What was the hardest part? Be as specific as possible.
 *      -Getting the files properly working. Nothing would work for a while. Something went wrong when getting the new files for this assignment.
 *		 The tests were failing still.-
 * 5. How long did it take for you to complete the assignment?
 *      -5 hours.-
 **************************************************************/
#pragma once

#define _USE_MATH_DEFINES
#include <math.h>   // for M_PI which is 3.14159
#include <iostream>
#include <iomanip>
#include <cassert>
#include <string>

using namespace std;

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestLander;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
	friend TestAcceleration;
	friend TestVelocity;
	friend TestAngle;
	friend TestLander;

	// Constructors
	Angle() : radians(0.0) {};
	Angle(const Angle& rhs) : radians(rhs.radians)
	{
	};
	Angle(double degrees)
	{
		setDegrees(degrees);
	};

	/*********************************************
		Member Operator Overrides
	**********************************************/
	
	// assignment 
	Angle& operator= (const Angle & rhs)
	{
		radians = rhs.radians;
		return *this;
	}
	Angle& operator= (double rhs)
	{
		radians = rhs;
		return *this;
	}

	//Increment and Deincrement
	Angle& operator++()
	{
		radians += M_PI/180;
		if (radians > 2 * M_PI)
			radians -= 2 * M_PI;
		// return new value
		return *this;
	}
	Angle operator++(int postfix)
	{
		Angle numReturn(*this);
		radians += M_PI/180;
		if (radians > 2 * M_PI)
			radians -= 2 * M_PI;
		// return old value
		return numReturn;
	}
	Angle& operator--()
	{
		radians -= M_PI/180;
		if (radians < 0)
			radians += 2 * M_PI;
		// return new value
		return *this;
	}
	Angle operator--(int postfix)
	{
		Angle numReturn(*this);
		radians -= M_PI/180;
		if (radians < 0)
			radians += 2 * M_PI;
		// return old value
		return numReturn;
	}

	/*********************************************
		Non-Member Operator Overrides
	**********************************************/

	//Negative (This should work like the prefix increment operator)
	inline friend Angle operator-(const Angle& rhs)
	{
		Angle angle;
		angle.setRadians(M_PI * 2 - rhs.radians);
		return angle;
	}

	//Equals not Equals
	inline friend bool operator==(const Angle& lhs,const Angle& rhs)
	{
		return lhs.radians == rhs.radians;
	}
	inline friend bool operator!=(const Angle& lhs, const Angle& rhs)
	{
		return lhs.radians != rhs.radians;
	}

	//Insertion
	inline friend ostream& operator<<(ostream& out, const Angle& rhs)
	{
		out << std::fixed << std::setprecision(1) << rhs.getDegrees();
		return out;
	}

	//Extraction
	inline friend istream& operator>>(istream& in, Angle& rhs)
	{
		double temp;
		if (in >> temp)             // only succeeds if in can pass a double into a temp variable
		{
			rhs.radians = rhs.convertToRadians(temp);
		}
		return in;
	}


	// Getters
	double getDegrees() const
	{
		return radians * 180.0 / M_PI;
	};

	double convertToDegrees(double inRads) const
	{
		inRads = normalize(inRads);
		double degrees = inRads * 180.0 / M_PI;
		return degrees;
	};

	double convertToRadians(double inDegs) const
	{
		double retRads = inDegs * M_PI / 180;
		retRads = normalize(retRads);
		return retRads;
	};

	double getRadians() const
	{
		return radians;
	};

	// Setters
	void setDegrees(double degrees)
	{
		radians = convertToRadians(degrees);
	};

	void setRadians(double inRadians)
	{
		radians = normalize(inRadians);
	};

	void setUp()
	{
		setDegrees(0);
	};
	void setDown()
	{
		setDegrees(180);
	};
	void setRight()
	{
		setDegrees(90);
	};
	void setLeft()
	{
		setDegrees(270);
	};
	void reverse()
	{
		radians = normalize(radians + M_PI);
	};
	Angle& add(double delta)
	{
		radians = normalize(radians + delta);
		return *this;
	};

	void display(std::ostream& out) const
	{

		out << std::fixed << std::setprecision(1) << convertToDegrees(radians);
	};

private:

	double normalize(double angle) const
	{
		while (angle >= (2 * M_PI))
		{
			angle = angle - (2 * M_PI);
		};

		while (angle < 0)
		{
			angle = angle + (2 * M_PI);
		};

		return angle;
	};


	double radians;   // 360 degrees equals 2 PI radians
};
