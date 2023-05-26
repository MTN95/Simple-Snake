#include "Engine.h"

int main(int argc, char* argv[])
{
	mEngine::Engine* game = mEngine::Engine::Getinstance();

	game->Init("test", false);
	game->RunEngine();
	game->Clean();
	return 0;
}
