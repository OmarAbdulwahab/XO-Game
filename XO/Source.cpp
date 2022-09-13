#include <iostream>
using namespace std;


void DrawSet(char items[3][3])
{
	bool isStraightLine = true;
	int charI = 0, charJ = 0;
	for (int i = 0; i < 7; i++)
	{
		if (isStraightLine)
		{
			for (int j = 0; j < 25; j++)
			{
				cout << "-";
			}
			cout << endl;
		}
		else
		{
			charJ = 0;
			for (int j = 0; j < 4; j++)
			{
				if(items[charI][charJ] ==' ' || j == 3)
					cout << "|\t";
				else
				{
					cout << "|" << items[charI][charJ] << "\t";
				}
				charJ++;
			}
			cout << endl;
			charI++;
		}
		
		isStraightLine = !isStraightLine;
	}
}

char IsGameOver(char gameSet[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (gameSet[i][0] == gameSet[i][1] && gameSet[i][1] == gameSet[i][2])
		{
			return gameSet[i][0];
		}
	}

	for (int j = 0; j < 3; j++)
	{
		if (gameSet[0][j] == gameSet[1][j] && gameSet[1][j] == gameSet[2][j])
		{
			return gameSet[0][j];
		}
	}

	if ((gameSet[0][0] == gameSet[1][1] && gameSet[1][1] == gameSet[2][2]) ||
		(gameSet[0][2] == gameSet[1][1] && gameSet[1][1] == gameSet[2][0]))
	{
		return gameSet[1][1];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gameSet[i][j] == ' ')
				return ' ';
		}
	}
	return '-';
}

void PlayGame()
{
	char gameSet[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			gameSet[i][j] = ' ';
		}
	}

	cout << "Please use the reference below to know how the cells are identified." << endl;
	char referenceSet[3][3] = { { '1', '2', '3' }, { '4','5','6' }, { '7','8', '9' } };
	DrawSet(referenceSet);

	bool isX = true;
	while (true)
	{
		
		cout << "Please choose cell: ";
		int id;
		cin >> id;
		id--;
		int i = id / 3;
		int j = id % 3;
		if (gameSet[i][j] != ' ')
		{
			do
			{
				cout << "Not empty cell! Please choose another cell!" << endl;
				cin >> id;
				i = id / 3;
				j = id % 3;
				if (gameSet[i][j] == ' ')
					break;
			} while (true);

		}

		if (isX)
		{
			gameSet[i][j] = 'X';
		}
		else
		{
			gameSet[i][j] = 'O';
		}

		isX = !isX;
		DrawSet(gameSet);
		char result = IsGameOver(gameSet);
		if (result == '-')
		{
			cout << "Game Over! No one won!" << endl;
			break;
		}
		else if (result == 'X')
		{
			cout << "Game Over! X Won!" << endl;
			break;
		}
		else if (result == 'O')
		{
			cout << "Game Over! O Won!" << endl;
			break;
		}
	}
}

void main()
{
	PlayGame();
}