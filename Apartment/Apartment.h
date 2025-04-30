#pragma once
#include <iostream>

class Apartment
{
	double square;
	int count_rooms;
public:
	Apartment();
	~Apartment();
	friend std::ostream& operator<<(std::ostream& os, const Apartment& apartment);
};

class Building
{
	int lots_of_apartments;
public:
	Apartment apartment;
	Building();
	~Building();
	Building& addBuilding();
	friend std::ostream& operator<<(std::ostream& os, const Building& building);
};