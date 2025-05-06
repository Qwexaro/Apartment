#include <iostream>
#include <vector>
#include <ctime>

class Dice
{
private:
    int facets;
public:
    Dice(int s) : facets(s) {}
    ~Dice() {
        std::cout << "dice has bin destructed" << std::endl;
    }

    int roll() {
        return rand() % facets + 1;
    }
};

class Player
{
private:
    std::vector<std::unique_ptr<Dice>> diceCollection;

public:
    //Player();
    ~Player() {
        std::cout << "player has bin destructed" << std::endl;
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

int main() {
    system("chcp 1251");
    srand(static_cast<int>(time(0)));
    Player player;

    // ������� ��������� �������
    player.takeDice(std::make_unique<Dice>(6));
    player.takeDice(std::make_unique<Dice>(6));
    player.takeDice(std::make_unique<Dice>(10));

    // ����� ������� ������
    std::cout << "���������� ������� �������:\n";
    player.rollDice();

    // ����� ������ �����
    player.putDice(1); // ������� ������ ����� (������ 1)

    return 0;
}