/***********************************************************************
 * Source File:
 *    ACCELERATION
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about changing speed
 ************************************************************************/

#include "acceleration.h"
#include "angle.h"

#include <cmath>

 /*********************************************
  * ACCELERATION : ADD
  *  a += a
  *********************************************/
void Acceleration::add(Acceleration accel2)
{
	double ddx2 = accel2.getDDX();
	double ddy2 = accel2.getDDY();

	ddx += ddx2;
	ddy += ddy2;
}

/*********************************************
 * ACCELERATION : SET
 *  set from angle and direction
 *********************************************/
void Acceleration::set(const Angle& angle, double magnitude)
{
	ddy = magnitude * cos(angle.getRadians());
	ddx = magnitude * sin(angle.getRadians());
}
