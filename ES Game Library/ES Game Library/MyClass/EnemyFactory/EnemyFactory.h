#pragma once

#include "../EnemyManager/EnemyManager.h"

class EnemyBase;

class EnemyFactory : public EnemyManager
{
public:
	EnemyFactory() {};
	~EnemyFactory() {};

	virtual void FileInitialize() {};
	virtual void Initialize();
	virtual void Update();
	virtual void Draw2D();
	virtual void Draw3D() {};

	void CreateEnemy(EnemyParam& enemy_param);


private:
	std::vector<EnemyBase*> m_enemys;
};