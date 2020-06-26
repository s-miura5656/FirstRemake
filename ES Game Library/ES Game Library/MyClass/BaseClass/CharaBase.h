#pragma once

#include "../../ESGLib.h"
#include "ImageBase.h"


class CharaBase : public RectEX
{
public:
	CharaBase() {};
	~CharaBase() { };

	void Draw2D();
	void Draw2D(ImageParam& image_param);

protected:
	void PlayAnimation(float& animation_time, ImageParam& animation_image_param);

	ImageParam img_param;

private:
	float m_count = 0;
	const float m_one_second = 60;
};