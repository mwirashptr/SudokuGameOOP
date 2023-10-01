#pragma once
#include <fstream>

#include "Player.h"
#include "Board.h"

class Filestream
{
private:
	Player player;
	Board board;
public:
	void Init(std::string);
	Player getPlayerData(std::string text);
	Board getBoardData(std::string text);

	Player* getPlayer();
	Board* getBoard();

	void setPlayer(std::string);
};