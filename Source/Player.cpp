#include <Player.h>

void Player::setName(std::string input)
{
	name = input;
}

std::string Player::getName()
{
	return name;
}

void Player::setCounter(int input)
{
	winCounter = input;
}

void Player::addCounter()
{
	winCounter++;
}

int Player::getCounter()
{
	return winCounter;
}