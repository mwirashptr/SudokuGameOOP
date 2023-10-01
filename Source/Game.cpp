#include <Game.h>

Player* Game::getPlayer()
{
	return data.getPlayer();
}

Board* Game::getBoard()
{
	return data.getBoard();
}

void Game::render()
{
	using namespace std;

	//render timer
	int MM = (timer / 4) / 60;
	int SS = (timer / 4) % 60;
	cout << "\n\t\t\t\t\t\t\t" << MM << " : " << SS;

	// Render Board
	cout << "\n\n\t\t\t\t\t\t";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (getBoard()->getCell(i, j) == '0')
				cout << "  ";
			else
				cout << getBoard()->getCell(i, j) << " ";
			if (j == 2 || j == 5)
				cout << "| ";
		}
		cout << "\n\t\t\t\t\t\t";
		if (i == 2 || i == 5)
			cout << "=====================\n\t\t\t\t\t\t";
	}

	cout << "\n\t\t\t\t\t   Tekan 'a' untuk mengisi jawaban";
}

void Game::input()
{
	using namespace std;
	if (_kbhit()) {
		kbInput = _getch();
	}

	int time = 0;
	switch (kbInput)
	{
	case 'a':
		// Memasukkan Angka ke Map
		int coorX = 0, coorY = 0;
		char answer = ' ';
		while (!getBoard()->isValid(coorX) && !isdigit(answer))
		{
			cout << "\n\t\t\t\tMasukkan koordinat X : ";
			while (true) {
				time += 1;
				if (_kbhit())
				{
					answer = _getch();
					break;
				}
				Sleep(250);
			}
			coorX = int(answer) - '0';
			answer = ' ';
			cout << coorX;
			if (getBoard()->isValid(coorX) == 0)
			{
				cout << " (Input is invalid)";
			}
			else
			{
				while (!getBoard()->isValid(coorY) && !isdigit(answer))
				{
					cout << "\n\t\t\t\tMasukkan koordinat Y : ";
					while (true) {
						time += 1;
						if (_kbhit())
						{
							answer = _getch();
							break;
						}
						Sleep(250);
					}
					coorY = int(answer) - '0';
					answer = ' ';
					cout << coorY;
					if (getBoard()->isValid(coorY) == 0)
					{
						cout << " (Input is invalid)";
					}
				}
			}

			if (level[coorY - 1][coorX - 1] != '0')
			{
				cout << "\n\t\t\t\tThe cell you've targetted is invalid";
				coorX = 0; coorY = 0;
			}
		}

		while (!isdigit(answer))
		{
			cout << "\n\t\t\t\tMasukkan jawaban : ";
			while (true) {
				time += 1;
				if (_kbhit())
				{
					answer = _getch();
					break;
				}
				Sleep(250);
			}
			cout << answer;
			if (!isdigit(answer))
			{
				cout << " (Input is invalid)";
			}
			Sleep(250);
		}
		getBoard()->setCell(coorY - 1, coorX - 1, answer);
		timer = timer + time;
		kbInput = ' ';
		break;
	}
}

bool Game::update()
{
	timer += 1;
	Sleep(250);
	system("CLS");
	if (getBoard()->checkWin())
	{
		getPlayer()->addCounter();
		data.setPlayer(text);
		std::cout << "\n\n\n\t\t\t\t\t\tSelamat kamu sudah menang";
		std::cout << "\n\t\t\t\t\tNama	        : " << getPlayer()->getName();
		std::cout << "\n\t\t\t\t\tJumlah Win	: " << getPlayer()->getCounter();
		return 1;
	}
	return 0;
}

void Game::StartMenu()
{
	using namespace std;
	timer = 0; kbInput = ' ';
	cout << "\n";
	cout << "========================================================================================================================\n";
	cout << "================================      ===  ====  ==       =====    ====  ====  ==  ====  ===============================\n";
	cout << "===============================  ====  ==  ====  ==  ====  ===  ==  ===  ===  ===  ====  ===============================\n";
	cout << "===============================  ====  ==  ====  ==  ====  ==  ====  ==  ==  ====  ====  ===============================\n";
	cout << "================================  =======  ====  ==  ====  ==  ====  ==  =  =====  ====  ===============================\n";
	cout << "==================================  =====  ====  ==  ====  ==  ====  ==     =====  ====  ===============================\n";
	cout << "====================================  ===  ====  ==  ====  ==  ====  ==  ==  ====  ====  ===============================\n";
	cout << "===============================  ====  ==  ====  ==  ====  ==  ====  ==  ===  ===  ====  ===============================\n";
	cout << "===============================  ====  ==   ==   ==  ====  ===  ==  ===  ====  ==   ==   ===============================\n";
	cout << "================================      ====      ===       =====    ====  ====  ===      ================================\n";
	cout << "========================================================================================================================\n\n";

	cout << "   - Sudoku terdiri dari kotak 9 x 9\n";
	cout << "   - Anda hanya dapat menggunakan angka dari 1 - 9\n";
	cout << "   - Setiap balok 3 x 3 hanya boleh berisi angka 1 - 9\n";
	cout << "   - Setiap kolom dan baris hanya boleh berisi angka dari 1 - 9\n";
	cout << "   - Setiap angka pada blok 3 x 3, kolom, dan baris hanya dapat digunakan satu kali\n";
	cout << "   - Permainan berakhir ketika seluruh kotak Sudoku terisi dengan angka dengan benar\n\n\n\n\n\n";

	cout << "\t\t\t\t\t      Tekan ENTER untuk memulai ";
	if (cin.get() != '\n')
	{
		exit(0);
	}
	system("CLS");
}

bool Game::retry()
{
	char temp;
	using namespace std;
	cout << "\n\n\t\t\t\t\tApakah kamu ingin bermain kembali..... ? [y/n]";
	temp = _getch();
	if (temp == 'y')
	{
		return 1;
		system("CLS");
	}
	return 0;
}

void Game::Login()
{
	std::cout << "\n\t\t\t\t\tMasukkan Nama Pemain : ";
	std::cin >> text;
	system("CLS");
}

void Game::Init()
{
	data.Init(text);
	level = data.getBoard()->getBoard();
}

void Game::Run()
{
	bool run = true;
	while (run)
	{
		render();
		input();
		if (update())
		{
			run = false;
		}
	}
}

void Game::Play()
{
	bool play = true;
	while (play)
	{
		Login();
		Init();
		StartMenu();
		Run();
		play = retry();
	}
}