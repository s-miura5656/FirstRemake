#include "ImageBase.h"

/*
* 連番画像のX方向を変える
* @param param = 画像のパラメーター
*/
Rect RectEX::MoveRectX(ImageParam& param)
{
	param.rect.left = param.rect.right;
	param.rect.right = param.rect.left + param.image_division_size.x;

	//! 画像の端まで行ったら戻る
	if (param.rect.left >= param.image_size.x)
	{
		param.rect.left = 0;
		param.rect.right = param.rect.left + param.image_division_size.x;
	}

	return param.rect;
}

/*
* 連番画像のY方向を変える
* @param param = 画像のパラメーター
*/
Rect RectEX::MoveRectY(ImageParam& param)
{
	param.rect.top = param.rect.bottom;
	param.rect.bottom = param.rect.top + param.image_division_size.y;

	//! 画像の端まで行ったら戻る
	if (param.rect.top >= param.image_size.y)
	{
		param.rect.top = 0;
		param.rect.bottom = param.rect.top + param.image_division_size.y;
	}

	return param.rect;
}

/*
* 画像の点滅
* @param param = 画像のパラメーター
: @param alpha_value = 画像をのAlphaの増減値
*/
void RectEX::FlashImage(ImageParam& param, float alpha_value)
{
	//! true = 不透明にしていく false = 透明にしていく
	param.alpha = alpha_flag ? param.alpha + alpha_value : param.alpha - alpha_value;

	if (param.alpha >= ALPHA_MAX)
	{
		alpha_flag = false;
		param.alpha = ALPHA_MAX;
	}

	if (param.alpha <= ALPHA_ZERO)
	{
		alpha_flag = true;
		param.alpha = ALPHA_ZERO;
	}
}
	

/*
* 秒数で点滅させたいときにAlpha値を計算する
* １点滅を何秒でさせるか
* @param time = 点滅間隔（秒数） 
*/
float RectEX::AlphaPerSecond(float time)
{
	//! HACK:１点滅を何秒でするかの計算
	float alpha = (1.f * 2) / (60.f * time);
	
	return alpha;
}
