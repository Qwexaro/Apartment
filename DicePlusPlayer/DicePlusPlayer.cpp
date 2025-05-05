#include "DiceAndPlayer.h"


Player::Player(){}

Player::~Player()
{
	std::cout << "����� ����������� " << std::endl;
}

Dice::Dice() : facets{rand()%6+1}, num{facets}{}

Dice::~Dice()
{
	std::cout << "����� � ����������� ������ " << facets << ", ���������" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Dice& dice)
{
	out << "����� � ����������� ������: " << dice.facets 
		<< ", � ������: " << dice.num << std::endl;
	return out;
}

void Player::take()
{
	std::cout << "����� �����: ";
}

void Player::put()
{
	std::cout << "����� �����: ";
}

void Player::throwCube()
{
	std::cout << "����� ������� �����: ";
}