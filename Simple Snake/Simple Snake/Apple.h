#pragma once
#include <SDL.h>
#include "IObject.h"
#include "Vec2D.h"

class Apple : public IObject
{
public:

	Apple(mEngine::Vec2D position);

	void Update() override;
	void Render() override;
	void Clean() override;

	bool isColliding();

private:
	SDL_FRect apple_rect;
	
	const float APPLE_SIZE = 20;
};

