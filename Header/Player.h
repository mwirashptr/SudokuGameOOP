#pragma once

#include <iostream>
#include <string>

class Player
{
private:
	std::string name;
	int winCounter = 0;

public:
	Player();

	void setPlayer(std::string input, int winInput);
	void setName(std::string input);
	std::string getName();
	void setCounter();
	int getCounter();

	Player login();
};
