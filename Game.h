#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
/// <summary>
/// @Author: Keenan McEntee
/// @date 05/10/2016
/// @version 1.0
/// @Description: Game header that is managing setting up the methods and structures before the Game.cpp defines them.
///				  It also handles all our includes.
/// </summary>
class Game
{
public:
	Game();
	void run();
protected:
	void update();
	void selectWarhead();
	void acquireTarget();
	void launchCodes();

	enum Warhead { EXPLOSIVE, NUCLEAR };
	Warhead payload;
	

	typedef struct Position
	{
		float x;
		float y;
		void print()
		{
			std::cout << "   ("<< x <<" , "<< y << ")"<< std::endl;
		}
	}Coordinates;

	typedef struct Enemy {
		Coordinates coordinates;
	}Target;


	Coordinates coordinates;
	Target target;
};
