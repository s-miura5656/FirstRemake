#include "EnemyManager.h"
#include "../EnemyFactory/EnemyFactory.h"

void EnemyManager::Initialize()
{
	enemys_pram.resize(EnemyType::Enemy_NUM_MAX);

	for (int i = 0; 0 < EnemyType::Enemy_NUM_MAX; i++)
	{
		enemys_pram[i].type = i;
		enemys_pram[i].image.image = GraphicsDevice.CreateSpriteFromFile(_T("Title/boar.png"));
		enemys_pram[i].image.image_size = Vector2(600, 200);
		enemys_pram[i].image.ImageDivisionSize(Vector2(2, 1));
		enemys_pram[i].pos = Vector3(BOAR_MOVE_LIMIT_LEFT, 50 * (i % 5), -100);
		enemys_pram[i].speed = 2 * (i % 5) + 5;
	}

	m_enemy_factory->CreateEnemy(enemys_pram[EnemyType::Boar_1]);
}

void EnemyManager::Update()
{
	m_enemy_factory->Update();
}

void EnemyManager::Draw2D()
{
	m_enemy_factory->Draw2D();
}
