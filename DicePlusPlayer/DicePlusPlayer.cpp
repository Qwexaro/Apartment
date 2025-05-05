#include "DiceAndPlayer.h"


Player::Player(){}

Player::~Player()
{
	std::cout << "игрок уничтожился " << std::endl;
}

Dice::Dice() : facets{rand()%6+1}, num{facets}{}

Dice::~Dice()
{
	std::cout << "Кубик с количеством граней " << facets << ", уничтожен" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Dice& dice)
{
	out << "Кубик с количеством граней: " << dice.facets 
		<< ", с числом: " << dice.num << std::endl;
	return out;
}

void Player::take()
{
	std::cout << "Игрок берет: ";
}

void Player::put()
{
	std::cout << "Игрок ложит: ";
}

void Player::throwCube()
{
	std::cout << "Игрок бросает кубик: ";
}