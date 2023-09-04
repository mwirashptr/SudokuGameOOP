#include <Game.h>

Game::Game()
{
	using namespace std;
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
	cout << "\t\t\t\t\t    ";

	p = p.login();

	cout << "\t\t\t\t\t      Tekan ENTER untuk memulai ";
	if (cin.get() != '\n')
	{
		exit(0);
	}
	srand(uint32_t(time(NULL)));

	b.setBoard("123456789456789123789123456231564897564897231897231564312645978645978312978312645");
	system("CLS");
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
			cout << b.getCell(i, j) << " ";
			if (j == 2 || j == 5)
				cout << "| ";
		}
		cout << "\n\t\t\t\t\t\t";
		if (i == 2 || i == 5)
			cout << "=====================\n\t\t\t\t\t\t";
	}
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
		while (!b.isValid(coorX))
		{
			cout << "\n\t\t\t\tMasukkan koordinat X : ";
			while (true) {
				time += 1;
				if (_kbhit())
				{
					coorX = int(_getch()) - '0';
					break;
				}
				Sleep(250);
			}
			cout << char(coorX + '0');
			if (b.isValid(coorX) == 0)
			{
				cout << " (Input is invalid)";
			}
		}
		while (!b.isValid(coorY))
		{
			cout << "\n\t\t\t\tMasukkan koordinat Y : ";
			while (true) {
				time += 1;
				if (_kbhit())
				{
					coorY = int(_getch()) - '0';
					break;
				}
				Sleep(250);
			}
			cout << char(coorY + '0');
			if (b.isValid(coorY) == 0)
			{
				cout << " (Input is invalid)";
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
		b.setCell(coorY - 1, coorX - 1, answer);
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
	if (b.checkWin())
	{
		std::cout << "\n\n\n\t\t\t\t\t\tSelamat kamu sudah menang";
		std::cout << "\n\t\t\t\t\tNama	: " << p.getName();
		std::cout << "\n\t\t\t\t\tSkor	: 1000";
		return 1;
	}
	return 0;
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
	}
	return 0;
}

void Game::Run()
{
	bool run = true;

	while (run)
	{
		render();
		input();
		if (update())
			run = false;
	}
}