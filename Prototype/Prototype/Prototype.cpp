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
 * GRAVITY CALULATIONS
 ****************************************************/
float calcGravity(float altitude)
{
	//searches through array for two closest values
	//then uses linear interpolation to calculate the corresponding value for gravity


}


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


