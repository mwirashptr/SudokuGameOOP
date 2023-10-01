#pragma once

#include <iostream>
#include <string>

class Player
{
private:
	std::string name = "";
	int winCounter = 0;

public:
	void setName(std::string input);
	std::string getName();
	void setCounter(int input);
	void addCounter();
	int getCounter();
};
