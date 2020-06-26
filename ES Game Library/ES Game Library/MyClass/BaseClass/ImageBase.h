#pragma once

#include "../../ESGLib.h"
#include "Constant.h"

struct ImageParam
{
	SPRITE image;		         // �摜�f�[�^
	Vector2 image_size;          // �摜�T�C�Y
	Vector2 image_division_size; // �A�Ԃ̂P�R�}�̃T�C�Y
	Vector3 pos;		         // ���W
	Rect rect;		             // �摜�̎g�p�͈�
	float alpha;		         // �摜�̃A���t�@�l
	Vector3 rotation;	         // �摜�̉�]
	Vector3 center;		         // �摜�̒��S
	float image_scale;	         // �摜�̕\���{��
	
	ImageParam() {
		image_scale = 1.f;
		alpha = ALPHA_MAX;
		rotation = Vector3_Zero;
		center = Vector3_Zero;
		rect = Rect(0, 0, 0, 0);
		image_size = Vector2_Zero;
	};

	/*
	* �A�Ԃ̂P�R�}�̃T�C�Y���o��
	* @param division_number = �A�Ԃ̕�����
	*/
	void ImageDivisionSize(Vector2 division_number) {
		image_division_size.x = image_size.x / division_number.x;
		image_division_size.y = image_size.y / division_number.y;
	}
};

class ImageBase
{
public:
	ImageBase() {};
	~ImageBase() {};

private:

};

class RectEX : public Rect
{
public:
	RectEX() {};
	~RectEX() {};
	
	Rect MoveRectX(ImageParam& param);
	Rect MoveRectY(ImageParam& param);
	void FlashImage(ImageParam& param, float alpha_value);
	float AlphaPerSecond(float time);
private:
	bool alpha_flag = false;
	float alpha_value;
};