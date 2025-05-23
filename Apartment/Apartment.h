#include <iostream>
#include <vector>
#include "Interface.h"

class Apartment : public CheckInfo
{
    double area;
    int rooms;
public:
    Apartment();
    Apartment(double area, int rooms);

    ~Apartment();

    void info() const override;
};

class Building : public CheckInfo
{
    std::vector<std::unique_ptr<Apartment>> apartments;
public:
    ~Building();

    void info() const override;

    void addApartment(double area, int rooms);

    void removeApartment(int index);
};