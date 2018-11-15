#include "Player.h"
#include "GameObject.h"


void Player::draw()
{
	SDLGameObject::draw();
}

void Player::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
	m_acceleration.setX(1);
	SDLGameObject::update();
}

