#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <time.h>

#include "Filestream.h"

static std::string text = "";

class Game
{
private:
	Filestream data;
	std::array<std::array<char, 9>, 9> level;
	int timer = 0;
	char kbInput = ' ';

public:
	Player* getPlayer();
	Board* getBoard();

	void render();
	void input();
	bool update();

	void Login();
	void Init();
	void StartMenu();

	bool retry();
	void Run();
	void Play();
};