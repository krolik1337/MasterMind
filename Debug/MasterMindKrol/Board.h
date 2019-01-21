#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
class Board
{
public:
	const unsigned char matchColorPlace = 178; // ustawia znak dobrego koloru i miejsca
	const unsigned char matchColor = 176; // ustawia znak dobrego koloru
	const unsigned char sphere = 219; // ustawia znak kuli
	const unsigned char indicator = 248; // ustawia znak wskaznika aktualnej kuli
	Board();
	~Board();
	char wybor; // zmienna zapamietujaca wybor gracza
	void drawUI(); // rysuje ramke
	char drawMenu(); // rysuje menu wyboru
	char drawHowToPlay(); // rysuje Jak grac
	void gotoxy(int x, int y); // ustawia kursor w podanych wspolrzednych
	void changeColor(int color); // zmienia kolor tekstu konsoli
	void drawColors(); // rysuje dostepne kolory
	void drawTitle(); // rysuje napis tytulowy
};

