#include "apple.h"
#include <time.h>
void Apple::InitApple(char **map) {
	srand(time(NULL));
	_y_apple = 1 + rand() % 28;
	_x_apple = 1 + rand() % 28;
	_isAte = false;
	while (map[_y_apple][_x_apple] == 'b' ||
		map[_y_apple][_x_apple] == '#' || 
		map[_y_apple][_x_apple] == 'p') 
	{
		srand(time(NULL));
		_y_apple = 1 + rand() % 28;
		_x_apple = 1 + rand() % 28;
		_isAte = false;
	}
}
void Apple::DeleteApp(char** map) {
	map[_x_apple][_y_apple] = '.';
}
void Apple::UpdateApple(char **map) {
	map[_x_apple][_y_apple] = 'o';
}
