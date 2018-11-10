#pragma once
#include "Etypes.h"

class Camera;

class ProcessInput
{
private:
	static float m_cSpeed;
	static float m_lastXpos;
	static float m_lastYpos;
	static float m_xOffset;
	static float m_yOffset;
	static float m_mSpeed;
	static float m_yValue;
	static float m_pValue;
	static bool  m_aJump;

public:
	static void FrameBufferCallback(PLATFORM_WINDOW window, const int sWidth, const int sHeight);
	static void KeyboardMouseController(PLATFORM_WINDOW window, Camera& camera);
	static void MouseCallback(PLATFORM_WINDOW window, double x, double y);
	static bool WindowStateController(PLATFORM_WINDOW window);

	~ProcessInput() = delete;
	ProcessInput() = delete;
};

 