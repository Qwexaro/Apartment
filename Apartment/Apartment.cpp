#include "Apartment.h"

Apartment::Apartment() : area{0}, rooms{0}{}

Apartment::Apartment(double area, int rooms) : area{ area }, rooms{ rooms } {}

Apartment::~Apartment() 
{
    std::cout << "Квартирира с area: " << area 
        << " и с rooms: " << rooms << " разрушена" << std::endl; 
}

Building::Building() {}

Building::~Building() { std::cout << "постройка разрушилась" << std::endl; }

void Apartment::info() const
{
    std::cout << "Квартира с площадью: " << area
        << " метров, с количеством комнат: " << rooms << std::endl;
}

void Building::info() const
{
    std::cout << "Постройки:" << std::endl;
    for (int i = 0; i < apartments.size(); i++) apartments.at(i)->info();
}

void Building::addApartment(double area, int rooms) 
{
    apartments.push_back(std::make_shared<Apartment>(area, rooms));
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