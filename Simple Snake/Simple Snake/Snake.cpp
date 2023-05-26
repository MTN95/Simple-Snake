#include "Snake.h"
#include "Engine.h"

Snake::Snake(mEngine::Vec2D position) {
	
	snake_position = position;

	SDL_FRect initialRect;
	initialRect.x = snake_position.x;
	initialRect.y = snake_position.y;
	initialRect.w = WIDTH;
	initialRect.h = HEIGHT;

	snakeRects.push_back(initialRect);
}

void Snake::Update() {
	snake_position.x += snake_velocity.x;
	snake_position.y += snake_velocity.y;
}

void Snake::Render() {
	SDL_SetRenderDrawColor(mEngine::Engine::Getinstance()->GetRenderer(), 255, 0, 0, 255);

	for (const auto& rect : snakeRects) {
		SDL_FRect renderRect;
		renderRect.x = rect.x;
		renderRect.y = rect.y;
		renderRect.w = rect.w;
		renderRect.h = rect.h;

		SDL_RenderFillRectF(mEngine::Engine::Getinstance()->GetRenderer(), &renderRect);
	}
}


void Snake::Clean() {

}

void Snake::MoveX(float amount) {
	snake_velocity.x = amount;
	snake_velocity.y = 0;
}

void Snake::MoveY(float amount) {
	snake_velocity.x = 0;
	snake_velocity.y = amount;
}