#pragma once

#include "../../ESGLib.h"
#include "../TitleScene/TitleScene.h"

enum SceneNum
{
	Scene_Title,
	Scene_Main,
	Scene_Result,
}; 

class SceneManager
{
public:
	~SceneManager() 
	{
		title_scene.reset();
	};

	void Initialize();
	void Update();
	void Draw3D();
	void Draw2D();

	static SceneManager& Instance() {
		static SceneManager instance;
		return instance;
	};

private:
	SceneManager() {
		SceneNumber = SceneNum::Scene_Title;
		title_scene.reset(new TitleScene);
	};
	SceneManager(const SceneManager&) = delete;
	void operator=(const SceneManager&) = delete;

	std::shared_ptr<TitleScene> title_scene;

	int SceneNumber;
};