#include "Game.h"

/// <summary>
/// @author Keenan McEntee
/// @date 05/10/2016
/// @version 1.0
/// @Description: Main class to our game that handles everything in our game.
/// </summary>
Game::Game()
{

}
/// <summary>
/// Main game entry point - runs until user quits.
/// </summary>
void Game::run()
{
	bool again = true;			//Boolean setup to keep the game running in a loop until this changes to false or the user exits.
	while (again)
	{
		selectWarhead();		//Call's the select warhead function which is step 1 of our missile firing system.
		acquireTarget();		//Call's the acquire target function which is our second step in our system.
		launchCodes();			//Launch codes is the third and final step of user interaction before the game ends.
		update();
		bool answered = false;

		//This while loop is only to see if the user would like to continue playing or to exit the game.
		//It also includes user error checking.
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
/// Method to handle making the game look like it is doing something important
/// or calculations when all it really does is make it last a bit longer.
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

/*
//This is the first step in our game and is a function that handles making the user think that selecting a type of warhead is important.
//It checks for an answer and if it is an incorrect value it will ask again until a proper value is entered.
*/
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
/*
//This is our second function and its linked to the update method as in we input the target position here which is later used in update.
*/
void Game::acquireTarget()
{
	std::cout << "   Please enter the targets X coordinate: ";
	std::cin >> target.coordinates.x;
	std::cout << "   Please enter the targets Y coordinate: ";
	std::cin >> target.coordinates.y;

	std::cout << "\n ";
	target.coordinates.print();
	//This is just here because later we use a countdown to make the game look important.
	if (target.coordinates.x < 0)
	{
		target.coordinates.x = target.coordinates.x * -1;
	}
	if (target.coordinates.y < 0)
	{
		target.coordinates.y = target.coordinates.y * -1;
	}
}
/*
//This part in the code was probably the most difficult. It pseudo-randomises each launchcode value and then outputs all 6 of them as a string.
//We then use this to compare to a string we input to check if our input is correct or not.
//If our input is not correct, the game will redo this section again and output an error message.
*/
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

