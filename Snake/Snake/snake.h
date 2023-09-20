#pragma once
#include "common.h"


struct node {
	int x;
	int y;
};
class Snake {
public:
	Snake();
	~Snake() {};
	bool _isDead;
	void UpdateBodySnake(char** m_map);
	void UpdateSnake(char** m_map, char &fps);
	void GetDirection() {};

	void SetPos(int x, int y);
	void GetXY_Snake(int& x, int& y) {
		x = _xSnake;
		y = _ySnake;
	};
	void DeleteSnake(char** m_map);
	void SetLength(int length) {
		_length = length;
	}
	int GetLength() {
		return _length;
	}
	int GetScore() {
		return _score;
	}
	void SetScore(int score) {
		_score = score;
	}
private:
	int _xSnake;
	int _ySnake;
	node _body[100];
	int _direction;
	int _length;
	int _score;
};