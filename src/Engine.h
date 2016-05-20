#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "libtcod.hpp"
#ifndef GUARD
#define GUARD

#include "Player.h"
#endif // !GUARD



class Engine {
public:
	void init();
	void generateFiles();
	void update();
	void showMenu();
	bool gameOver;
	int conWidth, conHeight;

	Engine();
	~Engine();
protected:
	Player *player;
	TCODConsole *root;
};