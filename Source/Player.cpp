#include <Player.h>

void Player::setName(std::string input)
{
	name = input;
}

std::string Player::getName()
{
	return name;
}

void Player::setScore(int input)
{
	score = input;
}

int Player::getscore()
{
	return score;
}

Player Player::login()
{
	Player temp;
	using namespace std;

	cout << "Masukkan nama pemain : ";
	getline(cin, temp.name);
	return temp;
}