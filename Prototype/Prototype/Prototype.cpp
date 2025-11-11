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

using namespace std;

/****************************************************
 * GRAVITY CALULATIONS
 ****************************************************/
float calcGravity(float altitude)
{
	//searches through vector (tabular data) for two closest values
	//then uses linear interpolation to calculate the corresponding value for gravity

/* commented out while I figure out how to actually format the vector
	{

		(0,		9.807),
		(1000,	9.804),
		(2000,	9.801),
		(3000,	9.797),
		(4000,	9.794),
		(5000,	9.791),
		(6000,	9.788),
		(7000,	9.785),
		(8000,	9.782),
		(9000,	9.779),
		(10000,	9.776),
		(15000,	9.761),
		(20000,	9.745),
		(25000,	9.730),
		(30000,	9.715),
		(40000,	9.684),
		(50000,	9.654),
		(60000,	9.624),
		(70000,	9.594),
		(80000,	9.564)
	};
	*/
};


/****************************************************
 * MAIN
 ****************************************************/
int main()
{
	float distance = 0; //x value
	float altitude = 0; //y value

	//constant
	float timeScale = 0.01;
	//calculated on each loop
	float gravity;

	float drag = 0;

	float initialAngle = (75 * M_PI / 180);
	float initialSpeed = 827;

	float dy = (initialSpeed * cos(initialAngle));
	float dx = (initialSpeed * sin(initialAngle));


	float totalVelocity = sqrt((dx * dx) + (dy * dy));
	float hangTime = 0;

	while (altitude >= 0)
	{
		gravity = calcGravity(altitude);
		distance = distance + dx * timeScale; //no acceleration, as it is 0
		altitude = altitude + dy * timeScale + 0.5 * (gravity * (timeScale * timeScale));

		dy = dy + (gravity * timeScale);
		hangTime += timeScale;
	}

	cout << "Distance : " << distance << "   Altitude : " << altitude << "   Hang Time :" << hangTime;

}


