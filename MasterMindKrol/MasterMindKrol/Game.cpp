#include "Game.h"

using namespace std;

Game::Game()
{
}

Game::Game(char &wybor)
{
	choice = wybor;
}


Game::~Game()
{
}

void Game::setMaxRoundCount(int rounds)
{
	maxRoundCount = rounds;
}

void Game::setColors(int colors)
{
	colorCount = colors;
}

void Game::setCodeLength(int length)
{
	codeLength = length;
}

void Game::setRepeating(bool rep)
{
	repeating = rep;
}

void Game::generate()
{
	srand(time(NULL));
	generatedCode = new int[codeLength];
	if(repeating == true)
	{ 
		for (int i = 0; i < codeLength; i++)
		{
			generatedCode[i] = rand() % colorCount + 1;
		}
	}
	if(repeating == false)
	{
		bool *temp = new bool[colorCount];
		for (int i = 0; i < colorCount; i++)
		{
			temp[i] = true;
		}
		for (int i = 0; i < codeLength; i++)
		{
			while (1)
			{
				int j = rand() % colorCount + 1;
				if (temp[j] == true)
				{
					generatedCode[i] = j;
					temp[j] = false;
					break;
				}
			}
		}
		delete[] temp;
	}
}

char Game::play()
{
	playerCode = new int[codeLength];
	for (int i = 0; i < codeLength; i++)
	{
		playerCode[i] = 1;
	}
	system("cls");
	drawUI();
	drawColors();
	wipeData();
	generate();
	//odkomentowac zeby miec podglad w wylosowany kod
	//gotoxy(1, 1);
	//cout << generatedCode[0] << " " << generatedCode[1] << " " << generatedCode[2] << " " << generatedCode[3];
	changeColor(7);
	gotoxy(39, 21);
	cout << indicator;
	changeColor(8);
	gotoxy(36, 19);
	cout << roundCount <<". " ;
	for (int i = 0; i < codeLength; i++)
	{
		cout << sphere << "  ";
	}
	while (roundCount != maxRoundCount +1 && isWin != true)
	{
		char navigate = 0;
		switch ((navigate = _getch())) 
		{
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
			choice = '1';
			return choice;
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
		if (first > colorCount)
			first = 1;
		changeColor(first + 7);
		cout << sphere;
		break;
	case 1:
		second++;
		if (second > colorCount)
			second = 1;
		changeColor(second + 7);
		cout << sphere;
		break;
	case 2:
		third++;
		if (third > colorCount)
			third = 1;
		changeColor(third + 7);
		cout << sphere;
		break;
	case 3:
		fourth++;
		if (fourth > colorCount)
			fourth = 1;
		changeColor(fourth + 7);
		cout << sphere;
		break;
	case 4:
		fifth++;
		if (fifth > colorCount)
			fifth = 1;
		changeColor(fifth + colorCount - 1);
		cout << sphere;
		break;
	case 5:
		sixth++;
		if (sixth > colorCount)
			sixth = 1;
		changeColor(sixth + colorCount - 1);
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
			first = colorCount;
		changeColor(first + 7);
		cout << sphere;
		break;
	case 1:
		second--;
		if (second < 1)
			second = colorCount;
		changeColor(second + 7);
		cout << sphere;
		break;
	case 2:
		third--;
		if (third < 1)
			third = colorCount;
		changeColor(third + 7);
		cout << sphere;
		break;
	case 3:
		fourth--;
		if (fourth < 1)
			fourth = colorCount;
		changeColor(fourth + 7);
		cout << sphere;
		break;
	case 4:
		fifth--;
		if (fifth < 1)
			fifth = colorCount;
		changeColor(fifth + 7);
		cout << sphere;
		break;
	case 5:
		sixth--;
		if (sixth < 1)
			sixth = colorCount;
		changeColor(sixth + 7);
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
		mover = codeLength - 1;
	gotoxy(39 + mover * 3, 21);
	cout << indicator;
}

void Game::rightChange()
{
	clearIndicator();
	changeColor(7);
	mover++;
	if (mover > codeLength - 1)
		mover = 0;
	gotoxy(39 + mover * 3, 21);
	cout << indicator;
}

void Game::enterHit()
{
	saveCode();
	compare();
	if (wholeMatchesCount == codeLength)
	{
		isWin = true;
	}
	else
	{
		int i = 0;
		changeColor(7);
		for (i; i < wholeMatchesCount; i++)
		{
			gotoxy(58 + i * 2, 20 - roundCount);
			cout << matchColorPlace;
		}
		for (int j = 0; j < colorMatchesCount; j++)
		{
			gotoxy(58 + i * 2 + j * 2, 20 - roundCount);
			cout << matchColor;
		}
		roundCount++;
		changeColor(8);
		if (roundCount > 9)
		{
			gotoxy(35, 20 - roundCount);
			cout << roundCount << ". ";
			for (int i = 0; i < codeLength; i++)
			{
				playerCode[i] = 1;
			}
			for (int i = 0; i < codeLength; i++)
			{
				cout << sphere << "  ";
			}
		}
		else
		{
			gotoxy(36, 20 - roundCount);
			cout << roundCount << ". ";
			for (int i = 0; i < codeLength; i++)
			{
				playerCode[i] = 1;
			}
			for (int i = 0; i < codeLength; i++)
			{
				cout << sphere << "  ";
			}
		}
		first = second = third = fourth = fifth = sixth = 1;
		saveCode();
		wholeMatchesCount = colorMatchesCount = 0;
	}
}

void Game::clearIndicator()
{
	gotoxy(39, 21);
	cout << "                   ";
}

void Game::saveCode()
{
	playerCode[0] = first;
	playerCode[1] = second;
	playerCode[2] = third;
	if (codeLength > 3)
	{
		playerCode[3] = fourth;
		if (codeLength > 4)
		{
			playerCode[4] = fifth;
			if (codeLength > 5)
				playerCode[5] = sixth;
		}
		
	}
}

void Game::compare()
{
	bool isInList = false;
	int grab = 0;
	bool *exclude = new bool[codeLength];
	bool *excludeColor = new bool[codeLength];
	for (int i = 0; i < codeLength; i++)
	{
		exclude[i] = false;
		excludeColor[i] = false;
	}
	for (int i = 0; i < codeLength; i++)
	{
		if (generatedCode[i] == playerCode[i])
		{
			wholeMatchesCount++;
			exclude[i] = true;
		}
	}
	for (int i = 0; i < codeLength; i++)
	{
		if (!exclude[i])
		{
			for (int j = 0; j < 4; j++)
			{
				if (!exclude[j] && i != j)
				{
					if ((playerCode[i] == generatedCode[j]) && !excludeColor[j])
					{
						isInList = true;
						grab = j;
					}
				}
			}
			if (isInList)
			{
				colorMatchesCount++;
				isInList = false;
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
	for (int i = 0; i < codeLength; i++)
	{
		changeColor(generatedCode[i] + 7);
		cout << sphere << " ";
	}
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
			choice = play();
			break;
		case KEY_ESCAPE:
			choice = '1';
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
	for (int i = 0; i < codeLength; i++)
	{
		changeColor(generatedCode[i] + 7);
		cout << sphere << " ";
	}
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
			choice = play();
			break;
		case KEY_ESCAPE:
			choice = '1';
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
	first = second = third = fourth = fifth = sixth =1;
	saveCode();
	mover = wholeMatchesCount = colorMatchesCount = 0;
}

Game & Game::operator=(const Game & wzor)
{
	codeLength = wzor.codeLength;
	generatedCode = wzor.generatedCode;
	playerCode = wzor.playerCode;
	first = wzor.first; 
	second = wzor.second; 
	third = wzor.third;
	fourth = wzor.fourth; 
	fifth = wzor.fifth;
	sixth = wzor.sixth;
	isWin = wzor.isWin;
	roundCount = wzor.roundCount;
	mover = wzor.mover;
	wholeMatchesCount = wzor.wholeMatchesCount; 
	colorMatchesCount = wzor.colorMatchesCount;
	choice = wzor.choice; 
	colorCount = wzor.colorCount;
	maxRoundCount = wzor.maxRoundCount; 
	repeating = wzor.repeating;
	return *this;
}

void Game::drawColors()
{
	gotoxy(3, 10);
	cout << "Kolory kul: ";
	gotoxy(3, 12);
	int i = 0;
	for (i; i < colorCount/2; i++)
	{
		changeColor(8 + i);
		cout << sphere << "  ";
	}
	gotoxy(3,13);
	for (i; i < colorCount; i++)
	{
		changeColor(8 + i);
		cout << sphere << "  ";
	}
	/*	changeColor(8);
	cout << sphere << "  ";
	changeColor(9);
	cout << sphere << "  ";
	changeColor(10);
	cout << sphere << "  ";
	changeColor(11);
	cout << sphere << "  ";
	gotoxy(3, 13);
	changeColor(12);
	cout << sphere << "  ";
	changeColor(13);
	cout << sphere << "  ";
	changeColor(14);
	cout << sphere << "  ";
	changeColor(15);
	cout << sphere << "  ";*/
}