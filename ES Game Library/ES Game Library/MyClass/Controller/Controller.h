#pragma once

#include "../../ESGLib.h"

class Controller
{
public:
	~Controller() {};

	void Initialize();

	KeyboardState GetKeyState();
	KeyboardBuffer GetKeyBuffer();
	MouseBuffer GetMouseBuffer();
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