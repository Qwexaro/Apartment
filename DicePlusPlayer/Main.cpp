#include "DiceAndPlayer.h"

int main() 
{
    system("chcp 1251");
    srand(static_cast<int>(time(0)));
    Player player;

    std::unique_ptr<Dice> dice1 = std::make_unique<Dice>(6);
    std::unique_ptr<Dice> dice2 = std::make_unique<Dice>(12);
    std::unique_ptr<Dice> dice3 = std::make_unique<Dice>(9);
    
    player.takeDice(std::move(dice1));
    player.takeDice(std::move(dice2));
    player.takeDice(std::move(dice3));

    player.rollDice();

    player.putDice(1);

    player.rollDice();

    player.takeDice(std::move(dice1));
    player.rollDice();
   
    return 0;
}