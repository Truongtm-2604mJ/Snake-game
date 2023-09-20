#pragma once
#include "Map.h"
#include "apple.h"
#include "common.h"
#include "snake.h"
#include "mapCheckCollision.h"

class GameController {
public:
	void PlayGame(sf::RenderWindow& window, int &option);
};