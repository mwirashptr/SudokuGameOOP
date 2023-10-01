#include "Filestream.h"

void Filestream::Init(std::string input)
{
	player = getPlayerData(input);
	int random = rand() % 10 + 1;
	board = getBoardData(std::to_string(random));
}

Player Filestream::getPlayerData(std::string text)
{
	Player temp;
	std::string wincounter = "";
	std::fstream data("Player/" + text + ".txt");

	char c;
	while (data.get(c))
		wincounter = wincounter + c;

	if (wincounter == "")
	{
		data << "0";
		wincounter = "0";
	}

	temp.setName(text);
	temp.setCounter(std::stoi(wincounter));
	data.close();

	return temp;
}

Board Filestream::getBoardData(std::string text)
{
	Board temp;
	std::ifstream data("Board/" + text + ".txt");

	char c;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			data.get(c);
			temp.setCell(i, j, c);
		}
	}
	data.close();

	return temp;
}

Player* Filestream::getPlayer()
{
	return &player;
}

Board* Filestream::getBoard()
{
	return &board;
}

void Filestream::setPlayer(std::string text)
{
	std::ofstream data(("Player/" + text + ".txt"), std::ios::trunc);
	data << getPlayer()->getCounter();
	data.close();
}