#include "Board.h"

using namespace std;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // kolorki

Board::Board()
{
}


Board::~Board()
{
}

void Board::gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c); // kontrola kursora
}

void Board::changeColor(int color)
{
	SetConsoleTextAttribute(hConsole, color);
}

void Board::drawUI()
{
	int i; //ramka
	gotoxy(0, 0);
	cout << char(201);
	for (i = 0; i < 78; i++)
		cout << char(205);
	cout << char(187);
	for (i = 2; i < 26; i++)
	{
		gotoxy(1, i);
		if (i == 23) cout << char(204);
		if (i == 25) cout << char(200);
		else cout << char(186);
	}
	for (i = 0; i < 78; i++)
		cout << char(205);
	cout << char(188);
	for (i = 2; i < 25; i++)
	{
		gotoxy(80, i);
		if (i == 23) cout << char(185);
		cout << char(186);
	}
	gotoxy(2, 23);
	for (i = 2; i < 80; i++)
		cout << char(205);
}

char Board::drawMenu()
{
	gotoxy(34, 10); //powitanie
	cout << "MasterMind";
	gotoxy(21, 12);
	cout << "1. Rozpocznij gre";
	gotoxy(21, 13);
	cout << "2. Jak grac?";
	gotoxy(21, 14);
	cout << "3. Wyjscie";
	gotoxy(21, 15);
	cout << "Twoj wybor: ";
	cin >> wybor;
	return wybor;
}

char Board::drawHowToPlay()
{
	system("cls");
	drawUI();
	gotoxy(10, 3);
	cout << "Mastermind to gra polegajaca na odgadnieciu 4 ukrytych kul";
	gotoxy(10, 4);
	cout << "Gra zostanie rozwiazana jesli w ciagu 9 tur gracz odgadnie";
	gotoxy(10, 5);
	cout << "polozenie i kolor kul. W kazdej turze gracz wybiera 4 kule";
	gotoxy(10, 6);
	cout << "i sprawdza czy trafil. Kazda kula o wlasciwym kolorze we";
	gotoxy(10, 7);
	cout << "wlasciwym miejscu zostaje oznaczona znakiem "<<matchColorPlace<<", a jesli gracz";
	gotoxy(10, 8);
	cout << "odgadl kolor kuli, a nie jej lokalizacje, oznaczane jest to ";
	gotoxy(10, 9);
	cout << "symbolem "<<matchColor<<". Gracz nie wie, ktore kule sa wlasciwe, a ktore nie";
	gotoxy(10, 11);
	cout << "Nacisnij ESC aby wrocic";
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			std::cout << "DUDE! You've pressed the escape key";
			std::cin.ignore();
			return '4';
		}
	}
}