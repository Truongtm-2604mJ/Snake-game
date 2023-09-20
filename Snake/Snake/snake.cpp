#include "snake.h"


Snake::Snake() {
	                 //init snake
	_length = 3;
	for (int i = 2; i >=0; i--) {
		_body[i].y = 4;
		_body[i].x = i+5;
	}
	                // snake head
	_xSnake = 8;
	_ySnake = 4;

					//snake direction
	_direction = Direction::Right;
					//snake status
	_isDead = false;
	_score = 0;
}
void Snake::SetPos(int x, int y) {
	_xSnake = x;
	_ySnake = y;
}
void Snake::DeleteSnake(char **m_map) {
	for (int i = 0; i < _length; i++) {
		m_map[_body[i].x][_body[i].y] = '.';
	}
	m_map[_xSnake][_ySnake] = '.';
}
void Snake::UpdateBodySnake(char** m_map) {
	//update body
	for (int i = _length - 1; i > 0; i--) {
		_body[i].x = _body[i - 1].x;
		_body[i].y = _body[i - 1].y;
		m_map[_body[i].x][_body[i].y] = 'b';
	}
	_body[0].x = _xSnake;
	_body[0].y = _ySnake;
	m_map[_body[0].x][_body[0].y] = 'b';
}
void Snake::UpdateSnake(char **m_map, char& fps) {
	this->DeleteSnake(m_map);
	this->UpdateBodySnake(m_map);
								//update direction
	if (_isDead == false) {
		if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{	
			if (_direction == Left)
				_direction = Left;
			else
				_direction = Direction::Right;
		}

		else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (_direction == Down)
				_direction = Down;
			else
				_direction = Direction::Up;
		}

		else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (_direction == Right)
				_direction = Right;
			else
				_direction = Direction::Left;
		}

		else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (_direction == Up)
				_direction = Up;
			else
				_direction = Direction::Down;
		}
		else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (fps < 25)
				fps++;
		}
		else if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (fps > 10)
				fps--;
		}
						//update head
		switch (_direction)
		{
		case Right:
			_xSnake++;
			break;
		case Left:
			_xSnake--;
			break;
		case Up:
			_ySnake--;
			break;
		case Down:
			_ySnake++;
			break;
		default:
			break;
		}
	}
}
