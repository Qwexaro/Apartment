#pragma once

//#include <iostream>
#include <ctime>
#include <vector>
#include "Interface.h"

class Dice
{
	int facets, num;
public:
	Dice();
	~Dice();
	//int throwDice();
	friend std::ostream& operator<<(std::ostream& out, const Dice& dice);
};

class Player : public Take, public Put, public Throw, public Dice
{
	std::vector<std::unique_ptr<Dice>> dices;
public:
	Player();
	~Player();
	void take() override;
	void throwCube() override;
	void put() override;
};