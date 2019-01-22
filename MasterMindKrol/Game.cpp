#include "Game.h"

using namespace std;

Game::Game(char &wybor) : Board(wybor)
{
	choice = wybor;
}


Game::~Game()
{
}

void Game::generate()
{
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		generatedCode[i] = rand() % 8 + 1;
	}
}

char Game::play()
{
	wipeData();
	generate();
	gotoxy(1, 1);
	cout << generatedCode[0] << " " << generatedCode[1] << " " << generatedCode[2] << " " << generatedCode[3];
	changeColor(7);
	gotoxy(39, 21);
	cout << indicator;
	changeColor(8);
	gotoxy(36, 19);
	cout << roundCount << ". " << sphere << "  " << sphere << "  " << sphere << "  " << sphere;
	while (roundCount != 10 && isWin != true)
	{
		char navigate = 0;

		switch ((navigate = _getch())) {
		case KEY_UP:
			upChange();
			break;
		case KEY_DOWN:
			downChange();
			break;
		case KEY_LEFT:
			leftChange();
			break;
		case KEY_RIGHT:
			rightChange();
			break;
		case KEY_ENTER:
			enterHit();
			break;
		case KEY_ESCAPE:
			return '4';
			break;
		default:
			continue;
		}
	}
	if (isWin == true)
		return ifWin();
	else return ifLost();

}

void Game::upChange()
{
	gotoxy(39 + mover * 3, 20 - roundCount);
	switch (mover)
	{
	case 0:
		first++;
		if (first > 8)
			first = 1;
		changeColor(first + 7);
		cout << sphere;
		break;
	case 1:
		second++;
		if (second > 8)
			second = 1;
		changeColor(second + 7);
		cout << sphere;
		break;
	case 2:
		third++;
		if (third > 8)
			third = 1;
		changeColor(third + 7);
		cout << sphere;
		break;
	case 3:
		fourth++;
		if (fourth > 8)
			fourth = 1;
		changeColor(fourth + 7);
		cout << sphere;
		break;
	}
}

void Game::downChange()
{
	gotoxy(39 + mover * 3, 20 - roundCount);
	switch (mover)
	{
	case 0:
		first--;
		if (first < 1)
			first = 8;
		changeColor(first + 7);
		cout << sphere;
		break;
	case 1:
		second--;
		if (second < 1)
			second = 8;
		changeColor(second + 7);
		cout << sphere;
		break;
	case 2:
		third--;
		if (third < 1)
			third = 8;
		changeColor(third + 7);
		cout << sphere;
		break;
	case 3:
		fourth--;
		if (fourth < 1)
			fourth = 8;
		changeColor(fourth + 7);
		cout << sphere;
		break;
	}
}

void Game::leftChange()
{
	clearIndicator();
	changeColor(7);
	mover--;
	if (mover < 0)
		mover = 3;
	gotoxy(39 + mover * 3, 21);
	cout << indicator;
}

void Game::rightChange()
{
	clearIndicator();
	changeColor(7);
	mover++;
	if (mover > 3)
		mover = 0;
	gotoxy(39 + mover * 3, 21);
	cout << indicator;
}

void Game::enterHit()
{
	saveCode();
	compare();
	if (wholeMatchesCount == 4)
	{
		isWin = true;
	}
	else
	{
		int i = 0;
		changeColor(7);
		for (i; i < wholeMatchesCount; i++)
		{
			gotoxy(51 + i * 2, 20 - roundCount);
			cout << matchColorPlace;
		}
		for (int j = 0; j < colorMatchesCount; j++)
		{
			gotoxy(51 + i * 2 + j * 2, 20 - roundCount);
			cout << matchColor;
		}
		roundCount++;
		changeColor(8);
		gotoxy(36, 20 - roundCount);
		cout << roundCount << ". " << sphere << "  " << sphere << "  " << sphere << "  " << sphere;
		first = second = third = fourth = 1;
		saveCode();
		wholeMatchesCount = colorMatchesCount = 0;
	}

}

void Game::clearIndicator()
{
	gotoxy(39, 21);
	cout << "           ";
}

void Game::saveCode()
{
	playerCode[0] = first;
	playerCode[1] = second;
	playerCode[2] = third;
	playerCode[3] = fourth;
}

void Game::compare()
{
	bool inList = false;
	int grab = 0;
	bool exclude[4]{ false,false,false,false };
	bool excludeColor[4]{ false,false,false,false };
	for (int i = 0; i < 4; i++)
	{
		if (generatedCode[i] == playerCode[i])
		{
			wholeMatchesCount++;
			exclude[i] = true;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!exclude[i])
		{
			for (int j = 0; j < 4; j++)
			{
				if (!exclude[j] && i != j)
				{
					if ((playerCode[i] == generatedCode[j]) && !excludeColor[j])
					{
						inList = true;
						grab = j;
					}
				}
			}
			if (inList)
			{
				colorMatchesCount++;
				inList = false;
				excludeColor[grab] = true;
			}
		}
	}
}

char Game::ifWin()
{
	changeColor(7);
	system("cls");
	drawUI();
	gotoxy(37, 11);
	cout << "Brawo!";
	gotoxy(30, 13);
	cout << "Wygrales w ";
	if (roundCount == 1)
		cout << roundCount << " ruchu!";
	else cout << roundCount << " ruchach!";
	gotoxy(25, 15);
	cout << "Szukana kombinacja to: ";
	changeColor(generatedCode[0] + 7);
	cout << sphere << " ";
	changeColor(generatedCode[1] + 7);
	cout << sphere << " ";
	changeColor(generatedCode[2] + 7);
	cout << sphere << " ";
	changeColor(generatedCode[3] + 7);
	cout << sphere << " ";
	changeColor(7);
	gotoxy(24, 17);
	cout << "Nacisnij ESC aby powrocic do menu";
	gotoxy(25, 18);
	cout << "lub ENTER by zagrac jeszcze raz";
	char navigate = 0;
	while (navigate != KEY_ENTER && navigate != KEY_ESCAPE)
	{
		switch ((navigate = _getch()))
		{
		case KEY_ENTER:
			choice = '1';
			break;
		case KEY_ESCAPE:
			choice = '2';
			break;
		default:
			continue;
		}
	}
	return choice;
}

char Game::ifLost()
{
	changeColor(7);
	system("cls");
	drawUI();
	gotoxy(36, 11);
	cout << "Ojej! :(";
	gotoxy(24, 13);
	cout << "Tym razem nie udalo Ci sie wygrac";
	gotoxy(25, 15);
	cout << "Szukana kombinacja to: ";
	changeColor(generatedCode[0] + 7);
	cout << sphere << " ";
	changeColor(generatedCode[1] + 7);
	cout << sphere << " ";
	changeColor(generatedCode[2] + 7);
	cout << sphere << " ";
	changeColor(generatedCode[3] + 7);
	cout << sphere << " ";
	changeColor(7);
	gotoxy(24, 17);
	cout << "Nacisnij ESC aby powrocic do menu";
	gotoxy(25, 18);
	cout << "lub ENTER by zagrac jeszcze raz";
	char navigate = 0;
	while (navigate != KEY_ENTER && navigate != KEY_ESCAPE)
	{
		switch ((navigate = _getch()))
		{
		case KEY_ENTER:
			choice = '1';
			break;
		case KEY_ESCAPE:
			choice = '2';
			break;
		default:
			continue;
		}
	}
	return choice;
}

void Game::wipeData()
{
	isWin = false;
	roundCount = 1;
	first = second = third = fourth = 1;
	saveCode();
	mover = wholeMatchesCount = colorMatchesCount = 0;
}