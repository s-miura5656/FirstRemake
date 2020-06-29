#pragma once

#include"../BaseClass/CharaBase.h"

class RuleScene : public CharaBase
{
public:
	RuleScene() {};
	~RuleScene() {};

	void FileInitialize();
	void Initialize();
	void Update();
	void Draw2D();
	void Draw3D() {};

private:
	ImageParam m_img_param;
};