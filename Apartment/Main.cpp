#include "Apartment.h"

int main() 
{
    system("chcp 1251");
   
    std::shared_ptr<Building>building = std::make_shared<Building>();

    building->addApartment(50.5, 2);
    building->addApartment(65.5, 1);
    building->addApartment(101.5, 6);
    building->addApartment(12.5, 2);
    building->addApartment(11.5, 7);
    building->addApartment(10.5, 1);
    building->addApartment(1.5, 1);
    building->addApartment(15.5, 2);
    
    building->info();

    building->removeApartment(0);
    building->removeApartment(0);
    building->removeApartment(0);


    building->info();


    return 0;
}