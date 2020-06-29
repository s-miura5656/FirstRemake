#include "MainScene.h"

void MainScene::FileInitialize()
{
	m_player->FileInitialize();
}

void MainScene::Initialize()
{
	m_player->Initialize();
}

void MainScene::Update()
{
	m_player->Update();
}

void MainScene::Draw2D()
{
	m_player->Draw2D();
}
