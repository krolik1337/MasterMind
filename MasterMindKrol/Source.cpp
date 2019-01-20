#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "Board.h"
#include "Game.h"

using namespace std; // przerobiæ na tabelê?

int main()
{
	Board board; // deklaracja planszy
	Game game;
	board.drawUI(); // narysowanie ramki
	char wybor = board.drawMenu();
	while (wybor != '3')
	{
		switch (wybor)
		{
		case '1':
			cout << "Granko";
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
			cout << "nie ma takiego polecenia, sprobuj jeszcze raz.";
			wybor = board.drawMenu();
			break;
		}
	}
	system("cls"); // czzyszczenie okna konsoli
	cout << "GAME OVER"; // ekran koñcowy
	//gotoxy(33, 12);
	return 0;
}
