#pragma once

#include "../BaseClass/CharaBase.h"

class EnemyFactory;

/*
* è¨Ç≥Ç¢ 1 Å` 5 ëÂÇ´Ç¢
*/
enum EnemyType
{
	Boar_1,
	Boar_2,
	Boar_3,
	Boar_4,
	Boar_5,
	Pig_1,
	Pig_2,
	Pig_3,
	Pig_4,
	Pig_5,
	Enemy_NUM_MAX
};

struct EnemyParam
{
	ImageParam image;
	Vector3 pos;
	float speed;
	bool dead;
	int type;

	EnemyParam() {
		speed = 1.f;
		dead = false;
	}
};

class EnemyManager : public CharaBase
{
public:
	EnemyManager() { m_enemy_factory.reset(new EnemyFactory); };
	~EnemyManager() { m_enemy_factory.reset(nullptr); };

	virtual void FileInitialize() {};
	virtual void Initialize();
	virtual void Update();
	virtual void Draw2D();
	virtual void Draw3D() {};

private:
	std::vector<EnemyParam> enemys_pram;
	std::unique_ptr<EnemyFactory> m_enemy_factory;
};