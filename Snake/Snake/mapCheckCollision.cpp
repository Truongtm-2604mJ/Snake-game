#include "mapCheckCollision.h"

void MapCheckCollison(char** map, Apple* app, Snake* snake, sf::RenderWindow& window, int & option) {

				//wall, apple
	int x, y;
	snake->GetXY_Snake(x, y);

	if (x == 30) {
		x = 0;
		snake->SetPos(x, y);
	}
	else if (y == 30) {
		y = 0;
		snake->SetPos(x, y);
	}
	else if (x == -1) {
		x = 29;
		snake->SetPos(x, y);
	}
	else if (y == -1) {
		y = 29;
		snake->SetPos(x, y);
	}

	if (map[x][y] == '#' || map[x][y] == 'b') {
		snake->_isDead = true;
	}
	if (map[x][y] == 'o') {
		app->_isAte = true;
	}
			
	if (app->_isAte == true) {
		snake->SetLength(snake->GetLength() + 1);
		snake->SetScore(snake->GetScore() + 1);
		snake->UpdateBodySnake(map);
		app->DeleteApp(map);
		app->InitApple(map);
	}
				// gate
	
	if (snake->_isDead == true) {
		window.clear();
		option = 0;
	}
	else map[x][y] = 'p';
}