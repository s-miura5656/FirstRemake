#pragma once

#include "../../ESGLib.h"
#include "../TitleScene/TitleScene.h"
#include "../Explanation/ExplanationScene.h"
#include "../RuleScene/RuleScene.h"
#include "../MainScene/MainScene.h"

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
		m_rule_scene.reset();
		m_main_scene.reset();
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
		m_rule_scene.reset(new RuleScene);
		m_main_scene.reset(new MainScene);
	};
	SceneManager(const SceneManager&) = delete;
	void operator=(const SceneManager&) = delete;

	std::unique_ptr<TitleScene> m_title_scene;
	std::unique_ptr<Explanation> m_explanation_scene;
	std::unique_ptr<RuleScene> m_rule_scene;
	std::unique_ptr<MainScene> m_main_scene;

	int m_SceneNumber;
};