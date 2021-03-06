#pragma once
#include <Windows.h>
#include <time.h>
#include "Board.h"

class Game : public Board
{
private:
	int codeLength = 4; // dlugosc szukanego kodu
	int *generatedCode; // wzorzec wylosowany przez komputer
	int *playerCode; // wzorzec wprowadzony przez gracza
	int first = 1; // kod pierwszej kuli
	int second = 1; // kod drugiej kuli
	int third = 1; // kod trzeciej kuli
	int fourth = 1; // kod czwartej kuli
	int fifth = 1; // kod piatej kuli
	int sixth = 1; // kod szostej kuli
	bool isWin = false; // sprawdza czy wzorce sie zgadzaja	
	int roundCount = 1; // zmienna odpowiadajaca za licznik rund
	int mover = 0; // pomocny przy nawigacji podczas ustawiania koloru kuli 
	int wholeMatchesCount = 0; // licznik ile kul jest na wlasciwym miejscu
	int colorMatchesCount = 0; // licznik ile jest trafionych kolorow
	char choice; // zmienna zapamietujaca wybor gracza
	int colorCount = 8; // liczba kolorow
	int maxRoundCount = 9; // maksymalna ilosc rund
	bool repeating = true; // powtarzanie sie kolorow
public:
	Game(); // konstruktor domyslny
	Game(char &wybor);
	~Game();
	void setMaxRoundCount(int rounds); // ustawia maksymalna liczbe rund
	void setColors(int colors); // ustawia lcizbe kolorow
	void setCodeLength(int length); // ustawia dlugosc szukanego kodu
	void setRepeating(bool rep); // wlacza/wylacza powtarzalnosc kodu
	int getMaxRoundCount(); // ustawia maksymalna liczbe rund
	int getColors(); // ustawia lcizbe kolorow
	int getCodeLength(); // ustawia dlugosc szukanego kodu
	bool getRepeating(); // wlacza/wylacza powtarzalnosc kodu
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
	Game &operator=(const Game &wzor); // operator przypisania
};
