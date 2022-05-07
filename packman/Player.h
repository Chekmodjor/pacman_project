#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Export.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <windows.h>
#include <sstream>
#include "Map.h"
class Player 
{
private:

    float ox, oy;
    int rotation;
    sf::Sprite sprite;
    sf::FloatRect rect;
    float currentFrame;
    int score;
    float pixel;
    Map* map;
    int x_pos;
    int y_pos;
    int time;
public:

    Player(sf::Texture& image, Map* map, float pixel, int start_x, int start_y);
    void update(float time);
    void collision(bool dir);

    float getOx();
    float getOy();
    sf::Sprite getSprite();
    float getCurrentFrame();
    void setOx(float value);
    void setOy(float value);
    int get_x_position();
    int get_y_position();
    void setRotation(int rotation);
};
