#pragma once
#include <Windows.h>
#include <time.h>
#include "Board.h"

class Game : public Board
{
private:
	int codeLength = 4;
	int *generatedCode; // wzorzec wylosowany przez komputer
	int *playerCode; // wzorzec wprowadzony przez gracza
	int first = 1; // kod pierwszej kuli
	int second = 1; // kod drugiej kuli
	int third = 1; // kod trzeciej kuli
	int fourth = 1; // kod czwartej kuli
	int fifth = 1;
	int sixth = 1;
	bool isWin = false; // sprawdza czy wzorce sie zgadzaja	
	int roundCount = 1; // zmienna odpowiadajaca za licznik rund
	int mover = 0; // pomocny przy nawigacji podczas ustawiania koloru kuli 
	int wholeMatchesCount = 0; // licznik ile kul jest na wlasciwym miejscu
	int colorMatchesCount = 0; // licznik ile jest trafionych kolorow
	char choice; // zmienna zapamietujaca wybor gracza
	int colorCount = 8;
	int maxRoundCount = 9; // maksymalna ilosc rund
	bool repeating = true;
public:
	Game();
	Game(char &wybor);
	~Game();
	void setMaxRoundCount(int rounds);
	void setColors(int colors);
	void setCodeLength(int length);
	void setRepeating(bool rep);
	void generate(); // generuje wzorzec i zapisuje go do tabeli
	char play(); // rozpoczyna gre
	void upChange(); // akcja przy strzalce w gore
	void downChange(); // akcja przy strzalce w dol
	void leftChange(); // akcja przy strzalce w lewo
	void rightChange(); // akcja przy strzalce w prawo
	void enterHit(); // akcja po wcisnieciu ENTER
	void clearIndicator(); // wymazuje poprzedni indykator
	void saveCode(); // zapisuje do tablicy gracza aktualna kombinacje
	void compare(); // porownuje kod gracza z wylosowanym
	char ifWin(); // akcja po wygranej
	char ifLost(); // akcja po przegranej
	void wipeData(); // zeruje zmienne przed nowa gra
	void drawColors(); // rysuje dostepne kolory
	Game &operator=(const Game &wzor);
};
