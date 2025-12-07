/***********************************************************************
 * Source File:
 *    PHYSICS
 * Author:
 *    Mason Allen
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
	

	if (domain <= mapping[0].domain)
	{
		return mapping[0].range;
	}
	if (domain >= mapping[numMapping - 1].domain)
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

	const std::vector<std::pair<double, double>> density =
	{

		//		Altitude	Density
				{0,		 1.2250000},
				{1000,	 1.1120000},
				{2000,	 1.0070000},
				{3000,	 0.9093000},
				{4000,	 0.8194000},
				{5000,	 0.7364000},
				{6000,	 0.6601000},
				{7000,	 0.5900000},
				{8000,	 0.5258000},
				{9000,	 0.4671000},
				{10000,	 0.4135000},
				{15000,	 0.1948000},
				{20000,	 0.0889100},
				{25000,	 0.0400800},
				{30000,	 0.0184100},
				{40000,	 0.0039960},
				{50000,	 0.0010270},
				{60000,	 0.0003097},
				{70000,	 0.0000828},
				{80000,	 0.0000185}
	};

	//edge cases
	if (altitude < 0)
	{
		return  1.2250000;
	}
	if (altitude > 80000)
	{
		return 0.0000185;
	}

	//main search and linear interpolation
	for (int i = 0; i < density.size(); i++)
	{

		if (altitude == density[i].first)
		{
			return density[i].second;
		}
		else if (altitude < density[i].first)
		{
			double x1 = density[i - 1].first;
			double y1 = density[i - 1].second;
			double x2 = density[i].first;
			double y2 = density[i].second;

			double airDensity = linearInterpolation(x1, y1, x2, y2, altitude);

			return airDensity;
		}

	}


}

/*********************************************************
 * SPEED OF SOUND FROM ALTITUDE
 * determine the speed of sound for a given altitude.
 ********************************************************/
double speedSoundFromAltitude(double altitude)
{
	const std::vector<std::pair<double, double>> speedOfSound =
	{
		//	Altitude, Speed of sound  
			{0,      340},
			{1000,   336},
			{2000,   332},
			{3000,   328},
			{4000,   324},
			{5000,   320},
			{6000,   316},
			{7000,   312},
			{8000,   308},
			{9000,   303},
			{10000,  299},
			{15000,  295},
			{20000,  295},
			{25000,  295},
			{30000,  305},
			{40000,  324},
			{50000,  337},
			{60000,  319},
			{70000,  289},
			{80000,  269}
	};

	//edge cases for speed of sound
	double finalSoundSpeed;
	if (altitude <= 0)
	{
		return 340.0;
	}
	if (altitude >= 80000)
	{
		return 269.0;
	}
	//search and linear interpolation
	for (int i = 0; i < speedOfSound.size(); i++)
	{

		if (altitude == speedOfSound[i].first)
		{
			return speedOfSound[i].second;
			
		}
		else if (altitude < speedOfSound[i].first)
		{
			double x1 = speedOfSound[i - 1].first;
			double y1 = speedOfSound[i - 1].second;
			double x2 = speedOfSound[i].first;
			double y2 = speedOfSound[i].second;

			double finalSoundSpeed = linearInterpolation(x1, y1, x2, y2, altitude);
			return finalSoundSpeed;
		}
	}
}


/*********************************************************
 * DRAG FROM MACH
 * Determine the drag coefficient for a M795 shell given speed in Mach
 *********************************************************/
double dragFromMach(double speedMach)
{
	const std::vector<std::pair<double, double>> dragCoEf =
	{
		//		Mach    Drag Coef
				{0.000, 0.0000},
				{0.300, 0.1629},
				{0.500, 0.1659},
				{0.700, 0.2031},
				{0.890, 0.2597},
				{0.920, 0.3010},
				{0.960, 0.3287},
				{0.980, 0.4002},
				{1.000, 0.4258},
				{1.020, 0.4335},
				{1.060, 0.4483},
				{1.240, 0.4064},
				{1.530, 0.3663},
				{1.990, 0.2897},
				{2.870, 0.2297},
				{2.890, 0.2306},
				{5.000, 0.2656}
	};

	//edge cases for mach

	if (speedMach > 5.000)
	{
		return 0.2656;
	}

	//getting drag coefficient from mach
	for (int i = 0; i < dragCoEf.size(); i++)
	{

		if (speedMach == dragCoEf[i].first)
		{
			return dragCoEf[i].second;
		}
		else if (speedMach < dragCoEf[i].first)
		{
			double x1 = dragCoEf[i - 1].first;
			double y1 = dragCoEf[i - 1].second;
			double x2 = dragCoEf[i].first;
			double y2 = dragCoEf[i].second;

			double finalDrag = linearInterpolation(x1, y1, x2, y2, speedMach);

			return finalDrag;
		}
	}
}

