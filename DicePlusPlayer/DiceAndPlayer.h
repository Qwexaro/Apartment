#include <iostream>
#include <vector>
#include <ctime>

class Dice
{
    int facets, id;
    static int amount_dices;
public:
    
    Dice(int facets);
    
    ~Dice();

    int getId() const;
    int numberDice();
};

class Player
{
    std::vector<std::shared_ptr<Dice>> dice_collection;
public:
    Player();
    ~Player();

    void takeDice(std::shared_ptr<Dice>& dice);

    Player& putDice(int index);

    Player& rollDice();
};
