/****************************************************
 * Names: Hayden Olson & Mason Allen
 * Project: Artillery Prototype
 * Date: 6/12/2024
 * Teacher: Brother Goddfrey
 * Description: A simple artillery simulation prototype
 ****************************************************/

#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <vector>
#include <array>
#include <iomanip>

using namespace std;

/****************************************************
 * GRAVITY CALULATIONS
 ****************************************************/
double calcGravity(double altitude)
{
	//searches through vector (tabular data) for two closest values
	//then uses linear interpolation to calculate the corresponding value for gravity

	const vector<pair<double, double>> gravity = 
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

			double lin1 = (altitude - x1) / (x2 - x1);
			double lin2 = y1 + lin1 * (y2 - y1);

			return lin2;
		}

	}
	return -9.8;
};


/****************************************************
 * Calculate Air Density
 * this is basically the same function as calcGravity
 * but with a different table
 ****************************************************/
double calcAirDensity(double altitude)
{

	const vector<pair<double, double>> density =
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

			double lin1 = (altitude - x1) / (x2 - x1);
			double lin2 = y1 + lin1 * (y2 - y1);

			return lin2;
		}

	}
}


/****************************************************
 * Calculate Drag Coefficient
 * similat to calcGravity and calcAirDensity, but 
 * also has to calculate mach.
 ****************************************************/
double calcDragCoEf(double altitude, double velocity)
{

	const vector<pair<double, double>> speedOfSound =
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
	if (altitude < 0)
	{
		finalSoundSpeed = 340;
	}
	if (altitude > 80000)
	{
		finalSoundSpeed = 269;
	}

	//getting speed of sound from the first table
	for (int i = 0; i < speedOfSound.size(); i++)
	{

		if (altitude == speedOfSound[i].first)
		{
			finalSoundSpeed = speedOfSound[i].second;
			break;
		}
		else if (altitude < speedOfSound[i].first)
		{
			double x1 = speedOfSound[i - 1].first;
			double y1 = speedOfSound[i - 1].second;
			double x2 = speedOfSound[i].first;
			double y2 = speedOfSound[i].second;

			double lin1 = (altitude - x1) / (x2 - x1);
			double lin2 = y1 + lin1 * (y2 - y1);

			finalSoundSpeed = lin2;
			break;
		}

	}

	double mach = velocity / finalSoundSpeed;

	const vector<pair<double, double>> dragCoEf =
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

	if (mach > 5.000)
	{
		return 0.2656;
	}

	//getting drag coefficient from mach
	for (int i = 0; i < dragCoEf.size(); i++)
	{

		if (mach == dragCoEf[i].first)
		{
			finalSoundSpeed = dragCoEf[i].first;
		}
		else if (mach < dragCoEf[i].first)
		{
			double x1 = dragCoEf[i - 1].first;
			double y1 = dragCoEf[i - 1].second;
			double x2 = dragCoEf[i].first;
			double y2 = dragCoEf[i].second;

			double lin1 = (mach - x1) / (x2 - x1);
			double lin2 = y1 + lin1 * (y2 - y1);

			return lin2;
		}
	}
}

/****************************************************
 * MAIN
 ****************************************************/
int main()
{
	double distance = 0; //x value
	double altitude = 0; //y value
	double prevDist;
	double prevAlt;

	//constants
	double timeScale = 0.01;
	double mass = 46.7;
	double diameter_m = 154.89 / 1000.0; // mm -> m
	double area = M_PI * (diameter_m * 0.5) * (diameter_m * 0.5);
	double initialAngle = (75 * M_PI / 180);
	double initialSpeed = 827;

	//velocities
	double dy = (initialSpeed * cos(initialAngle));
	double dx = (initialSpeed * sin(initialAngle));
	double totalVelocity;
	
	double hangTime = 0;


	while (altitude >= 0)
	{
		//track previous info
		prevDist = distance;
		prevAlt = altitude;


		//get new velocity from updated x and y speeds
		totalVelocity = sqrt((dx * dx) + (dy * dy));

		//get air density from altitude
		double airDensity = calcAirDensity(altitude);

		//get drag coefficient from velocity
		double dragCoEf = calcDragCoEf(altitude, totalVelocity);
		
		//calculate drag 
		double drag = 0.5 * dragCoEf * airDensity * (totalVelocity * totalVelocity) * area;
		
		//get gravity relative to altitude
		double gravity = -calcGravity(altitude);
		
		//update position
		distance = distance + dx * timeScale; 
		altitude = altitude + dy * timeScale;
		
		//convert drag force to acceleration
		double dragAccel = drag / mass;

		//get reverse angles of movement for drag 
		double dragAngle = atan2(dy, dx);
		double dragX = -dragAccel * cos(dragAngle);
		double dragY = -dragAccel * sin(dragAngle);

		//update velocities
		dy = dy + ((dragY + gravity) * timeScale);
		dx = dx + (dragX * timeScale);

		//increment hangtime
		hangTime += timeScale;
	}

	
	double impactTime = -prevAlt / (altitude - prevAlt);
	double impactDistance = prevDist + impactTime * (distance = prevDist);
	double impactMoment = hangTime - timeScale + impactTime * timeScale;

	cout << std::fixed << std::setprecision(1) << "Distance : " << impactDistance << "m  Hang Time :" << impactMoment << "s";

}


