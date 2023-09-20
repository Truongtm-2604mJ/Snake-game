#pragma once

#include "common.h"
#include "snake.h"
#include "apple.h"

class Map {
public:
	void InitMap();
	void DrawMap(sf::RenderWindow& window,int score);
	~Map();
	char** GetMap() {
		return _map;
	};
	string str;
private:
	char ** _map;
};