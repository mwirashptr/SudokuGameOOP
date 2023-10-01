#include <Board.h>

void Board::setCell(int x, int y, char input)
{
	boardArray[x][y] = input;
}

char Board::getCell(int x, int y)
{
	return boardArray[x][y];
}

void Board::setBoard(std::string input)
{
	if (std::size(input) == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				setCell(i, j, input.front());
				input.erase(0, 1);
			}
		}
	}
}

bool Board::isValid(int input)
{
	if (input > 0 && input < 10)
	{
		return 1;
	}
	return 0;
}

bool Board::isFull()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (getCell(i, j) == ' ')
				return 0;
		}
	}

	return 1;
}

std::array<std::array<char, N>, N> Board::getBoard()
{
	return boardArray;
}

bool Board::checkHorizontal()
{
	for (int i = 0; i < 9; i++)
	{
		int temp = 0;
		for (int j = 0; j < 9; j++)
		{
			temp = temp + (getCell(i, j) - '0');
		}

		if (temp != 45)
		{
			return 0;
			break;
		}
	}

	return 1;
}

bool Board::checkVertical()
{
	for (int i = 0; i < 9; i++)
	{
		int temp = 0;
		for (int j = 0; j < 9; j++)
		{
			temp = temp + (getCell(j, i) - '0');
		}

		if (temp != 45)
		{
			return 0;
			break;
		}
	}

	return 1;
}

bool Board::checkRegion()
{
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			int temp = 0;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					temp = temp + (getCell(i + (3 * a), j + (3 * b)) - '0');
				}
			}
			if (temp != 45)
			{
				return 0;
			}
		}
	}

	return 1;
}

bool Board::checkWin()
{
	if (isFull())
		if (checkHorizontal())
			if (checkVertical())
				if (checkRegion())
					return 1;
	return 0;
}