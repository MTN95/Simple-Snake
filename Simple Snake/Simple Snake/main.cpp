#include "Engine.h"

int main(int argc, char* argv[])
{
	Engine* SnakeGame = Engine::GetInstance();
	SnakeGame->RunEngine();
	SnakeGame->Clean();
	return 0;
}
