#include "Player.h"
#include "../Controller/Controller.h"
#include "../DebugManager/DebugManager.h"
#include "../SceneManager/SceneManager.h"
#include "../SoundManager/SoundManager.h"


void Player::FileInitialize()
{
	m_img_param.resize(Player_NUM_MAX);
	m_img_param[PlayerNum::Scope].image = GraphicsDevice.CreateSpriteFromFile(_T("Player/Scope.png"));
	m_img_param[PlayerNum::Field].image = GraphicsDevice.CreateSpriteFromFile(_T("Player/field.png"));
}

void Player::Initialize()
{
	m_img_param[PlayerNum::Scope].pos = Vector3(0, 0, -1000);
	m_img_param[PlayerNum::Scope].rect = IMAGE_SIZE_SCREEN;

	m_img_param[PlayerNum::Field].pos = Vector3(-640, -540, 1000);
	m_img_param[PlayerNum::Field].rect = Rect(0, 0, 2560, 2160);

	SetCursorPos(800, 450);
}

void Player::Update()
{
	MoveScope();
	LimitedRangeOfMovement();
}

void Player::Draw2D()
{
	for (auto&& image : m_img_param)
	{
		CharaBase::Draw2D(image);
	}

	DebugManager::Instance().DrawDebugText(m_img_param[PlayerNum::Field].pos, Vector2(0,  0), Color_White);
}

void Player::MoveScope()
{
	MouseState state = Controller::Instance().GetMouseState();
	
	m_img_param[PlayerNum::Field].pos.x -= state.X;
	m_img_param[PlayerNum::Field].pos.y -= state.Y;
}

/*
* スコープの移動範囲制限
*/
void Player::LimitedRangeOfMovement()
{
	if (m_img_param[PlayerNum::Field].pos.x < LIMIT_SCOPE_LEFT)
		m_img_param[PlayerNum::Field].pos.x = LIMIT_SCOPE_LEFT;

	if (m_img_param[PlayerNum::Field].pos.x > LIMIT_SCOPE_RIGHT)
		m_img_param[PlayerNum::Field].pos.x = LIMIT_SCOPE_RIGHT;

	if (m_img_param[PlayerNum::Field].pos.y > LIMIT_SCOPE_UP)
		m_img_param[PlayerNum::Field].pos.y = LIMIT_SCOPE_UP;

	if (m_img_param[PlayerNum::Field].pos.y < LIMIT_SCOPE_DOWN)
		m_img_param[PlayerNum::Field].pos.y = LIMIT_SCOPE_DOWN;
}
