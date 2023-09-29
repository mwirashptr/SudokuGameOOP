#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>

#include <Player.h>
#include <Board.h>

class Game
{
private:
	Board b;
	Player* p = new Player;
	int timer;
	char kbInput;

public:
	Game(Player& x, Board y);

	void render();
	void input();
	bool update();

	bool retry();
	void Run();
};