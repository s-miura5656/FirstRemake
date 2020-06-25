#pragma once

#include "../../ESGLib.h"
#include "ImageBase.h"


class CharaBase
{
public:
	CharaBase() { rect_ex = img_param; };
	~CharaBase() { };

	void Draw2D();
	void Draw2D(ImagePram& image_param);

protected:
	void PlayAnimation(float& animation_time, ImagePram& animation_image_param);

	ImagePram img_param;

private:
	RectEX rect_ex;
	float m_count = 0;
	const float m_one_second = 60;
};