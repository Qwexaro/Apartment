#include "DiceAndPlayer.h"


Dice::Dice(int s) : facets(s) {}

Dice::~Dice() 
{
    std::cout << "dice has bin destructed" << std::endl;
}

int Dice::throwDice() 
{
    return rand() % facets + 1;
}

Player::~Player() 
{
    std::cout << "player has bin destructed" << std::endl;
}

void Player::takeDice(std::unique_ptr<Dice> dice) 
{
    diceCollection.push_back(std::move(dice));
}

void Player::putDice(int index) 
{
    if (index < diceCollection.size()) 
    {
        std::cout << "Кубик с " << diceCollection.at(index)->throwDice() << " возвращен на стол.\n";
        diceCollection.erase(diceCollection.begin() + index);
    }
}

void Player::rollDice()
{
    for (int i = 0; i < diceCollection.size(); i++)
    {
        std::cout << "Бросок кубика " << i + 1 << ": " << diceCollection.at(i)->throwDice() << "\n";
    }
}