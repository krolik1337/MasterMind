#pragma once
#include "Game.h"
class Options : public Game
{
private:
	char choice;
	Game gierka;
	int state = 1;
	int colors = 8;
	int rounds = 9;
	int toFind = 4;
	bool repeating = true;
public:
	Options(char &wybor, Game &gra);
	~Options();
	Game changes();
	void setState(int defaultState);
	void upChange(); // akcja przy strzalce w gore
	void downChange(); // akcja przy strzalce w dol
	void leftChange(); // akcja przy strzalce w lewo
	void rightChange(); // akcja przy strzalce w prawo
	char enterHit(); // akcja po wcisnieciu ENTER
	void save();
	void drawOptions();
};

