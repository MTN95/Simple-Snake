#pragma once
#include <SDL.h>
#include <vector>
#include "IObject.h"
#include "Vec2D.h"

class Snake : public IObject {

public:
	Snake(mEngine::Vec2D position);

	void Update() override;
	void Render() override;
	void Clean() override;

	std::vector<SDL_FRect>& GetSnakeRects() { return snakeRects; }

	void MoveX(float amount);
	void MoveY(float amount);

private:

	std::vector<SDL_FRect> snakeRects;
	mEngine::Vec2D snake_position;
	mEngine::Vec2D snake_velocity;

	const float WIDTH = 16;
	const float HEIGHT = 16;

};

