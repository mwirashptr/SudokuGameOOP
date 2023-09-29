#pragma once
#include <Fstream>

#include "Player.h"
#include "Board.h"

class Filestream
{
private:
	std::array<Player, 100> pQueue;
	std::array<Board, 100> bQueue;

	void setPlayerArray();
	void setBoardArray();
public:
	void getPlayerArray();
	void getBoardArray();
};