#include "DiceAndPlayer.h"

int main()
{
	srand(static_cast<int>(time(0)));
	system("chcp 1251");

	//Player player;


	Dice dice;
	std::cout << dice;

	return 0;

	/*
	Игрок берет куб
	Куб пропадает
	Игрок бросает куб
	Куб появляется и выдает число (in main)
	*/
}