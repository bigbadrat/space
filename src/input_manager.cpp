#include <iostream>
#include <GLFW/glfw3.h>
#include "input_manager.h"
#include "event_manager.h"
#include "engine.h"
#include "renderer.h"

namespace Tanaka
{
InputManager* InputManager::_instance = NULL;
/*
void simple_mouse(int button, int up, int x, int y)
{
    InputManager::get()->mouse(button,up,x,y);
}
*/
void glfw_keyboard(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	InputManager::get()->key_event(key, (action == GLFW_PRESS)?InputManager::KEY_ACTION_PRESS : InputManager::KEY_ACTION_RELEASE,0);
}

void glfw_mouse(GLFWwindow* window, int button, int action, int mods)
{
	InputManager::get()->mouse_event(button, (action == GLFW_PRESS)?InputManager::KEY_ACTION_PRESS : InputManager::KEY_ACTION_RELEASE,0,0);
}

InputManager::InputManager()
{
    _instance = this;
}

void InputManager::init()
{
	//TODO: Find a way to do this without using the renderer :(
	glfwSetKeyCallback(Renderer::get()->getWindow(),glfw_keyboard);
	glfwSetMouseButtonCallback(Renderer::get()->getWindow(), glfw_mouse);
}

void InputManager::key_event(int key, KEY_ACTION action, int mods)
{
	if (action == KEY_ACTION_PRESS)
	{
		std::cout << "Pressed key:" << key  << std::endl;
		Event e;
		e.type = -1;
		switch (key)
		{
		case GLFW_KEY_RIGHT:
			e.type = 6;
			break;
		case GLFW_KEY_LEFT:
			e.type = 4;
			break;
		case GLFW_KEY_UP:
			e.type = 8;
			break;
		case GLFW_KEY_DOWN:
			e.type = 2;
			break;
		}
		if (e.type != -1)
			Engine::get().event_manager().publish( e );
	}
	else if (action == KEY_ACTION_RELEASE)
	{
		std::cout << "Released key:" << key << std::endl;
	}

}

void InputManager::mouse_event(int button, KEY_ACTION action, int x, int y)
{
	std::cout << "Pressed mouse button "<< button << ( (action==KEY_ACTION_PRESS)?" down":" up" ) << " at position:" << x << "," << y << std::endl;
}

InputManager* InputManager::get()
{
    return _instance;
}
}
