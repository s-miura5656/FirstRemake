#pragma once

#include "../../ESGLib.h"

//! ��ʏ�
#define SCREEN_TOP 0
//! ��ʉ�
#define SCREEN_BOTTOM -720
//! ��ʍ�
#define SCREEN_LEFT 0
//! ��ʉE
#define SCREEN_RIGHT 1280

//! �A�j���[�V����������b��
#define ANIMATION_TIME 1.f

//! ��]�̏����ʒu
#define ROTATION_DEFAULT 0.f
//! Y�����]
#define ROTATION_Y_INVERSION 180.f

//! �A���t�@�l�ő�
#define ALPHA_MAX 1.f

//! �A���t�@�l��
#define ALPHA_ZERO 0.f

//! �摜�T�C�Y 1280 * 720
#define IMAGE_SIZE_SCREEN Rect(0, 0, 1280, 720)

//! �ړ��͈͐����@��
#define LIMIT_SCOPE_UP 0

//! �ړ��͈͐����@��
#define LIMIT_SCOPE_DOWN -1440

//! �ړ��͈͐����@�E
#define LIMIT_SCOPE_RIGHT 0

//! �ړ��͈͐����@��
#define LIMIT_SCOPE_LEFT -1280

//! ���ړ��̐����i�E�j
#define BOAR_MOVE_LIMIT_RIGHT 2860

//! ���ړ��̐����i���j
#define BOAR_MOVE_LIMIT_LEFT -300
