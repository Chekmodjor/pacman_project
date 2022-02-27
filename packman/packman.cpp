#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include "Map.h"
#include "AI.h"
const int width = 10;
const int height = 10;
#define Start -4
#define Finish -3
#define Wall -2
#define Empty -1
int main()
{
	std::string field[10]
	{
		"**********",
		"*________*",
		"*_*****__*",
		"*_____*__*",
		"*_*****__*",
		"*_*______*",
		"*_*****__*",
		"***______*",
		"*________*",
		"**********"
	};
	Map map(10, 10, Symb(Wall, '*'), Symb(Empty, '_'));
	map.setStringMap(10, 10, field);
	int begin_x = 1;
	int begin_y = 1;
	int end_x = 1;
	int end_y = 8;
	AI testAI(Map::Map(&map),begin_x,begin_y);
	testAI.setTargetCoord(end_x, end_y);
	testAI.calculateShortestWay();
	testAI.getGameMap().showIntMap();
	testAI.showShortestWay();

	map.clearMemory();
	testAI.getGameMap().clearMemory();
	/*

	/*sf::RenderWindow window(sf::VideoMode(800, 600), "Packman");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
	}*/
}