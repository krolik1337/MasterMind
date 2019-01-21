#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Board.h"
#include "Game.h"

using namespace std;

int main()
{
	Board board; // deklaracja planszy
	char wybor = '4';
	Game game(wybor);
	board.drawUI(); // narysowanie ramki
	wybor = board.drawMenu();
	while (wybor != '3')
	{
		switch (wybor)
		{
		case '1':
			system("cls");
			board.drawUI();
			board.drawColors();
			wybor = game.play();
			break;
		case '2':
			wybor = board.drawHowToPlay();
			break;
		case '3':
			break;
		case '4':
			system("cls");
			board.drawUI();
			wybor = board.drawMenu();
			break;
		default:
			board.gotoxy(17, 16);
			cout << "nie ma takiego polecenia, sprobuj jeszcze raz.";
			wybor = board.drawMenu();
			break;
		}
	}
	return 0;
}
