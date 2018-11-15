#pragma once

#include <map>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

class TextureManagerr;
class GameObject;
using namespace std;

class Game
{
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}


	SDL_Renderer* getRenderer()const { return m_pRenderer; }
private:

	Game() {}

	static Game* s_pInstance;

	typedef Game TheGame;




	SDL_Window * m_pWindow;
	SDL_Renderer*m_pRenderer;

	int m_currentFrame;
	int m_currentFrame2;
	bool m_bRunning;

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* m_monster;
	GameObject* m_monster2;

};

typedef Game TheGame;