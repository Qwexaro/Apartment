#include <iostream>

class Coin 
{

};

class Heart {

};

class Human 
{
public:
	std::shared_ptr<Coin>coin;
	Heart heart;
};


int main()
{
	std::shared_ptr<Human>human = std::make_shared<Human>();
	std::shared_ptr<Coin>coin = std::make_shared<Coin>();
	human->coin = coin;
	coin.reset();
	return 0;
}