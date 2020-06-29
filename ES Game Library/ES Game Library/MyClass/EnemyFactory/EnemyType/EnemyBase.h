#pragma once

#include "../EnemyFactory.h"

class EnemyBase : public EnemyFactory
{
public:
	EnemyBase(EnemyParam& enemy_param) { 
		m_enemy_param = enemy_param; 
		m_move_flag = false;
		m_move_speed = MoveEnemyDirection(m_enemy_param);
	};

	~EnemyBase() {};

	void FileInitialize() {};
	void Initialize() {};
	void Update();
	void Draw2D();
	void Draw3D() {};

	float MoveEnemyDirection(EnemyParam& enemy_param);

private:
	EnemyParam m_enemy_param;
	bool m_move_flag;
	float m_move_speed;
};