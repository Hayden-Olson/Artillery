/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    <your name here>
 * Summary:
 *    Laws of motion, effects of gravity, wind resistence, etc.
 ************************************************************************/
  
 #include "physics.h"  // for the prototypes
#include <cmath>
#include <math.h>
#include <vector>
#include <array>
#include <iomanip>
 
 
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
	//searches through vector (tabular data) for two closest values
//then uses linear interpolation to calculate the corresponding value for gravity
	const std::vector<std::pair<double, double>> gravity =
	{
		{0,		9.807},
		{1000,	9.804},
		{2000,	9.801},
		{3000,	9.797},
		{4000,	9.794},
		{5000,	9.791},
		{6000,	9.788},
		{7000,	9.785},
		{8000,	9.782},
		{9000,	9.779},
		{10000,	9.776},
		{15000,	9.761},
		{20000,	9.745},
		{25000,	9.730},
		{30000,	9.715},
		{40000,	9.684},
		{50000,	9.654},
		{60000,	9.624},
		{70000,	9.594},
		{80000,	9.564}
	};

	//edge cases
	if (altitude < 0)
	{
		return 9.807;
	}
	if (altitude > 80000)
	{
		return 9.564;
	}

	//main search and linear interpolation
	for (int i = 0; i < gravity.size(); i++)
	{

		if (altitude == gravity[i].first)
		{
			return gravity[i].second;
		}
		else if (altitude < gravity[i].first)
		{
			double x1 = gravity[i - 1].first;
			double y1 = gravity[i - 1].second;
			double x2 = gravity[i].first;
			double y2 = gravity[i].second;

			double gravCoef = linearInterpolation(x1, y1, x2, y2, altitude);

			return gravCoef;
		}

	}


	/*
	* I spent a while trying to get a raw calculation to work before I realised that we were supposed to be using linear interpolation on the prototype set of data.
	* leaving this here for now.
	* 
	double earthRad = 6371000; //in meters to match altitude
	double surfaceGrav = 9.807;

	double gravCoef = surfaceGrav * ( (earthRad / (earthRad + altitude)) * (earthRad / (earthRad + altitude)) );

	return gravCoef
	*/
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

