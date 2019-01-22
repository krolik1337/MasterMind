#include "Menu.h"

using namespace std;

Menu::Menu(char &wybor) : Board(wybor)
{
	choice = wybor;
}


Menu::~Menu()
{
}

void Menu::upChange()
{
	putchar(8);
	putchar(32);
	switch (choice)
	{
	case '1':
		gotoxy(35, 17);
		putchar(indicator);
		break;
	case '2':
		gotoxy(32, 15);
		putchar(indicator);
		break;
	case '3':
		gotoxy(34, 16);
		putchar(indicator);
		break;
	}
	choice--;
	if (choice < '1')
		choice = '3';
}

void Menu::downChange()
{
	putchar(8);
	putchar(32);
	switch (choice)
	{
	case '1':
		gotoxy(34, 16);
		putchar(indicator);
		break;
	case '2':
		gotoxy(35, 17);
		putchar(indicator);
		break;
	case '3':
		gotoxy(32, 15);
		putchar(indicator);
		break;
	}
	choice++;
	if (choice > '3')
		choice = '1';
}

char Menu::enterHit()
{
	return choice;
}
