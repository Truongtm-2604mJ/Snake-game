#pragma once
#include "apple.h"
#include "Map.h"
#include "common.h"
#include "snake.h"

void MapCheckCollison(char** map, Apple* app, Snake* snake, sf::RenderWindow& window, int &option);