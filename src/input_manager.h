#ifndef TANAKA_INPUT_HANDLER_H
#define TANAKA_INPUT_HANDLER_H

namespace Tanaka
{
class InputManager
{
public:
	enum KEY_ACTION
	{
		KEY_ACTION_PRESS,
		KEY_ACTION_RELEASE,
		KEY_ACTION_HOLD
	};
    InputManager();    

    void init();

	void key_event(int key, KEY_ACTION action, int mods);

	void mouse_event(int button, KEY_ACTION action, int x, int y);

    static
    InputManager* get();

private:
    static
    InputManager* _instance;

};

}


#endif
