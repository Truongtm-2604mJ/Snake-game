#include "gameController.h"
#include "gmenu.h"

void main() {
	sf::RenderWindow window(sf::VideoMode(900, 900), "Snake");
	GameController* gameControl = new GameController;
	Menu* menu = new Menu;

	int option = 0;
	while (option != 3) {
		if (option == 0) {
			menu->Option(option, window);
		}
		else if (option == 1) gameControl->PlayGame(window, option);
		else if (option == 2) menu->ShowManual(option,window);
	}
	delete gameControl;
	delete menu;
	cout << endl<<"deleted";
}