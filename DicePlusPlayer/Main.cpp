#include "DiceAndPlayer.h"

int main() 
{
    system("chcp 1251");
    srand(static_cast<int>(time(0)));
    Player player;

    std::shared_ptr<Dice> dice1 = std::make_shared<Dice>(6);
    std::shared_ptr<Dice> dice2 = std::make_shared<Dice>(12);
    std::shared_ptr<Dice> dice3 = std::make_shared<Dice>(9);
    
    player.takeDice(dice1);
    player.takeDice(dice2);
    player.takeDice(dice3);

    player.rollDice();

    player.putDice(1);

    player.rollDice();

    player.takeDice(dice2);

    player.rollDice();
   
    return 0;
}