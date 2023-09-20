#pragma once
#include "common.h"

class Apple {
public:
	void InitApple(char** map);
	//void ResetApple();
	void UpdateApple(char **map);
	void DeleteApp(char **map);
	void GetXY_Apple(int& x, int& y) {
		x = _x_apple;
		y = _y_apple;
	};
	bool _isAte;
private:
	int _x_apple;
	int _y_apple;
	
};