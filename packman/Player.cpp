#include "Player.h"
Player::Player(sf::Texture& image, Map* map, float pixel, int start_x, int start_y)
{
    sprite.setTexture(image);
    rect = sf::FloatRect(start_x * pixel, start_y * pixel, pixel, pixel);
    this->map = map;
    score = 0;
    this->pixel = pixel;
    x_pos = start_x;
    y_pos = start_y;
    rotation = 2;
    ox = 0.1;
    oy = 0;
    time = 0;
    currentFrame = 0;
}
void Player::update(float time)
{

    if ((int)rect.left % (int)pixel == 0)
        x_pos = rect.left / pixel;
    if ((int)rect.top % (int)pixel == 0)
        y_pos = rect.top / pixel;
    
    if (x_pos > 0 && x_pos < map->getWidth() && y_pos > 0 && y_pos < map->getHeight())
    {
        if (rotation == 1 && map->getStringMap()[y_pos - 1][x_pos] != map->getWallSymb().str_symb)
        {
            rect.top -= pixel;
        }
        if (rotation == 2 && map->getStringMap()[y_pos][x_pos + 1] != map->getWallSymb().str_symb)
        {
            rect.left += pixel;
        }
        if (rotation == 3 && map->getStringMap()[y_pos + 1][x_pos] != map->getWallSymb().str_symb)
        {
            rect.top += pixel;
        }
        if (rotation == 4 && map->getStringMap()[y_pos][x_pos - 1] != map->getWallSymb().str_symb)
        {
            rect.left -= pixel;
        }
    }



    //if (x_pos > 0 && x_pos < map->getWidth())
    //{
    //    if (map->getStringMap()[y_pos][x_pos - 1] != map->getWallSymb().str_symb && ox < 0)
    //    {
    //        rect.left += ox * time;
    //        oy = 0;
    //    }   
    //    if (map->getStringMap()[y_pos][x_pos + 1] != map->getWallSymb().str_symb && ox > 0)
    //    {
    //        rect.left += ox * time;
    //        oy = 0;
    //    }

    //    if (map->getStringMap()[y_pos][x_pos - 1] == map->getWallSymb().str_symb && ox < 0)
    //        ox = 0;
    //    if (map->getStringMap()[y_pos][x_pos + 1] == map->getWallSymb().str_symb && ox > 0)
    //        ox = 0;
    //}
    //if ((int)rect.left % (int)pixel == 0)
    //    x_pos = rect.left / pixel;
    //if ((int)rect.top % (int)pixel == 0)
    //    y_pos = rect.top / pixel;
    //if (y_pos > 0 && y_pos < map->getWidth())
    //{
    //    if (map->getStringMap()[y_pos - 1][x_pos] != map->getWallSymb().str_symb && oy < 0)
    //    {
    //        rect.top += oy * time;
    //        ox = 0;
    //    }
    //    if (map->getStringMap()[y_pos + 1][x_pos] != map->getWallSymb().str_symb && oy > 0)
    //    {
    //        rect.top += oy * time;
    //        ox = 0;
    //    }

    //    if (map->getStringMap()[y_pos - 1][x_pos] == map->getWallSymb().str_symb && oy < 0)
    //        oy = 0;
    //    if (map->getStringMap()[y_pos + 1][x_pos] == map->getWallSymb().str_symb && oy > 0)
    //        oy = 0;
    //}
    currentFrame += 0.005 * time;
    if (currentFrame > 4) currentFrame -= 4;
    if (ox > 0) sprite.setTextureRect(sf::IntRect(pixel * int(currentFrame), 40, pixel, pixel));
    if (ox < 0) sprite.setTextureRect(sf::IntRect(pixel * int(currentFrame) + pixel, 40, -pixel, pixel));
    if (oy < 0) sprite.setTextureRect(sf::IntRect(0 + (int(currentFrame) * pixel), 109, pixel, pixel));
    if (oy > 0) sprite.setTextureRect(sf::IntRect(pixel * int(currentFrame) + pixel, 70, -pixel, pixel));
    sprite.setPosition(rect.left, rect.top);
}
void Player::collision(bool dir)
{
    //for (int i = rect.top / pixel; i < (rect.top + rect.height) / pixel; i++)
    //{
    //    for (int j = rect.left / pixel; j < (rect.left + rect.width) / pixel; j++) 
    //    {
    //        if (map->getStringMap()[i][j] == map->getWallSymb().str_symb || map->getStringMap()[i][j] == '-') 
    //        {
    //            if ((ox > 0) && (dir == 0)) {
    //                rect.left = j * pixel - rect.width;
    //                ox = 0;
    //            }
    //            if ((ox < 0) && (dir == 0)) {
    //                rect.left = j * pixel + pixel;
    //                ox = 0;
    //            }
    //            if ((oy > 0) && (dir == 1)) {
    //                rect.top = i * pixel - rect.height;
    //                oy = 0;
    //            }
    //            if ((oy < 0) && (dir == 1)) {
    //                rect.top = i * pixel + pixel;
    //                oy = 0;
    //            }
    //        }//границы

    //        if (map->getStringMap()[i][j] == '0') 
    //        {
    //            map->getStringMap()[i][j] = ' ';
    //            score += 1;
    //        }//очки

    //        if (map->getStringMap()[i][j] == '*') 
    //        {
    //            map->getStringMap()[i][j] = ' ';
    //        }//супертаблетка

    //    }
    //}
        
}

float Player::getOx()
{
    return ox;
}
float Player::getOy()
{
    return oy;
}
sf::Sprite Player::getSprite()
{
    return sprite;
}
float Player::getCurrentFrame()
{
    return currentFrame;
}
void Player::setOx(float value)
{
    ox = value;
}
void Player::setOy(float value)
{
    oy = value;
}
int Player::get_x_position()
{
    return (rect.left + (rect.width / 1)) / (pixel);
}
int Player::get_y_position()
{
    return rect.top/ pixel;
}
void Player::setRotation(int rotation)
{
    this->rotation = rotation;
}