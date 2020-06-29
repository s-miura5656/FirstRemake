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
* �L�[�{�[�h�����Ă����
*/
KeyboardState Controller::GetKeyState()
{
	KeyboardState state = Keyboard->GetState();
	return state;
}

/*
* �L�[�{�[�h��񂾂�
*/
KeyboardBuffer Controller::GetKeyBuffer()
{
	KeyboardBuffer buffer = Keyboard->GetBuffer();
	return buffer;
}

/*
* �}�E�X��񂾂�
*/
MouseBuffer Controller::GetMouseBuffer()
{
	MouseBuffer buffer = Mouse->GetBuffer();
	return buffer;
}

/*
* �}�E�X�����Ă����
*/ 
MouseState Controller::GetMouseState()
{
	MouseState state = Mouse->GetState();
	return state;
}
