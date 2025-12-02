/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

 // for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestLander;

// for add()
class Acceleration;
class Angle;

/*********************************************
 * Velocity
 * I feel the need, the need for speed
 * Ticket 1: about 35 minutes.
 *
 *********************************************/
class Velocity
{
	// for unit tests
	friend TestPosition;
	friend TestVelocity;
	friend TestLander;

public:
	// constructors
	Velocity() : dx(0), dy(0) {}
	Velocity(double dx, double dy) : dx(dx), dy(dy) {}

	// getters
	double getDX()       const { return dx; }
	double getDY()       const { return dy; }
	double getSpeed()    const;

	// setters
	void setDX(double dx) { this->dx = dx; }
	void setDY(double dy) { this->dy = dy; }
	void set(const Angle& angle, double magnitude);

	//these three are in Ticket 2
	void addDX(double dx) { this->dx += dx; }
	void addDY(double dy) { this->dy += dy; }
	void add(const Acceleration& acceleration, double time);


	//new artillery functions
	Velocity reverse()
	{
		//not sure exactly what this is supposed to do, so just having it produce a new velocity object that is the inverse?

		Velocity reverse(-dx, -dy);
		return reverse;
	}
	//adds velocity objects together
	void addV(Velocity veloci2)
	{
		double dx2 = veloci2.getDX();
		double dy2 = veloci2.getDY();

		dx += dx2;
		dy += dy2;
	}

private:
	double dx;           // horizontal velocity
	double dy;           // vertical velocity
};

