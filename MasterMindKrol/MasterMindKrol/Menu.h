#pragma once
#include "Board.h"

class Menu : public Board
{
private:
	char choice; // zmienna zapamietujaca wybor gracza
public:
	Menu(char &wybor);
	~Menu();
	void upChange(); // akcja przy strzalce w gore
	void downChange(); // akcja przy strzalce w dol
	char enterHit(); // akcja po wcisnieciu ENTER
};

