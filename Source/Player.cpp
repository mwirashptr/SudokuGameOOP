#include <Player.h>

Player::Player()
{
	name = "";
}

void Player::setName(std::string input)
{
	name = input;
}

std::string Player::getName()
{
	return name;
}

void Player::setCounter()
{
	winCounter++;
}

int Player::getCounter()
{
	return winCounter;
}

Player Player::login()
{
	Player temp;
	using namespace std;

	cout << "Masukkan nama pemain : ";
	getline(cin, temp.name);
	return temp;
}