#include <queue>
#include <string>
#include <fstream>

#include <Game.h>

std::array<Player, 100> pQueue;
std::array<Board, 100> bQueue;

int main()
{
	Player* player = new Player;
	Board board;
	board.setBoard("123456789456789123789123456231564897564897231897231564312645978645978312978312645");

	std::ifstream data("Player.txt");
	std::string name;
	int flag = 0;
	while (!data.eof())
	{
		char ch;
		ch = data.get();
		if (ch == '\n')
		{
			Player temp;
			temp.setName(name);
			pQueue[flag] = temp;
			name = "";
			flag++;
		}
		else
			name.push_back(ch);
	}
	data.close();

	bool run = true;
	while (run)
	{
		std::ofstream login("Player.txt", std::ios::out | std::ios::app);
		std::string nameInput = "";
		std::cout << "\n\t\t\t\t\tMasukkan Nama Pemain : ";
		getline(std::cin, nameInput);

		bool isThere = true;
		int flag = 0;
		while (true)
		{
			if (pQueue[flag].getName() == nameInput)
			{
				player = &pQueue[flag];
				isThere = false;
				break;
			}
			else if (pQueue[flag].getName() == "")
			{
				break;
			}
			flag++;
		}
		if (isThere == true)
		{
			login << nameInput << std::endl;
			Player temp;
			temp.setName(nameInput);
			pQueue[flag] = temp;
			player = &pQueue[flag];
		}

		login.close();
		srand(uint32_t(time(NULL)));

		Game Game(*player, board);

		bool play = true;
		while (play)
		{
			Game.Run();
			if (!Game.retry())
			{
				play = false;
				run = false;
			}

			char ch = ' ';
			std::cout << "\n\t\t\t\t\tDiakun lain.... ? [y/n]";
			ch = _getch();
			if (ch == 'y')
			{
				play = false;
			}
			system("CLS");
		}
	}

	return 0;
}