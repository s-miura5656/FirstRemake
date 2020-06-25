#include "Controller.h"

Controller::Controller()
{
	InputDevice.CreateKeyboard();
	InputDevice.CreateMouse();
}

void Controller::Initialize()
{

}

KeyboardState Controller::GetKeyState()
{
	KeyboardState state = Keyboard->GetState();
	return state;
}

KeyboardBuffer Controller::GetKeyBuffer()
{
	KeyboardBuffer buffer = Keyboard->GetBuffer();
	return buffer;
}

MouseBuffer Controller::GetMouseBuffer()
{
	MouseBuffer buffer = Mouse->GetBuffer();
	return buffer;
}

MouseState Controller::GetMouseState()
{
	MouseState state = Mouse->GetState();
	return state;
}
