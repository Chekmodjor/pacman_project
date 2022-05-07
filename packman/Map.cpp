#include "Map.h"
Map::Map()
{
	width = 0;
	height = 0;
	string_map = nullptr;
	int_map = nullptr;
	wall = Symb();
	empty = Symb();
}
Map::Map(int width, int height, Symb wall, Symb empty)
{
	this->width = width;
	this->height = height;
	this->wall = wall;
	this->empty = empty;
	string_map = new char*[height];
	int_map = new int* [height];
	for (int i = 0; i < height; ++i)
	{
		int_map[i] = new int[width];
		string_map[i] = new char[width];
	}
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			string_map[i][j] = empty.str_symb;
			int_map[i][j] = empty.int_symb;
		}
	}
}
Map::Map(Map* map)
{
	this->width = map->width;
	this->height = map->height;
	this->wall.int_symb = map->wall.int_symb;
	this->wall.str_symb = map->wall.str_symb;
	this->empty.int_symb = map->empty.int_symb;
	this->empty.str_symb = map->empty.str_symb;
	this->string_map = new char*[this->height];
	this->int_map = new int* [height];
	for (int i = 0; i < height; ++i)
	{
		this->string_map[i] = new char[width];
		this->int_map[i] = new int[width];
		for (int j = 0; j < width; ++j)
		{
			this->int_map[i][j] = map->int_map[i][j];
			this->string_map[i][j] = map->string_map[i][j];
		}
	}
}
void Map::update_int_map()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (string_map[i][j] == wall.str_symb)
				int_map[i][j] = wall.int_symb;
			else
				int_map[i][j] = empty.int_symb;
		}
	}
}
void Map::update_string_map()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (int_map[i][j] == wall.int_symb)
				string_map[i][j] = wall.str_symb;
			else
				string_map[i][j] = empty.str_symb;
		}
	}
}
void Map::setStringMap(int width, int height, std::string* string_map)
{
	clearMemory();
	this->width = width;
	this->height = height;
	this->string_map = new char*[height];
	this->int_map = new int* [height];
	for (int i = 0; i < height; ++i)
	{
		this->string_map[i] = new char[width];
		this->int_map[i] = new int[width];
		for (int j = 0; j < width; ++j)
		{
			this->string_map[i][j] = string_map[i][j];
		}
	}
	update_int_map();
}
void Map::setIntMap(int width, int height, int** int_map)
{
	clearMemory();
	this->width = width;
	this->height = height;
	this->int_map = new int* [height];
	this->string_map = new char*[height];
	for (int i = 0; i < height; ++i)
	{
		this->int_map[i] = new int[width];
		this->string_map[i] = new char[width];
		for (int j = 0; j < width; ++j)
		{
			this->int_map[i][j] = int_map[i][j];
		}
	}
	update_string_map();
}
void Map::showIntMap()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << std::setw(3) << int_map[i][j];
		}
		std::cout << '\n';
	}
}
void Map::showStringMap()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << string_map[i][j];
		}
		std::cout << '\n';
	}
}
int** Map::getIntMap()
{
	return this->int_map;
}
char** Map::getStringMap()
{
	return this->string_map;
}
int Map::getWidth()
{
	return this->width;
}
int Map::getHeight()
{
	return this->height;
}
Symb Map::getWallSymb()
{
	return this->wall;
}
Symb Map::getEmptySymb()
{
	return this->empty;
}
void Map::clearMemory()
{
	if (this->string_map)
	{
		for (int i = 0; i < height; ++i)
		{
			delete[] this->string_map[i];
		}
		delete[] this->string_map;
	}
	if (this->int_map)
	{

		for (int i = 0; i < height; ++i)
		{
			delete[] this->int_map[i];
		}
		delete[] this->int_map;
	}

}
