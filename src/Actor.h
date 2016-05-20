#include "libtcod.hpp"

class Actor{
public:
	int x, y;
	int ch;
	TCODColor col;
	void render();

	Actor(int x, int y, int ch, TCODColor col);
	~Actor();
};