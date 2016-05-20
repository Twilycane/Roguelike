#include "Main.h"

Engine *engine = new Engine();

int main() {
	engine->init();
	while (!engine->gameOver)
	{
		engine->update();
	}
	engine->~Engine();
	delete engine;
	return 0;
}