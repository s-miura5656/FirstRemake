#include "CharaBase.h"

/* �A�Ԃ̃A�j���[�V����
* @param animation_time = �A�Ԃ�ς���Ԋu
* @param animation_image_param = �A�j���[�V�������������摜�̃p�����[�^�[
* @@aram division_number = �A�Ԃ̕�����
*/
void CharaBase::PlayAnimation(float& animation_time, ImagePram& animation_image_param)
{
	m_count++;

	/// �A�j���[�V���������鎞��
	if (m_count > m_one_second * animation_time)
	{
		m_count = 0;
	}

	/// �A�Ԃ̉摜�̒[�܂ł������烊�Z�b�g
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

