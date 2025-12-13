/**********************************************************************
 * Header File:
 *    SIMULATION
 * Author:
 *    <your name here>
 * Summary:
 *    Execute one simulation of a projectile being fired.
 ************************************************************************/

#pragma once
#include "position.h"
#include "uiInteract.h"  
#include "uiDraw.h"      
#include "ground.h"
#include "howitzer.h"



 /*********************************************
  * Simulation
  * Execute one simulation of a projectile being fired.
  *********************************************/
class Simulator
{
public:
   Simulator(const Position & posUpperRight) : ground(posUpperRight), howitzer() {}

   void display(ogstream & gout);

   Howitzer howitzer;
   Ground ground;
};


