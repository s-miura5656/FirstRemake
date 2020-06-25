#pragma once

#include "../../ESGLib.h"

struct ImagePram
{
	SPRITE image;		 // �摜�f�[�^
	Vector3 pos;		 // ���W
	Rect rect;		     // �摜�̎g�p�͈�
	float alpha;		 // �摜�̃A���t�@�l
	Vector3 rotation;	 // �摜�̉�]
	Vector3 center;		 // �摜�̒��S
	float size;			 // �摜�̃T�C�Y
	int division_number; // �A�Ԃ̐�
	ImagePram() {
		size = 1.f;
		alpha = 1.f;
		rotation = Vector3_Zero;
		center = Vector3_Zero;
		rect = RectWH(0, 0, 0, 0);
		division_number = 1;
	};
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
	
	void SetRect(Rect& rect) { m_rect = rect; };

	Rect MoveRectX() {
		m_rect.left = m_rect.right;
		m_rect.right += m_rect.right;
		return m_rect;
	};

private:
	Rect m_rect;
};