#include <iostream>
#include <vector>
#include <ctime>

class Dice
{
private:
    int sides;
public:
    Dice(int s) : sides(s) {}
    ~Dice() {
        std::cout << "dice has bin destructed";
    }

    int roll() {
        return rand() % sides + 1;
    }
};

class Player
{
private:
    std::vector<std::unique_ptr<Dice>> diceCollection;

public:
    Player();
    ~Player() {
        std::cout << "player has bin destructed";
    }

    void takeDice(std::unique_ptr<Dice> dice) {
        diceCollection.push_back(std::move(dice));
    }

    void putDice(int index) {
        if (index < diceCollection.size()) {
            std::cout << "����� � " << diceCollection.at(index)->roll() << " ��������� �� ����.\n";
            diceCollection.erase(diceCollection.begin() + index);
        }
    }

    void rollDice()
    {
        for (int i = 0; i < diceCollection.size(); i++)
        {
            std::cout << "������ ������ " << i + 1 << ": " << diceCollection.at(i)->roll() << "\n";
        }
    }
};