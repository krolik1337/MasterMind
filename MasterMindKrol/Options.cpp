#include "Options.h"

using namespace std;

Options::Options(char &wybor, Game &gra): gierka(wybor)
{
	choice = wybor;
	gierka = gra;
}


Options::~Options()
{
}

Game Options::changes()
{
	rounds = gierka.getMaxRoundCount();
	colors = gierka.getColors();
	repeating = gierka.getRepeating();
	toFind = gierka.getCodeLength();
	char navigate = 0;
	while (navigate != KEY_ESCAPE)
	{
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
		{
			choice = enterHit();
			if (state == 6 || state == 5)
			{
				return gierka;
			}
			break;
		}
		default:
			continue;
		}
	}
	return gierka;
}

void Options::setState(int defaultState)
{
	state = defaultState;
}

void Options::upChange()
{
	switch (state) // ustawia nastepny na podstawie poprzedniego
	{
	case 1:
		gotoxy(31, 4);
		putchar(space);
		gotoxy(34, 21);
		putchar(menuIndicator);
		break;
	case 2:
		gotoxy(27, 9);
		putchar(space);
		gotoxy(31, 4);
		putchar(menuIndicator);
		break;
	case 3:
		gotoxy(11, 14);
		putchar(space);
		gotoxy(27, 9);
		putchar(menuIndicator);
		break;
	case 4:
		gotoxy(41, 14);
		putchar(space);
		gotoxy(11, 14);
		putchar(menuIndicator);
		break;
	case 5:
		gotoxy(34, 19);
		putchar(space);
		gotoxy(41, 14);
		putchar(menuIndicator);
		break;
	case 6:
		gotoxy(34, 21);
		putchar(space);
		gotoxy(34, 19);
		putchar(menuIndicator);
		break;
	}
	state--;
	if (state < 1) // zamienia zmienna wyboru
		state = 6;
}

void Options::downChange()
{
	switch (state) // ustawia nastepny na podstawie poprzedniego
	{
	case 1:
		gotoxy(31, 4);
		putchar(space);
		gotoxy(27, 9);
		putchar(menuIndicator);
		break;
	case 2:
		gotoxy(27, 9);
		putchar(space);
		gotoxy(11, 14);
		putchar(menuIndicator);
		break;
	case 3:
		gotoxy(11, 14);
		putchar(space);
		gotoxy(41, 14);
		putchar(menuIndicator);
		break;
	case 4:
		gotoxy(41, 14);
		putchar(space);
		gotoxy(34, 19);
		putchar(menuIndicator);
		break;
	case 5:
		gotoxy(34, 19);
		putchar(space);
		gotoxy(34, 21);
		putchar(menuIndicator);
		break;
	case 6:
		gotoxy(34, 21);
		putchar(space);
		gotoxy(31, 4);
		putchar(menuIndicator);
		break;
	}
	state++;
	if (state > 6) // zamienia zmienna wyboru
		state = 1;
}

void Options::leftChange()
{
	switch (state)
	{
	case 1:
	{
		if (colors > 6)
		{
			if (colors == 7)
			{
				gotoxy(11 + (colors - 6) * 14 - 1, 7);
				putchar(eraseSelect);
				colors--;
				gotoxy(11 + (colors - 6) * 14, 7);
				putchar(select);
			}
			else 
			{
				gotoxy(11 + (colors - 6) * 14 - 1, 7);
				putchar(eraseSelect);
				colors--;
				gotoxy(11 + (colors - 6) * 14 - 1, 7);
				putchar(select);
			}
		}
		break;
	}
	case 2:
	{
		if (rounds > 5)
		{
			if (rounds > 10)
			{ 
				gotoxy(11 + (rounds - 5) * 5 - (10 - rounds), 12);
				putchar(eraseSelect);
				rounds--;
				gotoxy(11 + (rounds - 5) * 5 - (10 - rounds), 12);
				putchar(select);
			}
			else
			{ 
				gotoxy(11 + (rounds - 5) * 5, 12);
				putchar(eraseSelect);
				rounds--;
				gotoxy(11 + (rounds - 5) * 5, 12);
				putchar(select);
			}
		}
		break;
	}
	case 3:
	{
		if (toFind > 3)
		{
			gotoxy(11 + (toFind - 3) * 8, 17);
			putchar(eraseSelect);
			toFind--;
			gotoxy(11 + (toFind - 3) * 8, 17);
			putchar(select);
		}
		break;
	}
	case 4:
	{
		if (repeating == false)
		{
			gotoxy(66, 17);
			putchar(eraseSelect);
			gotoxy(42, 17);
			putchar(select);
			repeating = true;
		}
		break;
	}
	}
}

