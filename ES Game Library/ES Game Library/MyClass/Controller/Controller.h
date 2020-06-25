#pragma once

#include "../../ESGLib.h"

class Controller
{
public:
	~Controller() {};

	void Initialize();

	// キーボード押している間
	KeyboardState GetKeyState();
	// キーボード一回だけ
	KeyboardBuffer GetKeyBuffer();
	// マウス一回だけ
	MouseBuffer GetMouseBuffer();
	// マウス押している間
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