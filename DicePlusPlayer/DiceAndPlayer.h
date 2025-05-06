#include <iostream>
#include <vector>
#include <ctime>

class Dice
{
    int facets;
public:
    
    Dice(int s);
    
    ~Dice();

    int throwDice();
};

class Player
{
    std::vector<std::unique_ptr<Dice>> diceCollection;
public:
    
    ~Player();

    void takeDice(std::unique_ptr<Dice> dice);

    void putDice(int index);

    void rollDice();
};
