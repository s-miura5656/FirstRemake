#pragma once

#include "../../ESGLib.h"

struct ImagePram
{
	SPRITE image;		 // 画像データ
	Vector3 pos;		 // 座標
	Rect rect;		     // 画像の使用範囲
	float alpha;		 // 画像のアルファ値
	Vector3 rotation;	 // 画像の回転
	Vector3 center;		 // 画像の中心
	float size;			 // 画像のサイズ
	int division_number; // 連番の数
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