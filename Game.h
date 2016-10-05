#pragma once
#include <iostream>
/// <summary>
/// @Author K.M.
/// </summary>
class Game
{
public:
	Game();
	void run();
protected:
	void update();
	void selectWarhead();

	enum Warhead { EXPLOSIVE, NUCLEAR };


	typedef struct Position
	{
		int x;
		int y;
		void print()
		{
			std::cout << x << y << std::endl;
		}
	}Coordinates;

	typedef struct Enemy {
		Coordinates coordinates;
	}Target;
};
