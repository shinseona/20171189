#include "bullet.h"
#include "InputHandler.h"
#include "GameObject.h"

void bullet::draw()
{
	SDLGameObject::draw();
}


void bullet::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_Z))
	{
		speed = true;
	}
	

}

void bullet::update()
{
	if (speed == true)
	{
		m_velocity.setX(2);
	}
	handleInput(); // add our function
	m_currentFrame = int(((SDL_GetTicks() / 100)%1));
	SDLGameObject::update();

}
