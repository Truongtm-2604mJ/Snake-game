#include "gameController.h"
char fps=15;
bool pause = false;

void GameController::PlayGame(sf::RenderWindow &window, int &option) {
												//Init Entity
	window.create(sf::VideoMode(1100, 900), "Snake");
	Map* map = new Map;
	map->InitMap();
	Apple* app = new Apple;
	app->InitApple(map->GetMap());
	Snake* mSnake = new Snake;

											// Graphics
	while (window.isOpen() && option ==1) {


								//close or pause game
		sf::Event event;
						
		if ((window.pollEvent(event)))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				option = 3;
			}
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
			{
				if (pause == true) pause = false;
				else pause = true;
			}
		}
		if (!pause) {

			window.clear();

			//Update map
			app->UpdateApple(map->GetMap());
			mSnake->UpdateSnake(map->GetMap(),fps);

			//check Collision
			MapCheckCollison(map->GetMap(), app, mSnake, window,option);
			
			//draw
			map->DrawMap(window,mSnake->GetScore());

			window.display();
			window.setFramerateLimit(fps);
		}
	}
	map->~Map();
	delete app;
	app = NULL;
	delete mSnake;
	mSnake = NULL;
}