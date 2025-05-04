#include "Apartment.h"

Apartment::Apartment(double area, int rooms) : area(area), rooms(rooms) {}

Apartment::~Apartment() { std::cout << "���������� ���������" << std::endl; }

void Apartment::info() const
{
    std::cout << "�������� � ��������: " << area
        << " ������, � ����������� ������: " << rooms << std::endl;
}

Building::Building() {}

Building::~Building() { std::cout << "��������� �����������" << std::endl; }

void Building::info() const
{
    std::cout << "���������:" << std::endl;
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
        std::cout << "��� ������ �������." << std::endl;
    }
}