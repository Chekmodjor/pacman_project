#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include "Map.h"
#include "AI.h"
#include "Player.h"
#define Wall -2
#define Empty -1
const float pixel = 32;
int main()
{
	std::string level[31] = 
	{
	  "BBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	  "B000000000000BB000000000000B",
	  "B0BBBB0BBBBB0BB0BBBBB0BBBB0B",
	  "B*BBBB0BBBBB0BB0BBBBB0BBBB*B",
	  "B0BBBB0BBBBB0BB0BBBBB0BBBB0B",
	  "B00000000000000000000000000B",
	  "B0BBBB0BB0BBBBBBBB0BB0BBBB0B",
	  "B0BBBB0BB0BBBBBBBB0BB0BBBB0B",
	  "B000000BB0000BB0000BB000000B",
	  "BBBBBB0BBBBB0BB0BBBBB0BBBBBB",
	  "     B0BBBBB0BB0BBBBB0B     ",
	  "     B0BB0000000000BB0B     ",
	  "     B0BB0BBB--BBB0BB0B     ",
	  "BBBBBB0BB0B      B0BB0BBBBBB",
	  "<     0000B      B0000     >",
	  "BBBBBB0BB0B      B0BB0BBBBBB",
	  "     B0BB0BBBBBBBB0BB0B     ",
	  "     B0BB0000000000BB0B     ",
	  "     B0BB0BBBBBBBB0BB0B     ",
	  "BBBBBB0BB0BBBBBBBB0BB0BBBBBB",
	  "B000000000000BB000000000000B",
	  "B0BBBB0BBBBB0BB0BBBBB0BBBB0B",
	  "B0BBBB0BBBBB0BB0BBBBB0BBBB0B",
	  "B*00BB0000000000000000BB00*B",
	  "BBB0BB0BB0BBBBBBBB0BB0BB0BBB",
	  "BBB0BB0BB0BBBBBBBB0BB0BB0BBB",
	  "B000000BB0000BB0000BB000000B",
	  "B0BBBBBBBBBB0BB0BBBBBBBBBB0B",
	  "B0BBBBBBBBBB0BB0BBBBBBBBBB0B",
	  "B00000000000000000000000000B",
	  "BBBBBBBBBBBBBBBBBBBBBBBBBBBB"
	};
	Map map(28, 31, Symb(Wall, 'B'), Symb(Empty, ' '));
	map.setStringMap(28, 31, level);
	map.showStringMap();

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Pacman");
	sf::Texture t;
    t.loadFromFile("attributes.png");
    sf::Texture tileSet;
    tileSet.loadFromFile("attributes.png");
	Player player(t, &map, pixel, 10, 1);
	sf::Sprite tile(tileSet);
	sf::Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 600;
		if (time > 20) time = 20;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
					player.setRotation(4);
				else if (event.key.code == sf::Keyboard::Right)
					player.setRotation(2);
				else if (event.key.code == sf::Keyboard::Up)
					player.setRotation(1);
				else if(event.key.code == sf::Keyboard::Down)
					player.setRotation(3);

			}
		}
		
		player.update(time);
		window.clear(sf::Color::Black);
		for (int i = 0; i < map.getHeight(); i++) 
		{
			for (int j = 0; j < map.getWidth(); j++)
			{
				if (level[i][j] == 'B')
					tile.setTextureRect(sf::IntRect(0, 144, 32, 32));
				else if (level[i][j] == '0')
					tile.setTextureRect(sf::IntRect(pixel, 144, 32, 32));
				else if (level[i][j] == '*')
					tile.setTextureRect(sf::IntRect(2 * pixel, 144, 32, 32));
				else if (level[i][j] == '-')
					tile.setTextureRect(sf::IntRect(3 * pixel, 144, 32, 32));
				else
					tile.setTextureRect(sf::IntRect(10 * pixel, 144, 32, 32));
				tile.setPosition(j * pixel, i * pixel);
				window.draw(tile);
			}
		}
		window.draw(player.getSprite());
		window.display();
	}
	map.clearMemory();
}