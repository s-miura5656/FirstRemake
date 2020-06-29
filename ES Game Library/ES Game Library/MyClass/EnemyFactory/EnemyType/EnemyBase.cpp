#include "EnemyBase.h"

void EnemyBase::Update()
{
	m_enemy_param.pos.x += MoveEnemyDirection(m_enemy_param);
}

void EnemyBase::Draw2D()
{
	CharaBase::Draw2D(m_enemy_param.image);
}

float EnemyBase::MoveEnemyDirection(EnemyParam& enemy_param)
{
	//! 猪がフィールド内ならリターン
	if (enemy_param.pos.x > BOAR_MOVE_LIMIT_LEFT &&
		enemy_param.pos.x < BOAR_MOVE_LIMIT_RIGHT)
	{
		return;
	}

	//! 画面外に行ったら反転
	if (enemy_param.pos.x <= BOAR_MOVE_LIMIT_LEFT)
		m_move_flag = true;

	if (enemy_param.pos.x >= BOAR_MOVE_LIMIT_RIGHT)
		m_move_flag = false;

	//! true = 右へ移動 false = 左へ移動
	float speed = m_move_flag ? enemy_param.speed : -enemy_param.speed;

	 return speed;
}