#pragma once

#include "../../ESGLib.h"
#include "../BaseClass/CharaBase.h"
#include "../BaseClass/Constant.h"
#include "../BaseClass/Collision.h"

enum PlayerNum
{
	Scope,
	Field,
	Player_NUM_MAX
};

struct PlayerPram
{
	int score;
	int ammo;
	bool shot;
};

class Player : public CharaBase
{
public:
	Player() {};
	~Player() {};

	void FileInitialize();
	void Initialize();
	void Update();
	void Draw3D() {};
	void Draw2D();
	void MoveScope();
	void LimitedRangeOfMovement();

private:
	std::vector<ImageParam> m_img_param;
};