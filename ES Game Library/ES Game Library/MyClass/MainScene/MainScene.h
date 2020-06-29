#pragma once

#include "../../ESGLib.h"
#include "../Player/Player.h"

class MainScene
{
public:
	MainScene() {
		m_player.reset(new Player);
	};

	~MainScene() { m_player.reset(); };

	void FileInitialize();
	void Initialize();
	void Update();
	void Draw3D() {};
	void Draw2D();

private:
	std::unique_ptr<Player> m_player;
};