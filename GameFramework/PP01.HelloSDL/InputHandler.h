#include "SDL.h"
#include "Vector2D.h"
#include <vector>
	
enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};
class InputHandler
{
public:

	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	std::vector<bool> m_mouseButtonStates;

	// mouse motion event					
	Vector2D* m_mousePosition;
	Vector2D* getMousePosition();
	bool getMouseButtonState(int buttonNumber);
	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	bool isKeyDown(SDL_Scancode key);

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};



typedef InputHandler TheInputHandler;
#pragma once
