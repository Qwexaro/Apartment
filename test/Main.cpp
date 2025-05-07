#include <iostream>
#include <vector>
#include <ctime>

class Dice {
    int count_faces;
    int id;
    static int amount_of_dice;
public:
    Dice() : count_faces(6), id(++amount_of_dice) {}
    Dice(int count_faces) : count_faces(count_faces) {}
    ~Dice() { std::cout << "Деструктор кубика номер: " << id << std::endl; }
    int GetIdDice() { return id; }
    int throwDice() {
        return rand() % count_faces + 1;
    }
};

class Player {
    std::unique_ptr<Dice> dice;
public:
    Player() : dice(nullptr) {}
    Player(const Dice& dice) : dice(std::make_unique<Dice>(dice)) {}
    ~Player() { std::cout << "Деструктор" << std::endl; }
    Player& takeDice(Dice& dice) {
        std::cout << "Был взят кубик под номером: " << dice.GetIdDice() << std::endl;
        this->dice = std::make_unique<Dice>(dice);
        return *this;
    }
    void throwDice() {
        if (dice) {
            std::cout << "Выпало число: " << dice->throwDice() << std::endl;
        }
        else {
            std::cout << "У игрока нету кубика!" << std::endl;
        }
    }
    Player& dropDice() {
        this->dice = nullptr;
        std::cout << "Кубик выложен!" << std::endl;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& player) {
        if (player.dice) {
            out << "Кубик есть" << std::endl << "Номер кубика: " << player.dice->GetIdDice() << std::endl;
        }
        else {
            out << "Кубика у игрока нету!" << std::endl;
        }
        return out;
    }
};

int Dice::amount_of_dice = 0;

int main() 
{
    srand(int(time(0)));
    system("chcp 1251");
    system("cls");
    Dice dice;
    Dice dice1;
    Dice dice2;
    Player player;
    player.takeDice(dice);
    std::cout << player;
    player.throwDice();
    player.dropDice();
    std::cout << std::endl;

    player.takeDice(dice1);
    std::cout << player;
    player.throwDice();
    player.dropDice();
    std::cout << std::endl;

    player.takeDice(dice2);
    std::cout << player;
    player.throwDice();
    player.dropDice();
    std::cout << std::endl;
}