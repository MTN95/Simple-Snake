#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "Snake.h"
#include "Apple.h"


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
		void DrawGridLines();
		void Clean();
	
		void Events();
		void RunEngine();

		bool LoadSFX();

		inline bool IsRunning() { return m_IsRunning; }
		inline SDL_Renderer* GetRenderer() { return m_Renderer; }

		inline SDL_Window* GetWindow() { return m_Window; }
		inline const Vec2D* GetScreenDimensions() { return new Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT); }
		inline const Vec2D* GetGridDimensions() { return new Vec2D(GRID_ROWS, GRID_ROWS); }
		inline const float& GetGridSize() { return CELL_SIZE; }

	private:

		Engine() : m_Window(nullptr), m_Renderer(nullptr), m_IsRunning(false) {
			snake = nullptr;
			//apple = nullptr;
		}

		static Engine* s_Instance;

		SDL_Window* m_Window;
		SDL_Renderer* m_Renderer;

		bool m_IsRunning;

		static const int SCREEN_WIDTH = 800;
		static const int SCREEN_HEIGHT = 600;
		const float CELL_SIZE = 20; // Adjust this value to change the size of each grid cell

		float GRID_ROWS = SCREEN_HEIGHT / CELL_SIZE;
		float GRID_COLS = SCREEN_WIDTH / CELL_SIZE;
		
		Snake* snake;
		//Apple* apple;
	};
}
