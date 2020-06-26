#include "CharaBase.h"
#include "../SoundManager/SoundManager.h"
#include "../Controller/Controller.h"
#include "../SceneManager/SceneManager.h"

/* 連番のアニメーション
* @param animation_time = 連番を変える間隔
* @param animation_image_param = アニメーションさせたい画像のパラメーター
* @param division_number = 連番の分割数
*/
void CharaBase::PlayAnimation(float& animation_time, ImageParam& animation_image_param)
{
	m_count++;

	/// アニメーションさせる時間
	if (m_count > m_one_second * animation_time)
	{
		animation_image_param.rect = RectEX::MoveRectX(animation_image_param);
		m_count = 0;
	}
}

/*
* 左クリックを押したらシーン遷移
* @param scene_num = シーン番号
* @param se_num = システム音番号
*/
void CharaBase::ChangeScene(int scene_num, int se_num)
{
	if (SoundManager::Instance().GetSE(se_num)->IsPlaying())
		return;

	//! マウスの左クリックを押したら次へ遷移
	if (Controller::Instance().GetMouseBuffer().IsPressed(Mouse_Button1))
	{
		SoundManager::Instance().SEPlay(se_num);
		SceneManager::Instance().SetSceneNumber(scene_num);
	}
}

void CharaBase::Draw2D()
{
	SpriteBatch.Draw(*img_param.image, img_param.pos, img_param.rect, img_param.alpha, img_param.rotation, img_param.center, img_param.image_scale);
}

void CharaBase::Draw2D(ImageParam& image_param)
{
	SpriteBatch.Draw(*image_param.image,    
					  image_param.pos, 	    
					  image_param.rect,     
					  image_param.alpha,    
					  image_param.rotation, 
					  image_param.center,   
					  image_param.image_scale);   
}



