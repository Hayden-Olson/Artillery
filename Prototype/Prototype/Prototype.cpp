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
 * MAIN
 ****************************************************/
int main()
{
	float distance = 0; //x value
	float altitude = 0; //y value

	float timeScale = 1;
	float acceleration = 0;
	float drat = 0;
	float gravity = 0;
	float initialAngle = (75 * M_PI / 180);
	float initialSpeed = 827;
	
	float dx = (initialSpeed * cos(initialAngle));
	float dy = (initialSpeed * sin(initialAngle));

	
	float velocity = sqrt((dx * dx) + (dy * dy));


	for (int i = 1; i <= 20; i++)
	{
		distance = distance + dy * timeScale; //no acceleration, as it is 0
		altitude = altitude + dx * timeScale; //no gravity, as it is 0
	}

	cout << "Distance : " << distance << "   Altitude : " << altitude;

}


