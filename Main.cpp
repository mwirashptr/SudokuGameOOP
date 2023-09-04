#include <Game.h>

int main()
{
	bool play = true;
	while (play)
	{
		Game Game;
		Game.Run();
		if (!Game.retry())
			play = false;
		system("CLS");
	}

	return 0;
}