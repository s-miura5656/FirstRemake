#include "DebugManager.h"

void DebugManager::DrawDebugText(float value_to_display, Vector2 pos, Color color)
{
#if _DEBUG
	SpriteBatch.DrawString(DefaultFont, pos, color, _T("%f"), value_to_display);
#endif // _DEBUG
}

void DebugManager::DrawDebugText(int value_to_display, Vector2 pos, Color color)
{
#if _DEBUG
	SpriteBatch.DrawString(DefaultFont, pos, color, _T("%d"), value_to_display);
#endif // _DEBUG
}

void DebugManager::DrawDebugText(Vector3& value_to_display, Vector2 pos, Color color)
{
#if _DEBUG
	SpriteBatch.DrawString(DefaultFont, pos + Vector2(0, 0), color, _T("X %f"), value_to_display.x);
	SpriteBatch.DrawString(DefaultFont, pos + Vector2(0, 20), color, _T("Y %f"), value_to_display.y);
	SpriteBatch.DrawString(DefaultFont, pos + Vector2(0, 40), color, _T("Z %f"), value_to_display.z);
#endif // _DEBUG
}

void DebugManager::DrawDebugText(Rect& value_to_display, Vector2 pos, Color color)
{
#if _DEBUG
	SpriteBatch.DrawString(DefaultFont, pos + Vector2(0,  0), color, _T("Rect_Left %d"), value_to_display.left);
	SpriteBatch.DrawString(DefaultFont, pos + Vector2(0, 20), color, _T("Rect_Top %d"), value_to_display.top);
	SpriteBatch.DrawString(DefaultFont, pos + Vector2(0, 40), color, _T("Rect_Right %d"), value_to_display.right);
	SpriteBatch.DrawString(DefaultFont, pos + Vector2(0, 60), color, _T("Rect_Bottom %d"), value_to_display.bottom);
#endif // _DEBUG
}
