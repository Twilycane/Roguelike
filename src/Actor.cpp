#include "Actor.h"

Actor::Actor(int x, int y, int ch, TCODColor col) :
	x(x), y(y), ch(ch), col(col) {
}

void Actor::render()
{
	TCODConsole::root->putChar(x, y, ch);
	TCODConsole::root->setCharForeground(x, y, col);
}

Actor::~Actor(){}