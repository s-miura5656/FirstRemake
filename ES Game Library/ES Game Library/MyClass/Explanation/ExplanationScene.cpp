#include "ExplanationScene.h"
#include "../SceneManager/SceneManager.h"
#include "../SoundManager/SoundManager.h"
#include "../DebugManager/DebugManager.h"

void Explanation::FileInitialize()
{
	m_img_param.image = GraphicsDevice.CreateSpriteFromFile(_T("Explanation/Operation.png"));
}

void Explanation::Initialize()
{
	m_img_param.pos = Vector3_Zero;
	m_img_param.rect = IMAGE_SIZE_SCREEN;
}

void Explanation::Update()
{
	CharaBase::ChangeScene(SceneNum::Scene_Rule, SE_Num::Page);
}

void Explanation::Draw2D()
{
	CharaBase::Draw2D(m_img_param);
}