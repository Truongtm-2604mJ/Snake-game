#include "Map.h"
#pragma warning(disable : 4996)

void Map::InitMap() {
	freopen("map.txt", "r", stdin);

	_map = new char*[30];
	for (int i = 0; i < 30; i++)
		_map[i] = new char[30];
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++) {
			cin >> _map[j][i];
		}
	}
}
Map:: ~Map(){
	for (int i = 0; i < 30; i++) {
		delete _map[i];
		_map[i] = NULL;
	}
	delete _map;
	_map = NULL;

	cout << "map is deleted";
}

void Map::DrawMap(sf::RenderWindow &window, int score) {
	
	sf::RectangleShape rectangle;
	sf::CircleShape _shApple;
											//draw score
	rectangle.setPosition(915, 15);
	rectangle.setSize(sf::Vector2f(170, 870));
	rectangle.setFillColor(sf::Color(0, 0, 0));
	rectangle.setOutlineThickness(15);
	rectangle.setOutlineColor(sf::Color(200, 200, 200));
	window.draw(rectangle);
	rectangle.setOutlineThickness(0);
											//TEXT
	sf::Font font;
	font.loadFromFile("font/waltographUI.ttf");
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color(50, 200, 150));
	text.setCharacterSize(85);
	text.setStyle(sf::Text::Bold);

	text.setString("S");
	text.setPosition(920, 100);
	window.draw(text);
	text.setString("N");
	text.setPosition(940, 150);
	window.draw(text);
	text.setString("A");
	text.setPosition(960, 200);
	window.draw(text);
	text.setString("K");
	text.setPosition(980, 250);
	window.draw(text);
	text.setString("E");
	text.setPosition(1000, 300);
	window.draw(text);
										//Score
	
	text.setString("Score:");
	text.setCharacterSize(40);
	text.setPosition(920, 500);
	window.draw(text);

	str = to_string(score);
	text.setString(str);
	text.setCharacterSize(40);
	text.setPosition(940, 580);
	window.draw(text);
									//draw map
	for (int i = 0; i < m_mapHeight; i++)
	{
		for (int j = 0; j < m_mapWidth; j++) {
			if (_map[i][j] == '#') {        //Draw wall
				
				rectangle.setPosition(float (i*Cell_Size), float (j * Cell_Size));
				rectangle.setSize(sf::Vector2f(Cell_Size, Cell_Size));
				rectangle.setFillColor(sf::Color(50, 200, 150));
				window.draw(rectangle);
			}
			else if (_map[i][j] == 'p') {	 //Draw snake's head
				
				//_shApple.setFillColor(sf::Color(50, 100, 50));
				_shApple.setFillColor(sf::Color(100, 200, 200));
				_shApple.setRadius(15);
				_shApple.setPosition(sf::Vector2f(i * Cell_Size, j * Cell_Size));
				window.draw(_shApple);
			}
			else if (_map[i][j] == 'b') {   //Draw snake's body
				
				//_shApple.setFillColor(sf::Color(50, 100, 150));
				_shApple.setFillColor(sf::Color(250, 250, 250));
				_shApple.setRadius(15);
				_shApple.setPosition(sf::Vector2f(i * Cell_Size, j * Cell_Size));
				window.draw(_shApple);
			}
			else if (_map[i][j] == 'o') {	//Draw snake's apple

				_shApple.setFillColor(sf::Color(250, 100, 100));
				_shApple.setRadius(15);
				_shApple.setPosition(sf::Vector2f(i * Cell_Size, j * Cell_Size));
				window.draw(_shApple);
			}
		}
	}
}
