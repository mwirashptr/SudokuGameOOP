#pragma once

#include <array>
#include <string>

const int N = 9;

class Board
{
private:
	std::array<std::array<char, N>, N> boardArray;
public:
	void setCell(int x, int y, char input);
	char getCell(int x, int y);
	void setBoard(std::string input);
	bool isValid(int input);
	bool isFull();

	std::array<std::array<char, N>, N> getBoard();

	bool checkHorizontal();
	bool checkVertical();
	bool checkRegion();
};