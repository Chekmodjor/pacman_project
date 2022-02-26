#pragma once
#include "Map.h"
#include <vector>
class AI
{
private:
	Map gameMap;
	int x_position;
	int y_position;
	int target_x_position;
	int target_y_position;

	std::vector<std::pair<int, int>> shortestWay;
public:
	AI(const Map gameMap);
	AI(const Map gameMap, int x_position, int y_position);
	void setTargetCoord(int x_position, int y_position);
	void setOwnCoord(int x_position, int y_position);
	void calculateShortestWay();
	void setGameMap(Map gameMap);
	void showShortestWay();
	Map getGameMap();
};

