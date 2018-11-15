#include "Game.h"
#include <iostream>
#include "A.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		if (!TheTextureManager::Instance()->load("Assets/me.png", "animate", m_pRenderer)) {
			return false;
		}

		//m_go = new GameObject();
		//m_player = new Player();
		//m_enemy = new Enemy();
		a = new A();
		a2 = new A();

		//m_go->load(100, 100, 129, 165, "animate");
		//m_player->load(300, 300, 129, 165, "animate");
		//m_enemy->load(0, 0, 129, 165, "animate");
		a->load(100, 100, 129, 165, "animate");
		a2->load(300, 300, 129, 165, "animate");

		a->setMovingspeed(1, 0);
		a2->setMovingspeed(2, 0);

		//m_gameObjects.push_back(m_go);
		//m_gameObjects.push_back(m_player);
		//m_gameObjects.push_back(m_enemy);
		m_gameObjects.push_back(a);
		m_gameObjects.push_back(a2);
	}
	else {
		m_bRunning = false;
		return false;
	}
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_SetRenderDrawColor(m_pRenderer, 0, 150, 255, 255);
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw(m_pRenderer);
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update() {
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void Game::clean() {
	std::cout << "cleanning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}