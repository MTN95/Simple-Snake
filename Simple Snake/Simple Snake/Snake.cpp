#include "Snake.h"
#include "Engine.h"

Snake::Snake(mEngine::Vec2D position) {
	
	snake_position = position;
	
	SDL_FRect initialRect{};
	initialRect.x = snake_position.x;
	initialRect.y = snake_position.y;
	initialRect.w = SNAKE_SIZE;
	initialRect.h = SNAKE_SIZE;

	snake_rects.emplace_back(initialRect);
}


void Snake::Update() {
	snake_position.x += snake_velocity.x;
	snake_position.y += snake_velocity.y;

	auto SCREEN_WIDTH = mEngine::Engine::Getinstance()->GetScreenDimensions()->x;
	auto SCREEN_HEIGHT = mEngine::Engine::Getinstance()->GetScreenDimensions()->y;
	auto GRID_ROWS = mEngine::Engine::Getinstance()->GetGridDimensions()->x;
	auto GRID_COLS = mEngine::Engine::Getinstance()->GetGridDimensions()->y;
	auto CELL_SIZE = mEngine::Engine::Getinstance()->GetGridSize();

	CheckWallsColiision(SCREEN_WIDTH, SCREEN_HEIGHT);

	for (auto& rect : snake_rects) {
		rect.x = snake_position.x;
		rect.y = snake_position.y;
	}
}

void Snake::CheckWallsColiision(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	if (snake_position.x < 0)
		snake_position.x = 0;
	else if (snake_position.x >= SCREEN_WIDTH - SNAKE_SIZE)
		snake_position.x = SCREEN_WIDTH - SNAKE_SIZE;

	if (snake_position.y < 0)
		snake_position.y = 0;
	else if (snake_position.y >= SCREEN_HEIGHT - SNAKE_SIZE)
		snake_position.y = SCREEN_HEIGHT - SNAKE_SIZE;
}

void Snake::Render() {
	SDL_SetRenderDrawColor(mEngine::Engine::Getinstance()->GetRenderer(), 0, 255, 0, 255);

	for (auto& rect : snake_rects)
	{
		SDL_RenderFillRectF(mEngine::Engine::Getinstance()->GetRenderer(), &rect);
	}

}

void Snake::Clean() {

}

void Snake::MoveX(float amount) {
	snake_velocity.x = amount * SNAKE_SIZE;
	snake_velocity.y = 0;
}

void Snake::MoveY(float amount) {
	snake_velocity.x = 0;
	snake_velocity.y = amount * SNAKE_SIZE;
}