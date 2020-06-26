#include "ImageBase.h"

/*
* �A�ԉ摜��X������ς���
* @param param = �摜�̃p�����[�^�[
*/
Rect RectEX::MoveRectX(ImageParam& param)
{
	param.rect.left = param.rect.right;
	param.rect.right = param.rect.left + param.image_division_size.x;

	//! �摜�̒[�܂ōs������߂�
	if (param.rect.left >= param.image_size.x)
	{
		param.rect.left = 0;
		param.rect.right = param.rect.left + param.image_division_size.x;
	}

	return param.rect;
}

/*
* �A�ԉ摜��Y������ς���
* @param param = �摜�̃p�����[�^�[
*/
Rect RectEX::MoveRectY(ImageParam& param)
{
	param.rect.top = param.rect.bottom;
	param.rect.bottom = param.rect.top + param.image_division_size.y;

	//! �摜�̒[�܂ōs������߂�
	if (param.rect.top >= param.image_size.y)
	{
		param.rect.top = 0;
		param.rect.bottom = param.rect.top + param.image_division_size.y;
	}

	return param.rect;
}

/*
* �摜�̓_��
* @param param = �摜�̃p�����[�^�[
: @param alpha_value = �摜����Alpha�̑����l
*/
void RectEX::FlashImage(ImageParam& param, float alpha_value)
{
	//! true = �s�����ɂ��Ă��� false = �����ɂ��Ă���
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
* �b���œ_�ł��������Ƃ���Alpha�l���v�Z����
* �P�_�ł����b�ł����邩
* @param time = �_�ŊԊu�i�b���j 
*/
float RectEX::AlphaPerSecond(float time)
{
	//! HACK:�P�_�ł����b�ł��邩�̌v�Z
	float alpha = (1.f * 2) / (60.f * time);
	
	return alpha;
}
