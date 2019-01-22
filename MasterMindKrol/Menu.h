#pragma once
#include "Board.h"

class Menu : public Board
{
public:
	Menu(char &wybor);
	char choice; // zmienna zapamietujaca wybor gracza
	~Menu();
	void upChange(); // akcja przy strzalce w gore
	void downChange(); // akcja przy strzalce w dol
	char enterHit(); // akcja po wcisnieciu ENTER
};

