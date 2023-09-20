#pragma once
#include <iostream>
#include <array>
#include "SFML/Graphics.hpp"
#include "SFML/Window/Mouse.hpp"
#include <cstdlib>
using namespace std;

const unsigned char m_mapHeight = 30;
const unsigned char m_mapWidth = 30;
const unsigned char Cell_Size = 30;

enum Direction {
	Up,
	Left,
	Right,
	Down
};
