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
	//! �����t�B�[���h���Ȃ烊�^�[��
	if (enemy_param.pos.x > BOAR_MOVE_LIMIT_LEFT &&
		enemy_param.pos.x < BOAR_MOVE_LIMIT_RIGHT)
	{
		return;
	}

	//! ��ʊO�ɍs�����甽�]
	if (enemy_param.pos.x <= BOAR_MOVE_LIMIT_LEFT)
		m_move_flag = true;

	if (enemy_param.pos.x >= BOAR_MOVE_LIMIT_RIGHT)
		m_move_flag = false;

	//! true = �E�ֈړ� false = ���ֈړ�
	float speed = m_move_flag ? enemy_param.speed : -enemy_param.speed;

	 return speed;
}