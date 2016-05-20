#include "libtcod.hpp"
#include <stdio.h>

enum MAPTYPES
{
	DUNGEON = 0,
	OVERWORLD = 1
};

struct Tile {
	bool isWall;
	char ch;
};

class Map {
public:
	int width, height;
	Tile **map;
	Tile** init();
	void generateMap(int mapType);

	Map(int width, int height);
	~Map();
};