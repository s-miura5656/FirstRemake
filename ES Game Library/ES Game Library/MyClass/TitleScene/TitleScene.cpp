#include "TitleScene.h"
#include "../Controller/Controller.h"
#include "../BaseClass/Constant.h"

void TitleScene::Initialize()
{
	m_img_param.resize(TitleImageNum::Title_NUM_MAX);
	
	// タイトル背景
	m_img_param[TitleImageNum::Title_Logo].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/title.png"));
	m_img_param[TitleImageNum::Title_Logo].pos = Vector3_Zero;
	m_img_param[TitleImageNum::Title_Logo].rect = RectWH(0, 0, m_img_param[TitleImageNum::Title_Logo].image->GetWidth(), 
															m_img_param[TitleImageNum::Title_Logo].image->GetHeight());
	
	// タイトル雲１
	m_img_param[TitleImageNum::Title_Cloud_One].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/cloud.png"));
	m_img_param[TitleImageNum::Title_Cloud_One].pos = Vector3(0, 0, -10);
	m_img_param[TitleImageNum::Title_Cloud_One].rect = RectWH(0, 0, m_img_param[TitleImageNum::Title_Cloud_One].image->GetWidth(),
																 m_img_param[TitleImageNum::Title_Cloud_One].image->GetHeight());
	
	// タイトル雲２
	m_img_param[TitleImageNum::Title_Cloud_Two].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/cloud.png"));
	m_img_param[TitleImageNum::Title_Cloud_Two].pos = m_img_param[TitleImageNum::Title_Cloud_Two].pos + Vector3(1280, 0, 0);
	m_img_param[TitleImageNum::Title_Cloud_Two].rect = RectWH(0, 0, m_img_param[TitleImageNum::Title_Cloud_Two].image->GetWidth(),
																 m_img_param[TitleImageNum::Title_Cloud_Two].image->GetHeight());
	
	// タイトル猪
	m_img_param[TitleImageNum::Title_Enemy].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/boar.png"));
	m_img_param[TitleImageNum::Title_Enemy].pos = Vector3(1280, 440, -100);
	m_img_param[TitleImageNum::Title_Enemy].rect = RectWH(0, 0, m_enemy_image_rect.x, m_enemy_image_rect.y);
	m_img_param[TitleImageNum::Title_Enemy].division_number = 2;
	
	// タイトルスタート
	m_img_param[TitleImageNum::Title_Start_Logo].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/click.png"));
	m_img_param[TitleImageNum::Title_Start_Logo].pos = Vector3(490, 380, -100);
	m_img_param[TitleImageNum::Title_Start_Logo].rect = RectWH(0, 0, m_img_param[TitleImageNum::Title_Start_Logo].image->GetWidth(),
															m_img_param[TitleImageNum::Title_Start_Logo].image->GetHeight());
}

void TitleScene::Update()
{
	MoveCloud(TitleImageNum::Title_Cloud_One);
	MoveCloud(TitleImageNum::Title_Cloud_Two);
	MoveEnemy();
}

void TitleScene::Draw2D()
{
	for (auto&& image : m_img_param)
	{
		CharaBase::Draw2D(image);
	}
}

/** 画像を動かす
* @param pos = 動かす画像の座標
* @param move_value = 移動値
*/
void TitleScene::MoveImage(Vector3& pos, Vector3& move_value)
{
	pos.x += move_value.x;
	pos.y += move_value.y;
	pos.z += move_value.z;
}

/*
* 猪の移動
*/
void TitleScene::MoveEnemy()
{
	MoveImage(m_img_param[TitleImageNum::Title_Enemy].pos, m_enemy_move_value);
	CharaBase::PlayAnimation(m_boar_animation_time, m_img_param[TitleImageNum::Title_Enemy]);

	// true = 左移動  false = 右移動
	m_enemy_move_value.x = m_enemy_image_inversion_flag ? -m_move_value : m_move_value;

	// 猪が画面右へ消えたら左へ反転
	if (m_img_param[TitleImageNum::Title_Enemy].pos.x > SCREEN_RIGHT + m_img_param[TitleImageNum::Title_Enemy].image->GetWidth() / 2)
	{
		m_enemy_image_inversion_flag = true;
		m_img_param[TitleImageNum::Title_Enemy].rotation.y = ROTATION_DEFAULT;
	}

	// 猪が画面左へ消えたら右へ反転
	if (m_img_param[TitleImageNum::Title_Enemy].pos.x < SCREEN_LEFT - m_img_param[TitleImageNum::Title_Enemy].image->GetWidth() / 2)
	{
		m_enemy_image_inversion_flag = false;
		m_img_param[TitleImageNum::Title_Enemy].rotation.y = ROTATION_Y_INVERSION;
	}
}

/*
* 背景の雲の移動
* @param cloud_num = 雲画像の番号
*/
void TitleScene::MoveCloud(int cloud_num)
{
	MoveImage(m_img_param[cloud_num].pos, m_cloud_move_value);

	if (m_img_param[cloud_num].pos.x > m_img_param[cloud_num].image->GetWidth())
		return;

	//! 画像が１の場合２の後ろへ移動
	if (cloud_num == TitleImageNum::Title_Cloud_One)
	{
		m_img_param[cloud_num].pos.x = m_img_param[TitleImageNum::Title_Cloud_Two].pos.x + 
									   m_img_param[TitleImageNum::Title_Cloud_Two].image->GetWidth();
		return;
	}

	//! 画像１の後ろへ移動
	m_img_param[cloud_num].pos.x = m_img_param[TitleImageNum::Title_Cloud_One].pos.x +
								   m_img_param[TitleImageNum::Title_Cloud_One].image->GetWidth();
}


