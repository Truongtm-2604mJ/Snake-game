#include "gmenu.h"
int Scale[4][4] = { 0,0,0,0,
					0,1,0,0,
					0,0,1,0,
					0,0,0,1 };
int Menu::ShowManual(int &option,sf::RenderWindow& window) {

							//Display
	window.create(sf::VideoMode(900, 900), "Snake");
	position = 0;
	while (window.isOpen()) {
		window.clear();
		//event close X
		sf::Event event;

		if ((window.pollEvent(event)))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				option = 3;
				break;
			case sf::Event::MouseButtonReleased:
				switch (event.key.code)
				{
				case sf::Mouse::Left:

					cout << endl << "mouse left is released" << endl;
					cout << xMouse << "	" << yMouse << endl;

					if (yMouse > 100 &&
						yMouse < 270 &&
						xMouse < 670 &&
						xMouse > 180) {
						return option = 0;
					}
					break;
				default:
					break;
				}
				break;
			case sf::Event::MouseMoved:
				xMouse = event.mouseMove.x;
				yMouse = event.mouseMove.y;
				//cout << event.mouseMove.x << "	" << event.mouseMove.y << endl;
				if (yMouse > 100 &&
					yMouse < 270 &&
					xMouse < 670 &&
					xMouse > 180) {
					position = 1;
				}
				else position = 0;
			default:
				break;
			}
		}
		text.setString("SNAKE");
		text.setFillColor(sf::Color(50, 200, 150));
		text.setCharacterSize(150 +position *20 );
		text.setPosition(180-10*position, 100 - 10 * position);
		text.setStyle(sf::Text::Bold);
		window.draw(text);

		text.setString("Press ' UP ' to Up");
		text.setCharacterSize(30);
		text.setPosition(150, 380);
		window.draw(text);

		text.setString("Press ' RIGHT ' to Right");
		text.setCharacterSize(30);
		text.setPosition(150, 420);
		window.draw(text);

		text.setString("Press ' LEFT ' to Left");
		text.setCharacterSize(30);
		text.setPosition(150, 460);
		window.draw(text);

		text.setString("Press ' DOWN ' to Down");
		text.setCharacterSize(30);
		text.setPosition(150, 500);
		window.draw(text);

		text.setString("Press ' W ' to go Fast");
		text.setCharacterSize(30);
		text.setPosition(150, 540);
		window.draw(text);

		text.setString("Press ' S ' to go Slow");
		text.setCharacterSize(30);
		text.setPosition(150, 580);
		window.draw(text);

		window.display();
	}
}
void Menu::ShowMenu(sf::RenderWindow& window) {

	window.clear();							//Display
	//cout << position<<endl;

	text.setString("SNAKE");
	text.setFillColor(sf::Color(50, 200, 150));
	text.setCharacterSize(150);
	text.setPosition(180, 100);
	text.setStyle(sf::Text::Bold);
	window.draw(text);

	text.setString("Play");
	text.setCharacterSize(60+20*Scale[position][1]);
	text.setPosition(350-10* Scale[position][1], 380-10* Scale[position][1]);
	text.setStyle(sf::Text::Bold);
	window.draw(text);

	text.setString("Manual");
	text.setCharacterSize(60+20 * Scale[position][2]);
	text.setPosition(350 - 10 * Scale[position][2], 470 - 10 * Scale[position][2]);
	text.setStyle(sf::Text::Bold);
	window.draw(text);

	text.setString("Exit");
	text.setCharacterSize(60+20 * Scale[position][3]);
	text.setPosition(350 - 10 * Scale[position][3], 560 - 10 * Scale[position][3]);
	text.setStyle(sf::Text::Bold);
	window.draw(text);
}

int Menu::Option(int &option, sf::RenderWindow& window) {

	window.create(sf::VideoMode(900, 900), "Snake");

	while (window.isOpen()) {
		ShowMenu(window);
		//event close X
		sf::Event event;

		if ((window.pollEvent(event)))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				option = 3;
				break;
			case sf::Event::MouseButtonReleased:
				switch (event.key.code)
				{
				case sf::Mouse::Left:

					cout << endl << "mouse left is released" << endl;
					cout << xMouse << "	" << yMouse << endl;

					if (yMouse > 380 &&
						yMouse < 440 &&
						xMouse < 540 &&
						xMouse > 340) {
						return option = 1;
					}
					else if (yMouse > 470 &&
						yMouse < 540 &&
						xMouse < 560 &&
						xMouse > 340) {
						return option = 2;
					}
					else if (yMouse > 570 &&
						yMouse < 620 &&
						xMouse < 500 &&
						xMouse > 340) {
						return option = 3;
					}
					break;
				default:
					break;
				}
				break;
			case sf::Event::MouseMoved:
				xMouse = event.mouseMove.x;
				yMouse = event.mouseMove.y;
				//cout << event.mouseMove.x << "	" << event.mouseMove.y << endl;
				if (yMouse > 380 &&
					yMouse < 440 &&
					xMouse < 540 &&
					xMouse > 340) {
					position = 1;
				}
				else if (yMouse > 470 &&
					yMouse < 540 &&
					xMouse < 560 &&
					xMouse > 340) {
					position = 2;
				}
				else if (yMouse > 570 &&
					yMouse < 620 &&
					xMouse < 500 &&
					xMouse > 340) {
					position = 3;
				}
				else position = 0;
			default:
				break;
			}
		}
		window.display();
	}
}