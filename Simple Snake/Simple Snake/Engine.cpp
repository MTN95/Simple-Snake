#include "Engine.h"
#include <iostream>

namespace mEngine {
    Engine* Engine::s_Instance = nullptr;

    bool mEngine::Engine::Init(const char * title, bool fullscreen) {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            std::cout << "Failed to initialize SDL! SDL_Error: " << SDL_GetError() << '\n';
            return false;
        }

        int window_flags = 0;

        if (fullscreen) {
            window_flags = SDL_WINDOW_FULLSCREEN;
        }

        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

        if (m_Window == nullptr) {
            std::cout << "Failed to Create Window! SDL_Error: " << SDL_GetError() << '\n';
            return false;
        }

        m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (m_Renderer == nullptr) {
            std::cout << "Failed to Create Renderer! SDL_Error: " << SDL_GetError() << '\n';
            return false;
        }

        if (TTF_Init() != 0) {
            std::cout << "SDL_ttf could not initialize!SDL_ttf Error : " << TTF_GetError() << std::endl;
            return false;
        }

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            std::cout << "SDL_Mixer could not initialize! Mix_Error : " << Mix_GetError() << std::endl;
            return false;
        }

        if (!LoadSFX()) {
            std::cout << "Failed to load SFX!\n";
            return false;
        }

        snake = new Snake( { 400,300 } );
        //apple = new Apple( { 500,400 } );

        m_IsRunning = true;
        return true;
    }

    void mEngine::Engine::Update() {
        std::cout << "updating: " << cnt++ << '\n';
        snake->Update();
        //apple->Update();
    }

    void Engine::Render() {
        
        // Prepare scene
        SDL_SetRenderDrawColor(m_Renderer, 160, 160, 160, 255);
        SDL_RenderClear(m_Renderer);

        DrawGridLines();

		snake->Render();
        //apple->Render();

        // Present scene
        SDL_RenderPresent(m_Renderer);
    }

    void Engine::DrawGridLines()
    {
        SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
		// Draw horizontal grid lines
		for (int i = 0; i <= GRID_ROWS; i++) {
			float y = i * CELL_SIZE;
			SDL_RenderDrawLineF(m_Renderer, 0, y, SCREEN_WIDTH, y);
		}

		// Draw vertical grid lines
		for (int j = 0; j <= GRID_COLS; j++) {
			float x = j * CELL_SIZE;
			SDL_RenderDrawLineF(m_Renderer, x, 0, x, SCREEN_HEIGHT);
		}
    }

    void Engine::Clean() {
        
        snake->Clean();
        //apple->Clean();

        SDL_DestroyRenderer(m_Renderer);
        m_Renderer = nullptr;

        SDL_DestroyWindow(m_Window);
        m_Window = nullptr;

        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
    }

    void Engine::Events() {
        SDL_Event event; 

        while (SDL_PollEvent(&event)) {
            bool PressedOnce = event.type == SDL_KEYDOWN && event.key.repeat == 0;

            if (event.type == SDL_QUIT) {
                std::cout << "Quit\n";
                Quit();
            }           
            if (PressedOnce && event.key.keysym.sym == SDLK_ESCAPE) {
                std::cout << "Quit\n";
                Quit();
            }
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                snake->MoveY(-1.f);
                break;
            case SDLK_DOWN:
                snake->MoveY(1.f);
                break;
            case SDLK_RIGHT:
                snake->MoveX(1.f);
                break;
            case SDLK_LEFT:
                snake->MoveX(-1.f);
                break;
            }
        }
    }
    void Engine::RunEngine() {
        while (m_IsRunning)
        {
            Events();
            Update();
            Render();
            
        }
        Clean();
    }

    bool Engine::LoadSFX(){
        return true;
    }

}
