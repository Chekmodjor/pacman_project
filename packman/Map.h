#pragma once
#include <string>
#include <iostream>
#include <iomanip>
struct Symb
{
	int int_symb;
	char str_symb;
	Symb(int int_symb, char str_symb)
	{
		this->int_symb = int_symb;
		this->str_symb = str_symb;
	}
	Symb()
	{
		int_symb = 0;
		str_symb = ' ';
	}
};
class Map
{
private:
	int width;
	int height;
	std::string* string_map;
	int** int_map;
	Symb wall;
	Symb empty;
public:
	Map();
	Map(int width, int height, Symb wall, Symb empty);
	Map(Map* map);
	~Map();
	void update_int_map();
	void update_string_map();
	void clearMemory();
	void setStringMap(int width, int height, std::string* string_map);
	void setIntMap(int width, int height, int** int_map);
	void showIntMap();
	void showStringMap();
	int** getIntMap();
	std::string* getStringMap();
	int getWidth();
	int getHeight();
	Symb getWallSymb();
	Symb getEmptySymb();
};

