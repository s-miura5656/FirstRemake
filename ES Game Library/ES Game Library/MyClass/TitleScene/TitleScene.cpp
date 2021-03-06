#include "TitleScene.h"
#include "../Controller/Controller.h"
#include "../DebugManager/DebugManager.h"
#include "../SceneManager/SceneManager.h"

void TitleScene::FileInitialize()
{
	m_img_param.resize(TitleImageNum::Title_NUM_MAX);
	m_img_param[TitleImageNum::Logo].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/title.png"));
	m_img_param[TitleImageNum::Cloud_One].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/cloud.png"));
	m_img_param[TitleImageNum::Cloud_Two].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/cloud.png"));
	m_img_param[TitleImageNum::Enemy].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/boar.png"));
	m_img_param[TitleImageNum::Start_Logo].image = GraphicsDevice.CreateSpriteFromFile(_T("Title/click.png"));
}

void TitleScene::Initialize()
{
	//! タイトル背景
	m_img_param[TitleImageNum::Logo].pos = Vector3_Zero;
	m_img_param[TitleImageNum::Logo].rect = IMAGE_SIZE_SCREEN;
	
	//! タイトル雲１
	m_img_param[TitleImageNum::Cloud_One].pos = Vector3(0, 0, -10);
	m_img_param[TitleImageNum::Cloud_One].rect = IMAGE_SIZE_SCREEN;

	//! タイトル雲２
	m_img_param[TitleImageNum::Cloud_Two].pos = m_img_param[TitleImageNum::Cloud_Two].pos + Vector3(1280, 0, 0);
	m_img_param[TitleImageNum::Cloud_Two].rect = IMAGE_SIZE_SCREEN;
	
	//! タイトル猪
	m_img_param[TitleImageNum::Enemy].pos = Vector3(1280, 440, -100);
	m_img_param[TitleImageNum::Enemy].rect = Rect(0, 0, m_enemy_image_rect.x, m_enemy_image_rect.y);
	m_img_param[TitleImageNum::Enemy].image_size = Vector2(600, 200);
	m_img_param[TitleImageNum::Enemy].ImageDivisionSize(Vector2(2, 1));
	
	//! タイトルスタート
	m_img_param[TitleImageNum::Start_Logo].pos = Vector3(490, 380, -100);
	m_img_param[TitleImageNum::Start_Logo].rect = IMAGE_SIZE_SCREEN;

	start_alpha_value = CharaBase::AlphaPerSecond(2.f);
	start_flash_flag = false;
}

void TitleScene::Update()
{
	PushStartButton();
	MoveCloud(TitleImageNum::Cloud_One);
	MoveCloud(TitleImageNum::Cloud_Two);
	MoveEnemy();
}

void TitleScene::Draw2D()
{
	for (auto&& image : m_img_param)
	{
		CharaBase::Draw2D(image);
	}

	//DebugManager::Instance().DrawDebugText(m_img_param[TitleImageNum::Start_Logo].alpha, Vector2_Zero, Color_Red);
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
	MoveImage(m_img_param[TitleImageNum::Enemy].pos, m_enemy_move_value);
	CharaBase::PlayAnimation(m_boar_animation_time, m_img_param[TitleImageNum::Enemy]);

	// true = 左移動  false = 右移動
	m_enemy_move_value.x = m_enemy_image_inversion_flag ? -m_move_value : m_move_value;

	// 猪が画面右へ消えたら左へ反転
	if (m_img_param[TitleImageNum::Enemy].pos.x > SCREEN_RIGHT + m_img_param[TitleImageNum::Enemy].image_division_size.x)
	{
		m_enemy_image_inversion_flag = true;
		m_img_param[TitleImageNum::Enemy].rotation.y = ROTATION_DEFAULT;
	}

	// 猪が画面左へ消えたら右へ反転
	if (m_img_param[TitleImageNum::Enemy].pos.x < SCREEN_LEFT - m_img_param[TitleImageNum::Enemy].image_division_size.x)
	{
		m_enemy_image_inversion_flag = false;
		m_img_param[TitleImageNum::Enemy].rotation.y = ROTATION_Y_INVERSION;
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
	if (cloud_num == TitleImageNum::Cloud_One)
	{
		m_img_param[cloud_num].pos.x = m_img_param[TitleImageNum::Cloud_Two].pos.x + 
									   m_img_param[TitleImageNum::Cloud_Two].image->GetWidth();
		return;
	}

	//! 画像１の後ろへ移動
	m_img_param[cloud_num].pos.x = m_img_param[TitleImageNum::Cloud_One].pos.x +
								   m_img_param[TitleImageNum::Cloud_One].image->GetWidth();
}

void TitleScene::PushStartButton()
{
	CharaBase::FlashImage(m_img_param[TitleImageNum::Start_Logo], start_alpha_value);

	if (SoundManager::Instance().GetSE(SE_Num::Start)->IsPlaying())
		return;

	//! マウスの左クリックを押したら次へ遷移
	if (Controller::Instance().GetMouseBuffer().IsPressed(Mouse_Button1))
	{
		SoundManager::Instance().SEPlay(SE_Num::Start);
		start_alpha_value = CharaBase::AlphaPerSecond(0.3f);
		SceneManager::Instance().SetSceneNumber(SceneNum::Scene_Explanation);
	}

}


