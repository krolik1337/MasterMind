#pragma once
#include "Game.h"
class Options : public Game
{
private:
	char choice; // zmienna wyboru, zwracana do menu
	Game gierka; // zmienna gry 
	int state = 1; // stan menu
	int colors = 8; // liczba kolorow
	int rounds = 9; // liczba rund
	int toFind = 4; // dlugosc kodu 
	bool repeating = true; // powtarzalnosc kodu
public:
	Options(char &wybor, Game &gra);
	~Options();
	Game changes(); // glowna funckja w ktorej zmieniamy dane 
	void setState(int defaultState); // ustawia stan menu
	void upChange(); // akcja przy strzalce w gore
	void downChange(); // akcja przy strzalce w dol
	void leftChange(); // akcja przy strzalce w lewo
	void rightChange(); // akcja przy strzalce w prawo
	char enterHit(); // akcja po wcisnieciu ENTER
	void save(); // zapisuje wartosci w obiekcie gry
	void drawOptions(); // rysuje menu opcji
};

