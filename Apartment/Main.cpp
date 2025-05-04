#include <iostream>
#include <vector>

class Apartment 
{
    double area;
    int rooms;
public:
    Apartment(double area, int rooms) : area(area), rooms(rooms) {}

    ~Apartment() { std::cout << "Квартирира разрушена" << std::endl; }

    void displayInfo() const 
    {
        std::cout << "Квартира с площадью: " << area 
            << " метров, с количеством комнат: " << rooms << std::endl;
    }

};

class Building 
{
    std::vector<Apartment> apartments;
public:
    Building() {}

    ~Building() { std::cout << "постройка разрушилась" << std::endl; }


    void displayInfo() const 
    {
        std::cout << "Постройки:" << std::endl;
        for (int i = 0; i < apartments.size(); i++) apartments.at(i).displayInfo();    
    }

    
    void addApartment(double area, int rooms) {
        apartments.push_back(Apartment(area, rooms));
    }

    
    void removeApartment(int index) 
    {
        if (index >= 0 && index < apartments.size()) 
        { apartments.erase(apartments.begin() + index); }
        else 
        { std::cout << "Нет такого индекса." << std::endl; }
    }
};

int main() 
{
    system("chcp 1251");
   
    std::shared_ptr<Building>building =  std::make_shared<Building>();

    building->addApartment(50.5, 2);
    building->addApartment(65.5, 2);
    
    building->displayInfo();

    building->removeApartment(0);

    building->displayInfo();

    return 0;
}