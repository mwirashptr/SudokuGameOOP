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
	Player p;
	int timer = 0;
	char kbInput = ' ';
public:
	Game();
	void render();
	void input();
	bool update();

	bool retry();
	void Run();
};