#include "Options.h"


Options::Options(char &wybor): Game(wybor)
{
	choice = wybor;
}


Options::~Options()
{
}

char Options::changes()
{
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
				return choice;
			}
			break;
		}
		default:
			continue;
		}
	}
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
		switch (colors)
		{
		case 7:
		{
			gotoxy(24, 7);
			putchar(eraseSelect);
			gotoxy(11, 7);
			putchar(select);
			colors--;
			break;
		}
		case 8:
		{
			gotoxy(37, 7);
			putchar(eraseSelect);
			gotoxy(24, 7);
			putchar(select);
			colors--;
			break;
		}
		case 9:
		{
			gotoxy(51, 7);
			putchar(eraseSelect);
			gotoxy(37, 7);
			putchar(select);
			colors--;
			break;
		}
		case 10:
		{
			gotoxy(66, 7);
			putchar(eraseSelect);
			gotoxy(51, 7);
			putchar(select);
			colors--;
			break;
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
		switch (colors)
		{
		case 6:
		{
			gotoxy(11, 7);
			putchar(eraseSelect);
			gotoxy(24, 7);
			putchar(select);
			colors++;
			break;
		}
		case 7:
		{
			gotoxy(24, 7);
			putchar(eraseSelect);
			gotoxy(37, 7);
			putchar(select);
			colors++;
			break;
		}
		case 8:
		{
			gotoxy(37, 7);
			putchar(eraseSelect);
			gotoxy(51, 7);
			putchar(select);
			colors++;
			break;
		}
		case 9:
		{
			gotoxy(51, 7);
			putchar(eraseSelect);
			gotoxy(66, 7);
			putchar(select);
			colors++;
			break;
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
	setMaxRoundCount(rounds);
	setColors(colors);
	setCodeLength(toFind);
	setRepeating(repeating);
}
