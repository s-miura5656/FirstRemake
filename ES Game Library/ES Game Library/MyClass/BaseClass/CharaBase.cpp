#include "CharaBase.h"
#include "../SoundManager/SoundManager.h"
#include "../Controller/Controller.h"
#include "../SceneManager/SceneManager.h"

/* �A�Ԃ̃A�j���[�V����
* @param animation_time = �A�Ԃ�ς���Ԋu
* @param animation_image_param = �A�j���[�V�������������摜�̃p�����[�^�[
* @param division_number = �A�Ԃ̕�����
*/
void CharaBase::PlayAnimation(float& animation_time, ImageParam& animation_image_param)
{
	m_count++;

	/// �A�j���[�V���������鎞��
	if (m_count > m_one_second * animation_time)
	{
		animation_image_param.rect = RectEX::MoveRectX(animation_image_param);
		m_count = 0;
	}
}

/*
* ���N���b�N����������V�[���J��
* @param scene_num = �V�[���ԍ�
* @param se_num = �V�X�e�����ԍ�
*/
void CharaBase::ChangeScene(int scene_num, int se_num)
{
	if (SoundManager::Instance().GetSE(se_num)->IsPlaying())
		return;

	//! �}�E�X�̍��N���b�N���������玟�֑J��
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



