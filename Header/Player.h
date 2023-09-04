#pragma once
#include <iostream>

#include <string>

class Player
{
private:
	std::string name;
	int score = 0;
public:
	void setName(std::string input);
	std::string getName();
	void setScore(int input);
	int getscore();

	Player login();
};
