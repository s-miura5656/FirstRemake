#pragma once

#include "../../ESGLib.h"

class Controller
{
public:
	~Controller() {};

	void Initialize();

	// �L�[�{�[�h�����Ă����
	KeyboardState GetKeyState();
	// �L�[�{�[�h��񂾂�
	KeyboardBuffer GetKeyBuffer();
	// �}�E�X��񂾂�
	MouseBuffer GetMouseBuffer();
	// �}�E�X�����Ă����
	MouseState GetMouseState();

	static Controller& Instance() {
		static Controller instance;
		return instance;
	}

private:
	Controller();
	Controller(const Controller&) = delete;
	void operator=(const Controller&) = delete;
};