#pragma once

#include "../SoundManager/SoundManager.h"
#include "../BaseClass/Constant.h"
#include "../BaseClass/CharaBase.h"

enum TitleImageNum
{
	Title_Logo,
	Title_Cloud_One,
	Title_Cloud_Two,
	Title_Enemy,
	Title_Start_Logo,
	Title_NUM_MAX
};

class TitleScene : public CharaBase
{
public:
	TitleScene() { SoundManager::Instance().BGMPlay(BGM_Num::Title); };
	~TitleScene() {};

	void FileInitialize();
	void Initialize();
	void Update();
	void Draw2D();
	void Draw3D() {};
	
	void MoveImage(Vector3& pos, Vector3& move_value);
	void MoveEnemy();
	void MoveCloud(int cloud_num);
	void PushStartButton();

private:
	std::vector<ImageParam> m_img_param;

	float start_alpha_value;
	bool start_flash_flag;

	bool m_enemy_image_inversion_flag = true;
	float m_boar_animation_time = 0.5f;
	// à⁄ìÆílÅiÇ«ÇÃà ìÆÇ©Ç∑Ç©Åj
	const float m_move_value = 5.f;
	Vector3 m_cloud_move_value = Vector3(-0.1f, 0, 0);
	Vector3 m_enemy_move_value = Vector3_Zero;
	const Vector2 m_enemy_image_rect = Vector2(300, 200);
};