#include "Apartment.h"

int main() 
{
    system("chcp 1251");
   
    std::shared_ptr<Building>building =  std::make_shared<Building>();

    building->addApartment(50.5, 2);
    building->addApartment(65.5, 2);
    
    building->info();

    building->removeApartment(0);

    building->info();

    return 0;
}