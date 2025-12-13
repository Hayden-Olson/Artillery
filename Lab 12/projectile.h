/**********************************************************************
 * Header File:
 *    PROJECTILE
 * Author:
 *    <your name here>
 * Summary:
 *    Everything we need to know about a projectile
 ************************************************************************/

#pragma once

#include <list>
#include "position.h"
#include "velocity.h"
#include "physics.h"
#include "uiDraw.h"
#include "angle.h"

#define DEFAULT_PROJECTILE_WEIGHT 46.7       // kg
#define DEFAULT_PROJECTILE_RADIUS 0.077545   // m

// forward declaration for the unit test class
class TestProjectile; 

 /**********************************************************************
  * Projectile
  *    Everything we need to know about a projectile
  ************************************************************************/
class Projectile
{
public:
   // Friend the unit test class
   friend ::TestProjectile;

   // create a new projectile with the default settings
   Projectile() : mass(DEFAULT_PROJECTILE_WEIGHT), radius(DEFAULT_PROJECTILE_RADIUS) {}



   // advance the round forward until the next unit of time
   void advance(double simulationTime) 
   {
       PositionVelocityTime tempPVT;

       if (!flightPath.empty()) 
       {
           double timeValue = simulationTime - flightPath.back().t;
           //need to get accleration and velocity based on altitude and such.
           double altitude = flightPath.back().pos.getMetersY();
           double pVelocityX = flightPath.back().v.getDX();
           double pVelocityY = flightPath.back().v.getDY();
           double pSpeed = flightPath.back().v.getSpeed();

           double airDensity = densityFromAltitude(altitude);
           double gravity = gravityFromAltitude(altitude);
           double speedOfSound = speedSoundFromAltitude(altitude);
           double mach = pSpeed / speedOfSound;

           double drag = dragFromMach(mach);
           double forceX = forceFromDrag(airDensity, -drag, radius, pVelocityX);
           double forceY = forceFromDrag(airDensity, drag, radius, pVelocityY);

           //something is going wrong before here. acceleration for both is off, but I'm unsure what that might be from.
           double pAccelerationX = accelerationFromForce(forceX, mass);
           double pAccelerationY = accelerationFromForce(forceY, mass);
           pAccelerationY -= gravity;

           double pAddVelocityX = velocityFromAcceleration(pAccelerationX, timeValue);
           double pAddVelocityY = velocityFromAcceleration(pAccelerationY, timeValue);


           // x = x + vt + 0.5at^2 

           tempPVT.pos.setMetersX(flightPath.back().pos.getMetersX() + (flightPath.back().v.getDX() * timeValue) + (0.5 * (-pAccelerationX * timeValue * timeValue)));
           tempPVT.pos.setMetersY(flightPath.back().pos.getMetersY() + (flightPath.back().v.getDY() * timeValue) + (0.5 * (pAccelerationY * timeValue * timeValue)));
           //making the adjustments to velocity
           tempPVT.v.setDX(flightPath.back().v.getDX() + pAddVelocityX);
           tempPVT.v.setDY(flightPath.back().v.getDY() + pAddVelocityY);
           //increment the timer (?)
           tempPVT.t = simulationTime;
           //add the new PositionVelocityTime to the end of the list.
           flightPath.push_back(tempPVT);
       }
   }

   void reset()
       //pretty simple, nothing fancy
   {
       mass = DEFAULT_PROJECTILE_WEIGHT;
       radius = DEFAULT_PROJECTILE_RADIUS;
       flightPath = {};
   }

   void fire(Angle angle, Position position, double muzzleVelocity)
   {
       PositionVelocityTime pvt;
       pvt.pos = position;

       Velocity vel;
       vel.set(angle, muzzleVelocity); //this should calculate the velocity from the angle and muzzle velocity, hopefully

       pvt.v = vel;

       pvt.t = 1.0;

       flightPath.push_back(pvt);
   }

private:

   // keep track of one moment in the path of the projectile
   struct PositionVelocityTime
   {
      PositionVelocityTime() : pos(), v(), t(0.0) {}
      Position pos;
      Velocity v;
      double t;
   };

   double mass;           // weight of the M795 projectile. Defaults to 46.7 kg
   double radius;         // radius of M795 projectile. Defaults to 0.077545 m
   std::list<PositionVelocityTime> flightPath;
};