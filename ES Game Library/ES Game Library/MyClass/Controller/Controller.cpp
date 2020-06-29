#include "Controller.h"

Controller::Controller()
{
	InputDevice.CreateKeyboard();
	InputDevice.CreateMouse();
}

void Controller::Initialize()
{

}

/*
* キーボード押している間
*/
KeyboardState Controller::GetKeyState()
{
	KeyboardState state = Keyboard->GetState();
	return state;
}

/*
* キーボード一回だけ
*/
KeyboardBuffer Controller::GetKeyBuffer()
{
	KeyboardBuffer buffer = Keyboard->GetBuffer();
	return buffer;
}

/*
* マウス一回だけ
*/
MouseBuffer Controller::GetMouseBuffer()
{
	MouseBuffer buffer = Mouse->GetBuffer();
	return buffer;
}

/*
* マウス押している間
*/ 
MouseState Controller::GetMouseState()
{
	MouseState state = Mouse->GetState();
	return state;
}
