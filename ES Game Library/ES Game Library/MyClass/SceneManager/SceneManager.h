#pragma once

#include "../../ESGLib.h"
#include "../TitleScene/TitleScene.h"
#include "../Explanation/ExplanationScene.h"

enum SceneNum
{
	Scene_Title,
	Scene_Explanation,
	Scene_Rule,
	Scene_Main,
	Scene_Result,
	Scene_Retry,
	Scene_Return_Title
}; 

class SceneManager
{
public:
	~SceneManager() 
	{
		m_title_scene.reset();
		m_explanation_scene.reset();
	};

	void FileInitialize();
	void Initialize();
	void Update();
	void Draw3D();
	void Draw2D();

	void SetSceneNumber(int scene_number) { m_SceneNumber = scene_number; }
	int GetSceneNumber() { return m_SceneNumber; }

	static SceneManager& Instance() {
		static SceneManager instance;
		return instance;
	};

private:
	SceneManager() {
		m_SceneNumber = SceneNum::Scene_Title;
		m_title_scene.reset(new TitleScene);
		m_explanation_scene.reset(new Explanation);
	};
	SceneManager(const SceneManager&) = delete;
	void operator=(const SceneManager&) = delete;

	std::shared_ptr<TitleScene> m_title_scene;
	std::shared_ptr<Explanation> m_explanation_scene;

	int m_SceneNumber;
};