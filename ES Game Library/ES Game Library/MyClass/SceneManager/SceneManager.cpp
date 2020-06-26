#include "SceneManager.h"

void SceneManager::FileInitialize()
{
	title_scene->FileInitialize();
}

void SceneManager::Initialize()
{
	switch (SceneNumber)
	{
	case SceneNum::Scene_Title:
		title_scene->Initialize();
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

void SceneManager::Update()
{
	switch (SceneNumber)
	{
	case SceneNum::Scene_Title:
		title_scene->Update();
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

void SceneManager::Draw3D()
{
	switch (SceneNumber)
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
	switch (SceneNumber)
	{
	case SceneNum::Scene_Title:
		title_scene->Draw2D();

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
