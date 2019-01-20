#pragma once
#include <Windows.h>
#include <time.h>

class Game
{
public:
	//int wszystkie[8]; // tablica przechowujaca mozliwe kule do wylosowania
	int generatedCode[4]; // wzorzec wylosowany przez komputer
	int inputCode[4]; // wzorzec wprowadzony przez gracza
	int isMatch; // sprawdza czy wzorce sie zgadzaja	
	int roundCount; // zmienna odpowiadajaca za licznik rund
	Game();
	~Game();
	void generate();
};

