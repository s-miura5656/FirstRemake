#pragma once

#include "../../ESGLib.h"

class DebugManager
{
public:
	~DebugManager() {};

	void DrawDebugText(float value_to_display, Vector2 pos, Color color);
	void DrawDebugText(int value_to_display, Vector2 pos, Color color);
	void DrawDebugText(Vector3& value_to_display, Vector2 pos, Color color);
	void DrawDebugText(Rect& value_to_display, Vector2 pos, Color color);

	static DebugManager& Instance() {
		static DebugManager instance;
		return instance;
	}

private:
	DebugManager() : DefaultFont(GraphicsDevice.CreateDefaultFont()) {};
	DebugManager(const DebugManager&) = delete;
	void operator=(const DebugManager&) = delete;


	FONT DefaultFont;
};