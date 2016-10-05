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
	bool again = true;
	while (again)
	{
		selectWarhead();
		acquireTarget();
		launchCodes();
		update();
		bool answered = false;
		while (!answered)
		{
			char answer;
			std::cout << "   Would you like to launch another strike? (y/n): ";
			std::cin >> answer;
			if (answer == 'y')
			{
				again = true;
				answered = true;
			}
			else if (answer == 'n')
			{
				again = false;
				answered = true;
			}
			else
				answered = false;
		}
	}
	
}

/// <summary>
/// Method to handle all game updates
/// </summary>
/// <param name="time">update delta time</param>
void Game::update()
{
	int count = 1;
	for (; target.coordinates.x > 0 || target.coordinates.y; target.coordinates.x-- && target.coordinates.y-- && count++)
	{
		
		Sleep(100);
		std::cout << "[]";
		if (count == 20)
		{
			std::cout << "\n \n";
			count = 0;
		}
	}
	int rnd = rand() % 10;
	if (rnd > 5)
	{
		std::cout << "\n \n TARGET HIT \n \n";
	}
	else
	{
		std::cout << "\n \n TARGET MISSED \n \n";
	}
}

void Game::selectWarhead()
{
	bool warheadSelected = false;
	while (!warheadSelected)
	{
		float decision = 0;
		std::cout << "   Please choose a warhead: \n" << "  1) Explosive \n  2) Nuclear \n \n Please Enter number: ";
		std::cin >> decision;
		std::cout << std::endl;
		if (decision == 1)
		{
			payload = Warhead::EXPLOSIVE;
			std::cout << "   Explosive Selected." << std::endl;
			warheadSelected = true;
		}
		else if (decision == 2)
		{
			payload = Warhead::NUCLEAR;
			std::cout << "   Nuclear Selected" << std::endl;
			warheadSelected = true;
		}
		else
		{
			std::cout << "   Please choose a valid option." << std::endl;
		}
	}
	
}
void Game::acquireTarget()
{
	std::cout << "   Please enter the targets X coordinate: ";
	std::cin >> target.coordinates.x;
	std::cout << "   Please enter the targets Y coordinate: ";
	std::cin >> target.coordinates.y;

	std::cout << "\n ";
	target.coordinates.print();
}
void Game::launchCodes()
{
	bool launch = false;
	while (!launch) {
		int launchCode[6];
		std::string launchCodeX = "";
		for (int i = 0; i < 6;i++)
		{
			launchCode[i] = rand() % 10;
			launchCodeX += std::to_string(launchCode[i]);
		}
		std::cout << "   Launch Code (" << launchCodeX << ")" << std::endl;
		std::string enteredCodeX;
		std::cout << "   Please enter launch code: ";
		std::cin >> enteredCodeX;
		if (enteredCodeX == launchCodeX)
		{
			launch = true;
		}
		else
		{
			std::cout << "   ERROR, LAUNCH CODE INCORRECT" << std::endl;
		}
	}
}

