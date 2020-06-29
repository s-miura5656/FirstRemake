#include "SceneManager.h"

void SceneManager::FileInitialize()
{
	m_title_scene->FileInitialize();
	m_explanation_scene->FileInitialize();
	m_rule_scene->FileInitialize();
	m_main_scene->FileInitialize();
}

void SceneManager::Initialize()
{
	m_title_scene->Initialize();
	m_explanation_scene->Initialize();
	m_rule_scene->Initialize();
	m_main_scene->Initialize();
}

void SceneManager::Update()
{
	switch (m_SceneNumber)
	{
	case SceneNum::Scene_Title:
		m_title_scene->Update();
		break;
	case SceneNum::Scene_Explanation:
		m_explanation_scene->Update();
		break;
	case SceneNum::Scene_Rule:
		m_rule_scene->Update();
		break;
	case SceneNum::Scene_Main:
		m_main_scene->Update();
		break;
	case SceneNum::Scene_Result:

		break;
	case SceneNum::Scene_Retry:
		SceneManager::Initialize();
		SetSceneNumber(SceneNum::Scene_Main);
		break;
	case SceneNum::Scene_Return_Title:
		SceneManager::Initialize();
		SetSceneNumber(SceneNum::Scene_Title);
		break;
	}
}

void SceneManager::Draw3D()
{
	switch (m_SceneNumber)
	{
	case SceneNum::Scene_Title:

		break;
	case SceneNum::Scene_Explanation:

		break;
	case SceneNum::Scene_Rule:

		break;
	case SceneNum::Scene_Main:

		break;
	case SceneNum::Scene_Result:

		break;
	}
}

void SceneManager::Draw2D()
{
	switch (m_SceneNumber)
	{
	case SceneNum::Scene_Title:
		m_title_scene->Draw2D();
		break;
	case SceneNum::Scene_Explanation:
		m_explanation_scene->Draw2D();
		break;
	case SceneNum::Scene_Rule:
		m_rule_scene->Draw2D();
		break;
	case SceneNum::Scene_Main:
		m_main_scene->Draw2D();
		break;
	case SceneNum::Scene_Result:

		break;
	}
}
