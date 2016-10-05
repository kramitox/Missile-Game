#include "Game.h"

/// <summary>
/// @author Keenan McEntee
/// @date 05/10/2016
/// @version 1.0
/// 
/// </summary>
Game::Game()
{

}
/// <summary>
/// Main game entry point - runs until user quits.
/// </summary>
void Game::run()
{
	selectWarhead();
	acquireTarget();
	launchCodes();
}

/// <summary>
/// Method to handle all game updates
/// </summary>
/// <param name="time">update delta time</param>
void Game::update()
{

}

void Game::selectWarhead()
{
	bool warheadSelected = false;
	while (!warheadSelected)
	{
		float decision = 0;
		std::cout << "Please choose a warhead: \n" << "  1) Explosive \n  2) Nuclear \n \n Please Enter number: ";
		std::cin >> decision;
		std::cout << std::endl;
		if (decision == 1)
		{
			payload = Warhead::EXPLOSIVE;
			std::cout << "Explosive Selected." << std::endl;
			warheadSelected = true;
		}
		else if (decision == 2)
		{
			payload = Warhead::NUCLEAR;
			std::cout << "Nuclear Selected" << std::endl;
			warheadSelected = true;
		}
		else
		{
			std::cout << "Please choose a valid option." << std::endl;
		}
	}
	
}
void Game::acquireTarget()
{
	std::cout << "Please enter the targets X coordinate: ";
	std::cin >> target.coordinates.x;
	std::cout << "Please enter the targets Y coordinate: ";
	std::cin >> target.coordinates.y;

	std::cout << "\n \n \n";
	target.coordinates.print();
}
void launchCodes()
{
	int launchCode = rand;
	int enteredCode = 0;
	std::cout << "Launch code = (" << launchCode << ")" << std::endl;
	system("pause");
}

