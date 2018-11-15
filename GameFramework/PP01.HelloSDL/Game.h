#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Player.h"
#include "Enemy.h"
#include <vector>

using namespace std;

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
private:
	std::vector<GameObject*> m_gameObjects;
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* a;
	GameObject* a2;
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};