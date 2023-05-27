#pragma once
#include <SDL.h>
#include <deque>
#include "common.h"
#include "Apple.h"
#include "SnakeSegment.h"

class Snake {
public:
	Snake(unsigned headColor, unsigned segmentColor, unsigned coinColor);
	~Snake();
	void restart();
	void update();
	void render(SDL_Renderer *renderer);
	inline bool isDead() { return this->dead; }


private:
	std::deque<SnakeSegment> segments;
	Apple coin;
	bool dead;
	unsigned direction;
	unsigned time, timeout;
	unsigned headColor, segmentColor, coinColor;
	SDL_Rect renderRect;

	void updateInputControls();
	void renderSnake(SDL_Renderer* renderer);
	void renderCoin(SDL_Renderer* renderer);
	void RenderGrid(SDL_Renderer* renderer);
	void addSegment(unsigned x, unsigned y);
	void moveSnake();
	bool checkForWallCollision();
	bool checkForSelfCollision();
	bool checkForCoinCollision();
	
};