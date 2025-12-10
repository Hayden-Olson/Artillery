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

	double getDx()
	{
		return sin(radians);
	}

	double getDy()
	{
		return cos(radians);
	}

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

	void setDxDy(double dx, double dy)
	{
		radians = normalize(atan2(dx, dy));
	}

	//conversions

	void reverse()
	{
		radians = normalize(radians + M_PI);
	};
	Angle& add(double delta)
	{
		radians = normalize(radians + delta);
		return *this;
	};

	//checks

	bool isRight()
	{
		if (radians < M_PI)
		{
			return true;
		}
		return false;
	}

	bool isLeft()
	{
		if (radians > M_PI)
		{
			return true;
		}
		return false;
	}

	virtual void display(std::ostream& out) const
	{

		out << std::fixed << std::setprecision(1) << convertToDegrees(radians) << "degrees";
	};

	virtual Angle & operator++()
	{
		if (radians + (M_PI / 180) > (2 * M_PI))
		{
			radians = (M_PI / 180);
		}
		else
		{
			radians += (M_PI / 180);
		}
	}

	virtual Angle& operator--()
	{
		if (radians - (M_PI / 180) < 0)
		{
			radians = (2 * M_PI) - (M_PI / 180);
		}
		else
		{
			radians -= (M_PI / 180);
		}
	}

private:

	double normalize(double angle) const
	{
		while (angle > (2 * M_PI))
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
/************************************
 * ANGLE RADIANS
 ************************************/
class AngleRadians : public Angle
{
public:
	// Constructor that takes radians
	AngleRadians(double radians) : Angle()
	{
		setRadians(radians);
	}
	// Override display method to show radians
	virtual void display(std::ostream& out) const override
	{
		out << std::fixed << std::setprecision(2) << getRadians() << " radians";
	}
	virtual Angle& operator++() override
	{
		double newRads = getRadians() + (M_PI / 8);
		setRadians(newRads);
		return *this;
	}
	virtual Angle& operator--() override
	{
		double newRads = getRadians() - (M_PI / 8);
		setRadians(newRads);
		return *this;
	}
};

