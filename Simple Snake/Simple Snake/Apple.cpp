#include "Apple.h"
#include "Engine.h"

Apple::Apple(mEngine::Vec2D position)
{
	apple_rect.x = position.x;
	apple_rect.y = position.y;
	apple_rect.w = APPLE_SIZE;
	apple_rect.h = APPLE_SIZE;
}

void Apple::Update()
{
	
}

void Apple::Render()
{
	SDL_SetRenderDrawColor(mEngine::Engine::Getinstance()->GetRenderer(), 255, 0, 0, 255);
	SDL_RenderFillRectF(mEngine::Engine::Getinstance()->GetRenderer(), &apple_rect);

}

void Apple::Clean()
{
}

bool Apple::isColliding()
{
	SDL_Log("IsColliding!......\n");
	return false;
}
