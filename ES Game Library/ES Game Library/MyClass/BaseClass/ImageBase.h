#pragma once

#include "../../ESGLib.h"
#include "Constant.h"

struct ImageParam
{
	SPRITE image;		         // 画像データ
	Vector2 image_size;          // 画像サイズ
	Vector2 image_division_size; // 連番の１コマのサイズ
	Vector3 pos;		         // 座標
	Rect rect;		             // 画像の使用範囲
	float alpha;		         // 画像のアルファ値
	Vector3 rotation;	         // 画像の回転
	Vector3 center;		         // 画像の中心
	float image_scale;	         // 画像の表示倍率
	
	ImageParam() {
		image_scale = 1.f;
		alpha = ALPHA_MAX;
		rotation = Vector3_Zero;
		center = Vector3_Zero;
		rect = Rect(0, 0, 0, 0);
		image_size = Vector2_Zero;
	};

	/*
	* 連番の１コマのサイズを出す
	* @param division_number = 連番の分割数
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