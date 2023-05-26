#pragma once
#include <SDL.h>
#include <vector>
#include "IObject.h"
#include "Vec2D.h"

class Snake : public IObject {

public:
	Snake(mEngine::Vec2D position);

	void Update() override;
	void CheckWallsColiision(int SCREEN_WIDTH, int SCREEN_HEIGHT);
	void Render() override;
	void Clean() override;

	std::vector<SDL_FRect>& GetSnakeRects() { return snake_rects; }

	void MoveX(float amount);
	void MoveY(float amount);

private:

	std::vector<SDL_FRect> snake_rects;
	mEngine::Vec2D snake_position;
	mEngine::Vec2D snake_velocity;

	const float SNAKE_SIZE = 20;

};

