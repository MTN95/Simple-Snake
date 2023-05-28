#pragma once
#include "Snake.h"

class Engine
{
public:
	static inline Engine* GetInstance()
	{
		return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
	}

	bool Init(const char* title, bool fullscreen);
	void Quit() { m_IsRunning = false; }

	void Update();
	void Render();
	void Clean();

	void Events();
	void RunEngine();

private:
	Engine() : m_Window(nullptr), m_Renderer(nullptr), m_IsRunning(false) {}

	static Engine* s_Instance;

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	bool m_IsRunning;

	SDL_Color* backgroundColor;
	SDL_Color* snakeHeadColor;
	SDL_Color* snakeSegmentColor;
	SDL_Color* appleColor;

	Snake* m_Snake;
};