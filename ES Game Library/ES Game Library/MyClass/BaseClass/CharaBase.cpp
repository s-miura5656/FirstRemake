#include "CharaBase.h"

/* 連番のアニメーション
* @param animation_time = 連番を変える間隔
* @param animation_image_param = アニメーションさせたい画像のパラメーター
* @@aram division_number = 連番の分割数
*/
void CharaBase::PlayAnimation(float& animation_time, ImagePram& animation_image_param)
{
	m_count++;

	/// アニメーションさせる時間
	if (m_count > m_one_second * animation_time)
	{
		m_count = 0;
	}

	/// 連番の画像の端までいったらリセット
	if (animation_image_param.rect.left <= animation_image_param.image->GetWidth())
		return;

	animation_image_param.rect.left = 0;
}

void CharaBase::Draw2D()
{
	SpriteBatch.Draw(*img_param.image, img_param.pos, img_param.rect, img_param.alpha, img_param.rotation, img_param.center, img_param.alpha);
}

void CharaBase::Draw2D(ImagePram& image_param)
{
	SpriteBatch.Draw(*image_param.image,    
					  image_param.pos, 	    
					  image_param.rect,     
					  image_param.alpha,    
					  image_param.rotation, 
					  image_param.center,   
					  image_param.alpha);   
}

