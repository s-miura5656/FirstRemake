#include "EnemyFactory.h"
#include "EnemyType/EnemyBase.h"

void EnemyFactory::Initialize()
{

}

void EnemyFactory::Update()
{
	for (auto&& enemy : m_enemys)
	{
		enemy->Update();
	}
}

void EnemyFactory::Draw2D()
{
	for (auto&& enemy : m_enemys)
	{
		enemy->Draw2D();
	}
}

void EnemyFactory::CreateEnemy(EnemyParam& enemy_param)
{
	m_enemys.push_back(new EnemyBase(enemy_param));
}
