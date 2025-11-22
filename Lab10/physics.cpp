/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    <your name here>
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/
  
 #include "physics.h"  // for the prototypes
 
 /*********************************************************
 * LINEAR INTERPOLATION
 * From a list of domains and ranges, linear interpolate
 *********************************************************/
double linearInterpolation(const Mapping mapping[], int numMapping, double domain)
{
	double range = 999.9;
	

	if (domain < mapping[0].domain)
	{
		return mapping[0].range;
	}
	if (domain > mapping[numMapping - 1].domain)
	{
		return mapping[numMapping - 1].range;
	}


	for (int i = 0; i < numMapping; i++)
	{

		if (domain == mapping[i].domain)
		{
			return mapping[i].range;
		}
		else if (domain < mapping[i].domain)
		{
			double d0 = mapping[i - 1].domain;
			double r0 = mapping[i - 1].range;
			double d1 = mapping[i].domain;
			double r1 = mapping[i].range;

			range = linearInterpolation(d0, r0, d1, r1, domain);
			return range;
		}

	}
}

/*********************************************************
 * GRAVITY FROM ALTITUDE
 * Determine gravity coefficient based on the altitude
 *********************************************************/
double gravityFromAltitude(double altitude)
{
   return -99.9;
}

/*********************************************************
 * DENSITY FROM ALTITUDE
 * Determine the density of air based on the altitude
 *********************************************************/
double densityFromAltitude(double altitude)
{
   return -99.9;
}

/*********************************************************
 * SPEED OF SOUND FROM ALTITUDE
 * determine the speed of sound for a given altitude.
 ********************************************************/
double speedSoundFromAltitude(double altitude)
{
   return -99.9;
}


/*********************************************************
 * DRAG FROM MACH
 * Determine the drag coefficient for a M795 shell given speed in Mach
 *********************************************************/
double dragFromMach(double speedMach)
{
   return -99.9;
}

