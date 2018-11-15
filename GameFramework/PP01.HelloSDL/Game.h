#pragma once

#include <map>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

class GameObject;
using namespace std;

class Game
{
public:
	//Game() {}
	//~Game() {}
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	vector<GameObject*> m_gameObjects;

	//GameObject *m_go;
	//Player *m_player;
	//Enemy *m_enemy;

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_RendererFlip* m_pRendererFlip;

	Game() {}
	// create the s_pInstance member variable
	static Game* s_pInstance;
	// create the typedef
	
	int m_currentFrame;

	bool m_bRunning;
};
typedef Game TheGame;