#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"

class bullet : public SDLGameObject
{
public:
	bullet(const LoaderParams* pParams) : SDLGameObject(pParams) {};
	virtual void draw();
	virtual void update();
	virtual void clean() {};
private:
	void handleInput();
	bool speed;
};