#pragma once

#include"../BaseClass/CharaBase.h" 

class Explanation : public CharaBase
{
public:
	Explanation() {};
	~Explanation() {};

	void FileInitialize();
	void Initialize();
	void Update();
	void Draw2D();
	void Draw3D() {};

private:
	ImageParam m_img_param;
};