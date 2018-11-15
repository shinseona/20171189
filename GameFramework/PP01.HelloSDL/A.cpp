#include "A.h"


void A::load(int x, int y, int width, int height, std::string textureID) {
	GameObject::load(x, y, width, height, textureID);
}

void A::draw(SDL_Renderer* pRenderer) {
	GameObject::draw(pRenderer);
}

void A::clean() {

}

void A::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 8));
	m_x += x_speed;
	m_y += y_speed;
	moveRightLeft(100);
}

void A::setMovingspeed(int x, int y) {
	GameObject::setMovingspeed(x, y);
}

void A::moveRightLeft(int dist) {
	GameObject::moveRightLeft(dist);
}
