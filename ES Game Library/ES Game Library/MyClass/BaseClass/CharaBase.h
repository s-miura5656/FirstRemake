#pragma once

#include "../../ESGLib.h"
#include "ImageBase.h"


class CharaBase : public RectEX
{
public:
	CharaBase() {};
	~CharaBase() { };

	virtual void Draw2D();
	virtual void Draw2D(ImageParam& image_param);

	void ChangeScene(int scene_num, int se_num);
protected:
	void PlayAnimation(float& animation_time, ImageParam& animation_image_param);

	ImageParam img_param;

private:
	float m_count = 0;
	const float m_one_second = 60;
};