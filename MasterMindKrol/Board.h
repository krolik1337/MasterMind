#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER '\r'
#define KEY_ESCAPE 27

class Board
{
public:
	const unsigned char matchColorPlace = 178; // ustawia znak dobrego koloru i miejsca
	const unsigned char matchColor = 176; // ustawia znak dobrego koloru
	const unsigned char sphere = 219; // ustawia znak kuli
	const unsigned char indicator = 248; // ustawia znak wskaznika aktualnej kuli
	Board(char &wybor);
	~Board();
	char choice; // zmienna zapamietujaca wybor gracza
	void drawUI(); // rysuje ramke
	void drawMenu(); // rysuje menu wyboru
	char drawHowToPlay(); // rysuje Jak grac
	void gotoxy(int x, int y); // ustawia kursor w podanych wspolrzednych
	void changeColor(int color); // zmienia kolor tekstu konsoli
	void drawColors(); // rysuje dostepne kolory
	void drawTitle(); // rysuje napis tytulowy
};