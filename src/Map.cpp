#include "Map.h"

Map::Map(int width, int height) : width(width), height(height)
{
	map = init();
}

// Generate empty map
Tile** Map::init() {
	Tile **map = new Tile*[width];
	for (int i = 0; i < width; i++)
		map[i] = new Tile[height];
	return map;
}

// Place NCPs


// Place loot 



void Map::generateMap(int mapType) {

}

Map::~Map(){}