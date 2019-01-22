#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Board.h"
#include "Game.h"
#include "Menu.h"

using namespace std;

int main()
{
	char wybor = '1';
	Board board(wybor); // deklaracja planszy
	Game game(wybor);
	Menu menu(wybor);
	while (wybor != '3')
	{
		system("cls");
		board.drawUI(); // narysowanie ramki
		board.drawMenu();
		char navigate = 0;
		while (navigate != KEY_ENTER)
		{
			switch ((navigate = _getch())) {
			case KEY_UP:
				menu.upChange();
				break;
			case KEY_DOWN:
				menu.downChange();
				break;
			case KEY_ENTER:
				wybor = menu.enterHit(); 
				break;
			default:
				continue;
			}
		}
		switch (wybor)
		{
		case '1':
			system("cls");
			board.drawUI();
			board.drawColors();
			wybor = game.play();
			break;
		case '2':
			board.drawHowToPlay();
			break;
		case '3':
			break;
		default:
			continue;
		}
	}
	return 0;
}