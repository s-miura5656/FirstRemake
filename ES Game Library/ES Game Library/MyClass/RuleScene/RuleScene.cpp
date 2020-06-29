#include "RuleScene.h"
#include "../SceneManager/SceneManager.h"
#include "../SoundManager/SoundManager.h"
#include "../DebugManager/DebugManager.h"

void RuleScene::FileInitialize()
{
	m_img_param.image = GraphicsDevice.CreateSpriteFromFile(_T("Rule/rule.png"));
}

void RuleScene::Initialize()
{
	m_img_param.pos = Vector3_Zero;
	m_img_param.rect = IMAGE_SIZE_SCREEN;
}

void RuleScene::Update()
{
	CharaBase::ChangeScene(SceneNum::Scene_Main, SE_Num::Page);
}

void RuleScene::Draw2D()
{
	CharaBase::Draw2D(m_img_param);
}
