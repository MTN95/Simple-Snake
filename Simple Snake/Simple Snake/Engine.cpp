#include "Engine.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init(const char* title, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL_Init Failed: " << SDL_GetError() << std::endl;
		return false;
	}
	int window_flags = 0;
	(fullscreen) ? window_flags = SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

	m_Window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		window_flags
	);

	if (!m_Window)
	{
		std::cerr << "SDL_CreateWindow Failed: " << SDL_GetError() << std::endl;
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_Renderer)
	{
		std::cerr << "SDL_CreateRenderer Failed: " << SDL_GetError() << std::endl;
		return false;
	}

	backgroundColor = new SDL_Color{ 0, 64, 0};
	snakeHeadColor = new SDL_Color{ 0, 120, 0 };
	snakeSegmentColor = new SDL_Color{ 0, 255, 0 };
	appleColor = new SDL_Color{ 255, 0, 0 };


	m_Snake = new Snake(snakeHeadColor, snakeSegmentColor, appleColor);

	return true;
}

void Engine::Update()
{
	m_Snake->update();
}

void Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 150, 150, 150, 255);
	SDL_RenderClear(m_Renderer);

	m_Snake->render(m_Renderer);

	SDL_RenderPresent(m_Renderer);

	SDL_Delay(20);
}

void Engine::Clean()
{
	m_Snake = nullptr;
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	SDL_Quit();
}

void Engine::Events()
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
		case SDL_QUIT:
			m_IsRunning = false;
			break;
		case SDL_KEYDOWN:
			if (sdlEvent.key.keysym.sym == SDLK_ESCAPE)
				m_IsRunning = false;
			else if (sdlEvent.key.keysym.sym == SDLK_RETURN)
			{
				if (m_Snake->isDead())
					m_Snake->restart();
			}
			break;
		}
	}
}

void Engine::RunEngine()
{
	if (!Init("Simple Snake", false))
	{
		std::cout << "Failed to Init Engine!\n";
		return;
	}

	m_IsRunning = true;
	while (m_IsRunning)
	{
		Events();
		Update();
		Render();
	}

	Clean();
}