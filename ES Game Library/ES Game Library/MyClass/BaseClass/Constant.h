#pragma once

#include "../../ESGLib.h"

//! 画面上
#define SCREEN_TOP 0
//! 画面下
#define SCREEN_BOTTOM -720
//! 画面左
#define SCREEN_LEFT 0
//! 画面右
#define SCREEN_RIGHT 1280

//! アニメーションさせる秒数
#define ANIMATION_TIME 1.f

//! 回転の初期位置
#define ROTATION_DEFAULT 0.f
//! Y軸反転
#define ROTATION_Y_INVERSION 180.f

//! アルファ値最大
#define ALPHA_MAX 1.f

//! アルファ値無
#define ALPHA_ZERO 0.f

//! 画像サイズ 1280 * 720
#define IMAGE_SIZE_SCREEN Rect(0, 0, 1280, 720)

//! 移動範囲制限　上
#define LIMIT_SCOPE_UP 0

//! 移動範囲制限　下
#define LIMIT_SCOPE_DOWN -1440

//! 移動範囲制限　右
#define LIMIT_SCOPE_RIGHT 0

//! 移動範囲制限　左
#define LIMIT_SCOPE_LEFT -1280

//! 猪移動の制限（右）
#define BOAR_MOVE_LIMIT_RIGHT 2860

//! 猪移動の制限（左）
#define BOAR_MOVE_LIMIT_LEFT -300
