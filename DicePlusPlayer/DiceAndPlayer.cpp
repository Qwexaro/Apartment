#include "DiceAndPlayer.h"

int Dice::amount_dices = 0;

Dice::Dice(int facets) : facets{ facets }, id{ ++amount_dices } {}

Player::Player(){}

Dice::~Dice() 
{
    std::cout << "dice with id: " << id << " has bin destructed" << std::endl;
}

int Dice::numberDice() 
{
    return rand() % facets + 1;
}

int Dice::getId() const
{
    return id;
}

Player::~Player() 
{
    std::cout << "player has bin destructed" << std::endl;
    dice_collection.clear();
}

void Player::takeDice(std::shared_ptr<Dice>& dice) 
{
    std::cout << "Берется dice с id: " << dice->getId() << std::endl;
    dice_collection.push_back(dice);
    
}

Player& Player::putDice(int index) 
{
    if (index < dice_collection.size()) 
    {
        std::cout << "Кубик с id: " << dice_collection.at(index)->getId() << " возвращен на стол.\n";
        dice_collection.erase(dice_collection.begin() + index);
    }
    return *this;
}

Player& Player::rollDice()
{
    for (int i = 0; i < dice_collection.size(); i++)
    {
        std::cout << "Бросок кубика с id: "<< dice_collection.at(i)->getId() << ": " << dice_collection.at(i)->numberDice() << "\n";
    }
    return *this;
}