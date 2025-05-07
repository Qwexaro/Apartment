#include <iostream>
#include <vector>
#include <ctime>
#include "Interfaces.h"

class Dice : public IThrow
{
    int count_faces;
    int id;
    static int amount_of_dice;
public:
    Dice();
    Dice(int count_faces);
    ~Dice();
    int getId() const;
    void numberDice() override;
};


class Player : public IThrow
{
    std::vector<std::unique_ptr<Dice>> dice;
public:
    Player();
    Player(const Dice& dice);
    ~Player();
    Dice& takeDice();

    void numberDice() override;

    Player& dropDice();

    friend std::ostream& operator<<(std::ostream& out, const Player& player);
};

