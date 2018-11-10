#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Etypes.h" 
#include "Shader.h"
#include "ProcessInput.h"
#include "VertexBuffer.h"

//C language
namespace platform
{
	void PlatformInit();
	PLATFORM_WINDOW CreatePlatformWindow(const int w, const int h, const char *const t, const bool fsMode, const PLATFORM_WINDOW window, const int cMajor, const int cMinor, const char *const p);
	void PlatformGLContextVersion(const int cMajor, const int cMinor, const char* const p);
	bool LoadPlatform3DLib();

	void SetPlatformViewPort();
    void PollPlatformWindow();
	void PresentPlatformWindow();
	void EnableInputMode();
	//inline  GLFWwindow* ReturnWindow() const { return m_Window; };
	//inline bool ReturnCurrentContextStatus() { return m_CurrentContextFlag; };
	void TerminatePlatform();  
 
}

 