void Options::rightChange()
{
	switch (state)
	{
	case 1:
	{
		
		if (colors < 10)
		{
			if (colors == 6)
			{
				gotoxy(11 + (colors - 6) * 14, 7);
				putchar(eraseSelect);
				colors++;
				gotoxy(11 + (colors - 6) * 14 - 1, 7);
				putchar(select);
			}
			else
			{
				gotoxy(11 + (colors - 6) * 14 - 1, 7);
				putchar(eraseSelect);
				colors++;
				gotoxy(11 + (colors - 6) * 14 - 1, 7);
				putchar(select);

			}
		}
		break;
	}
	case 2:
	{
		if (rounds < 15)
		{
			if (rounds > 9)
			{
				gotoxy(11 + (rounds - 5) * 5 - (10 - rounds), 12);
				putchar(eraseSelect);
				rounds++;
				gotoxy(11 + (rounds - 5) * 5 - (10 - rounds), 12);
				putchar(select);
			}
			else
			{
				gotoxy(11 + (rounds - 5) * 5, 12);
				putchar(eraseSelect);
				rounds++;
				gotoxy(11 + (rounds - 5) * 5, 12);
				putchar(select);
			}
		}
		break;
	}
	case 3:
	{
		if (toFind < 6)
		{
			gotoxy(11 + (toFind - 3) * 8, 17);
			putchar(eraseSelect);
			toFind++;
			gotoxy(11 + (toFind - 3) * 8, 17);
			putchar(select);
		}
		break;
	}
	case 4:
	{
		if (repeating == true)
		{
			gotoxy(42, 17);
			putchar(eraseSelect);
			gotoxy(66, 17);
			putchar(select);
			repeating = false;
		}
		break;
	}
	}
}

char Options::enterHit()
{
	if (state == 6)
	{
		return '3';
	}
	if (state == 5)
	{
		save();
		return '3';
	}
}

void Options::save()
{
	gierka.setMaxRoundCount(rounds);
	gierka.setColors(colors);
	gierka.setCodeLength(toFind);
	gierka.setRepeating(repeating);
}


void Options::drawOptions()
{
	system("cls");
	drawUI();
	gotoxy(31, 4);
	cout << "> Ilosc kolorow";
	gotoxy(11, 6);
	cout << "6            7             8             9            10";
	gotoxy(11, 7);
	for (int i = 0; i < 56; i++)
	{
		cout << char(eraseSelect);
	}
	gotoxy(29, 9);
	cout << "Maksymalna liczba rund";
	gotoxy(11, 11);
	cout << "5    6    7    8    9    10    11    12    13    14   15";
	gotoxy(11, 12);
	for (int i = 0; i < 56; i++)
	{
		cout << char(eraseSelect);
	}
	gotoxy(13, 14);
	cout << "Liczba zgadywanych kul";
	gotoxy(11, 16);
	cout << "3       4       5       6";
	gotoxy(11, 17);
	for (int i = 0; i < 25; i++)
	{
		cout << char(eraseSelect);
	}
	gotoxy(43, 14);
	cout << "Powtarzanie sie kolorow";
	gotoxy(42, 16);
	cout << "on                    off";
	gotoxy(42, 17);
	for (int i = 0; i < 25; i++)
	{
		cout << char(eraseSelect);
	}
	gotoxy(36, 19);
	cout << "Zapisz";
	gotoxy(36, 21);
	cout << "Wyjdz ";
	if (colors == 6)
	{
		gotoxy(11 + (gierka.getColors() - 6) * 14, 7);
		putchar(select);
	}
	else
	{ 
		gotoxy(11 + (gierka.getColors() - 6) * 14 - 1, 7);
		putchar(select);
	}
	if (gierka.getMaxRoundCount() > 10)
		gotoxy(11 + (gierka.getMaxRoundCount() - 5) * 5 - (10 - gierka.getMaxRoundCount()), 12);
	else
		gotoxy(11 + (gierka.getMaxRoundCount() - 5) * 5, 12);
	putchar(select);
	gotoxy(11 + (gierka.getCodeLength() - 3) * 8, 17);
	putchar(select);
	if (gierka.getRepeating() == false)
		gotoxy(66, 17);
	else
		gotoxy(42, 17);
	putchar(select);

	gotoxy(32, 4);

}