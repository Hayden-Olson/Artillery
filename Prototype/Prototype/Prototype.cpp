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

using namespace std;

/****************************************************
 * INERTIA
 ****************************************************/
double inertia(double acceleration, double drag, double gravity)
{
	for (int i = 0; i < 21; i++)
	{
		// Do nothing
	}
	return 0.0;
}

/****************************************************
 * ACCELERATION
 ****************************************************/
double acceleration()
{
	return 0.0;
}

/****************************************************
 * GROUND IMPACT
 ****************************************************/
double ground_impact()
{
	return 0.0;
}

/****************************************************
 * GRAVITY
 ****************************************************/
double gravity()
{
	double table[20][2] =
	{
//		Altitude	Gravity m/s^2
		{0,			9.807},
		{1000,		9.804},
		{2000,		9.801},
		{3000,		9.797},
		{4000,		9.794},
		{5000,		9.791},
		{6000,		9.788},
		{7000,		9.785},
		{8000,		9.782},
		{9000,		9.779},
		{10000,		9.776},
		{15000,		9.761},
		{20000,		9.745},
		{25000,		9.730},
		{30000,		9.715},
		{40000,		9.684},
		{50000,		9.654},
		{60000,		9.624},
		{70000,		9.594},
		{80000,		9.564}

	};

	return -9.81;
}

/****************************************************
 * DRAG
 ****************************************************/
double drag(double velocity)
{
	double diameter = 0.15489;
	double radius = diameter / 2;
	double area = ((radius * M_PI) * (radius * M_PI));

	double drag = 0.5 * drag_coefficient() * air_density() * velocity * area;

	return 0.0;
}

/****************************************************
 * AIR DENSITY
 ****************************************************/
double air_density()
{
	double table[20][2] =
	{
		//		Altitude	Density
				{0,			1.2250000},
				{1000,		1.1120000},
				{2000,		1.0070000},
				{3000,		0.9093000},
				{4000,		0.8194000},
				{5000,		0.7364000},
				{6000,		0.6601000},
				{7000,		0.5900000},
				{8000,		0.5258000},
				{9000,		0.4671000},
				{10000,		0.4135000},
				{15000,		0.1948000},
				{20000,		0.0889100},
				{25000,		0.0400800},
				{30000,		0.0184100},
				{40000,		0.0039960},
				{50000,		0.0010270},
				{60000,		0.0003097},
				{70000,		0.0000828},
				{80000,		0.0000185}


	};

	return 1.225;
}

/****************************************************
 * DRAG COEFFICIENT
 ****************************************************/
double drag_coefficient()
{

	double table[20][2] = 
	{
//		Mach		Drag Coefficient
		{0.000,		0.0000},
		{0.300,		0.1629},
		{0.500,		0.1659},
		{0.700,		0.2031},
		{0.890,		0.2597},
		{0.920,		0.3010},
		{0.960,		0.3287},
		{0.980,		0.4002},
		{1.000,		0.4258},
		{1.020,		0.4335},
		{1.060,		0.4483},
		{1.240,		0.4064},
		{1.530,		0.3663},
		{1.990,		0.2897},
		{2.870,		0.2297},
		{2.890,		0.2306},
		{5.000,		0.2656}

	};
	return 0.47;
}

/****************************************************
 * Speed of Sound
 ****************************************************/
double sound_speed()
{
	int table[20][2] =
	{
		// Altitude		Speed of Sound m/s
			{0,			340},
			{1000,		336},
			{2000,		332},
			{3000,		328},
			{4000,		324},
			{5000,		320},
			{6000,		316},
			{7000,		312},
			{8000,		308},
			{9000,		303},
			{10000,		299},
			{15000,		295},
			{20000,		295},
			{25000,		295},
			{30000,		305},
			{40000,		324},
			{50000,		337},
			{60000,		319},
			{70000,		289},
			{80000,		269}
	};


}


/****************************************************
 * HIT THE GROUND
 ****************************************************/
double hit_the_ground()
{
	return 0.0;
}

/****************************************************
 * MAIN
 ****************************************************/
int main()
{
	double time = 1;
	double mass = 46.7;
	double velocity = 827;

	//just temporary variables to curb stub errors
	float distance;

	//we need to still give the tables actual functionality for calculations, and implement linear interpolation.
	//a lot of parts are here, but they need to actually do things still.


	
	inertia(acceleration(), drag(velocity), gravity());
	
	float angle;
	cout << "What is the angle of the howitzer where 0 is up? ";
	cin >> angle;
	cout << "Distance:     " << distance << "Hang Time:     " << time << endl;
}


