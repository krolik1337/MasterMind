#include "Board.h"

using namespace std;

HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // kolorki

Board::Board(char & wybor)
{
	choice = wybor;
}


Board::~Board()
{
}

void Board::gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(hConsole, c); // kontrola kursora
}

void Board::changeColor(int color)
{
	SetConsoleTextAttribute(hConsole, color);
}

void Board::drawColors()
{
	gotoxy(3, 10);
	cout << "Kolory kul: ";
	gotoxy(3, 12);
	changeColor(8);
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
	cout << sphere << "  ";
}

void Board::drawTitle()
{
	changeColor(10);
	unsigned char t = 178;
	gotoxy(18, 5);
	cout << t << "   " << t << "           " << t << "          " << t << "   " << t << "          " << t;
	gotoxy(18, 6);
	cout << t << t << " " << t << t << "  " << t << t << "  " << t << t << t << " " << t << t << t << " " << t << t << t << " " << t << " " << t << " " << t << t << " " << t << t << " " << t << " " << t << " " << t << t << "   " << t;
	gotoxy(18, 7);
	cout << t << " " << t << " " << t << " " << t << " " << t << "  " << t << "    " << t << "  " << t << " " << t << " " << t << t << "  " << t << " " << t << " " << t << "   " << t << t << " " << t << "   " << t;
	gotoxy(18, 8);
	cout << t << "   " << t << " " << t << " " << t << "  " << t << t << t << "  " << t << "  " << t << t << t << " " << t << "   " << t << "   " << t << " " << t << " " << t << "  " << t << " " << t << t << t;
	gotoxy(18, 9);
	cout << t << "   " << t << " " << t << " " << t << "    " << t << "  " << t << "  " << t << "   " << t << "   " << t << "   " << t << " " << t << " " << t << "  " << t << " " << t << " " << t;
	gotoxy(18, 10);
	cout << t << "   " << t << "  " << t << t << t << " " << t << t << t << "  " << t << "  " << t << t << t << " " << t << "   " << t << "   " << t << " " << t << " " << t << "  " << t << " " << t << t << t;
	changeColor(7);
}

void Board::drawUI()
{
	changeColor(7);
	int i;
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
	gotoxy(62, 24);
	cout << "Autor: Kamil Krol";
}

void Board::drawMenu(char ch)
{
	changeColor(7);
	drawTitle();
	gotoxy(35, 15);
	cout << "Rozpocznij gre";
	gotoxy(37, 16);
	cout << "Jak grac?";
	gotoxy(38, 17);
	cout << "Wyjscie"; 
	switch (ch)
	{
	case '1':
		gotoxy(32, 15);
		putchar(menuIndicator);
		break;
	case '2':
		gotoxy(34, 16);
		putchar(menuIndicator);
		break;
	case '3':
		gotoxy(35, 17);
		putchar(menuIndicator);
		break;
	}
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
	cout << "wlasciwym miejscu zostaje oznaczona znakiem " << matchColorPlace << ", a jesli gracz";
	gotoxy(10, 8);
	cout << "odgadl kolor kuli, a nie jej lokalizacje, oznaczane jest to ";
	gotoxy(10, 9);
	cout << "symbolem " << matchColor << ". Gracz nie wie, ktore kule sa wlasciwe, a ktore nie.";
	gotoxy(10, 10);
	cout << "Strzalki lewo/prawo zmieniaja aktywna kule, strzalki gora/dol";
	gotoxy(10, 11);
	cout << "zmieniaja kolor aktywnej kuli.";
	gotoxy(10, 13);
	cout << "Nacisnij ESC aby wrocic";
	char navigate = 0;
	while (navigate != KEY_ESCAPE)
	{
		switch ((navigate = _getch())) 
		{
		case KEY_ESCAPE:
			choice = '2';
			return choice;
		}
	}
	return choice;
}