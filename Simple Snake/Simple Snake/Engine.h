#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Snake.h"

namespace mEngine
{
	class Engine
	{
	public:

		int cnt = 0;

		static inline Engine* Getinstance()
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

		bool LoadSFX();

		inline bool IsRunning() { return m_IsRunning; }
		inline SDL_Renderer* GetRenderer() { return m_Renderer; }

		inline SDL_Window* GetWindow() { return m_Window; }

	private:

		Engine() : m_Window(nullptr), m_Renderer(nullptr), m_IsRunning(false) {
			snake = nullptr;
		}

		static Engine* s_Instance;

		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;

		bool m_IsRunning;

		const int SCREEN_WIDTH = 800;
		const int SCREEN_HEIGHT = 600;

		Snake* snake;

	};
}
