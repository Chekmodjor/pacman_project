#include "AI.h"
AI::AI(Map gameMap)
{
	this->gameMap = gameMap;
	this->x_position = 0;
	this->y_position = 0;
	this->target_x_position = 0;
	this->target_y_position = 0;
}
AI::AI(Map gameMap, int x_position, int y_position)
{
	this->gameMap = gameMap;
	this->x_position = x_position;
	this->y_position = y_position;
	this->target_x_position = 0;
	this->target_y_position = 0;
}
void AI::setTargetCoord(int x_position, int y_position)
{
	this->target_x_position = x_position;
	this->target_y_position = y_position;
}
void AI::calculateShortestWay()
{
	std::vector<std::pair<int, int>> wave;
	std::vector<std::pair<int, int>> oldWave;
	oldWave.push_back(std::pair<int, int>(y_position, x_position));
	int nstep = 0;
	gameMap.getIntMap()[y_position][x_position] = 0;
	int dx[]{ 0,1,0,-1 };
	int dy[]{ -1,0,1,0 };
	bool exit = false;
	while (oldWave.size() > 0)
	{
		++nstep;
		wave.clear();
		for (std::vector<std::pair<int, int>>::iterator i = oldWave.begin(); i != oldWave.end(); ++i)
		{
			for (int d = 0; d < 4; ++d)
			{
				int ny = i->first + dy[d];
				int nx = i->second + dx[d];

				if (gameMap.getIntMap()[ny][nx] == gameMap.getEmptySymb().int_symb)
				{
					wave.push_back(std::pair<int, int>(ny, nx));
					gameMap.getIntMap()[ny][nx] = nstep;
				}
				if (nx == target_x_position && ny == target_y_position)
				{
					exit = true;
					break;
				}
			}
			if (exit)
				break;
		}
		if (exit)
			break;
		oldWave = wave;
	}
	wave.clear();
	oldWave.clear();
	shortestWay.clear();
	int x = target_x_position;
	int y = target_y_position;
	shortestWay.push_back(std::pair<int, int>(target_y_position, target_x_position));
	while (gameMap.getIntMap()[y][x] != 0)
	{
		for (int d = 0; d < 4; ++d)
		{
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (gameMap.getIntMap()[y][x] - 1 == gameMap.getIntMap()[ny][nx])
			{
				x = nx;
				y = ny;
				shortestWay.push_back(std::pair<int, int>(ny, nx));
				break;
			}
		}
	}
}
void AI::setOwnCoord(int x_position, int y_position)
{
	this->x_position = x_position;
	this->y_position = y_position;
}
void AI::setGameMap(Map gameMap)
{
	this->gameMap = gameMap;
}
Map AI::getGameMap()
{
	return this->gameMap;
}
void AI::showShortestWay()
{
	for (int i = shortestWay.size()-1; i >= 0; --i)
	{
		std::cout << shortestWay[i].second << ' ' << shortestWay[i].first << "  ";
	}
}