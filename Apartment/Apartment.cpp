#include "Apartment.h"

Apartment::Apartment(double area, int rooms) : area(area), rooms(rooms) {}

Apartment::~Apartment() { std::cout << "Квартирира разрушена" << std::endl; }

void Apartment::info() const
{
    std::cout << "Квартира с площадью: " << area
        << " метров, с количеством комнат: " << rooms << std::endl;
}

Building::Building() {}

Building::~Building() { std::cout << "постройка разрушилась" << std::endl; }

void Building::info() const
{
    std::cout << "Постройки:" << std::endl;
    for (int i = 0; i < apartments.size(); i++) apartments.at(i).info();
}

void Building::addApartment(double area, int rooms) 
{
    apartments.push_back(Apartment(area, rooms));
}


void Building::removeApartment(int index)
{
    if (index >= 0 && index < apartments.size())
    {
        apartments.erase(apartments.begin() + index);
    }
    else
    {
        std::cout << "Нет такого индекса." << std::endl;
    }
}