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
private:
	char choice; // zmienna zapamietujaca wybor gracza
public:
	Board();
	Board(char &wybor);
	~Board();
	const unsigned char matchColorPlace = 178; // ustawia znak dobrego koloru i miejsca
	const unsigned char matchColor = 176; // ustawia znak dobrego koloru
	const unsigned char sphere = 219; // ustawia znak kuli
	const unsigned char indicator = 248; // ustawia znak wskaznika aktualnej kuli
	const unsigned char menuIndicator = 62; // ustawia znak wskaznika menu
	const unsigned char select = 206; // ustawia znak wyboru opcji
	const unsigned char eraseSelect = 205; // ustawia znak paska opcji
	const unsigned char space = 32;
	
	void drawUI(); // rysuje ramke
	void drawMenu(char ch); // rysuje menu wyboru
	char drawHowToPlay(); // rysuje Jak grac
	void gotoxy(int x, int y); // ustawia kursor w podanych wspolrzednych
	void changeColor(int color); // zmienia kolor tekstu konsoli
	void drawTitle(); // rysuje napis tytulowy
};