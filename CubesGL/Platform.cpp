#include "Platform.h"

#include <iostream>
#include <string>

namespace platform
{
	static PLATFORM_WINDOW s_window = 0;
	static PLATFORM_WINDOW s_sharWindow = 0;
	static PLATFORM_MONITOR s_monitor = 0;
	static float s_width = 0;
	static float s_height = 0;
	static unsigned int s_cMajor = 0;
	static unsigned int s_cMinor = 0;
	static unsigned int s_profile = 0;

	bool m_CurrentContextFlag = false;
	static bool m_gladFlag = false;

	static void PlatformInit() 
	{
		glfwInit();
	}

	PLATFORM_WINDOW CreatePlatformWindow(const int w, const int h, const char *const t, const bool fsMode, PLATFORM_WINDOW window, const int cMajor, const int cMinor, const char *const p)
	{
		PlatformInit();
		s_window = glfwCreateWindow(w, h, t, (PLATFORM_MONITOR)(fsMode == TRUE ? s_monitor = glfwGetPrimaryMonitor() : FALSE), (window == NULL ? NULL : s_sharWindow = window));
		s_width = static_cast<float>(w);
		s_height = static_cast<float>(h);
		PlatformGLContextVersion(cMajor, cMinor, p);
		LoadPlatform3DLib();
		if (m_gladFlag)
			SetPlatformViewPort();
		return  s_window;
	}

	static bool LoadPlatform3DLib()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cerr << "LOG::GLAD::ERROR::GLAD HAS NOT BEEN INCLUDED SUCCESSFULLY::" << std::endl;
			m_gladFlag = false;
			return false;
		}
		else
		{
			std::cout << "LOG::GLAD::INFO::GLAD HAS BEEN INCLUDED SUCCESSFULLY::" << std::endl;
			m_gladFlag = true;
			return true;
		}
	}

	static void PlatformGLContextVersion(const int cMajor, const int cMinor, const char* const p)
	{
		s_cMajor = cMajor; 
		s_cMinor = cMinor; 

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, s_cMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, s_cMinor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, (p == "CORE" ? s_profile = GLFW_OPENGL_CORE_PROFILE : s_profile = GLFW_OPENGL_COMPAT_PROFILE));
		std::cout << "LOG::GLFW:: CREATED CONTEXT_VERSION::" << s_cMajor << "." << s_cMinor << std::endl;
		std::cout << "LOG::GLFW:: PROFILE::" << (s_profile == GLFW_OPENGL_CORE_PROFILE ? "GLFW_OPENGL_CORE_PROFILE" : "GLFW_OPENGL_COMPAT_PROFILE" )<< std::endl;

		if (s_window == NULL)
		{
			std::cerr << "LOG::CONTEXT_GL::GLFW::ERROR:: WINDOW CREATION HAS BEEN FAILED::" << std::endl;
			glfwTerminate();
		}
		else
		{
			std::cout << "LOG::CONTEXT_GL::GLFW:: WINDOW HAS BEEN CREATED SUCCESSFULLY::" << std::endl;
			glfwMakeContextCurrent(s_window);
			glfwSetFramebufferSizeCallback(s_window, ProcessInput::FrameBufferCallback);
			glfwSetCursorPosCallback(s_window, ProcessInput::MouseCallback);
			m_CurrentContextFlag = true;
		}
	}

    void PollPlatformWindow()
	{
		glfwPollEvents();
	}

    void PresentPlatformWindow()
	{
		glfwSwapBuffers(s_window);
	}

	void SetPlatformViewPort()
	{
		glViewport(0, 0, (int)s_width, (int)s_height);
	}

	void TerminatePlatform()
	{
		glfwTerminate();
	}

	void EnableInputMode()
	{
		glfwSetInputMode(s_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	}
}


























/*
bool Platform::m_gladFlag = false;
GLFWwindow* Platform::m_Window = nullptr;
GLFWwindow* Platform::m_sWindow = nullptr; 
GLFWmonitor* Platform::m_monitor = nullptr;

Platform::Platform(const int &w, const int &h, const char *t, const bool &fsMode, GLFWwindow* window, const int &cMajor, const int &cMinor, const std::string &p)
{
	glfwInit();
	m_Window = glfwCreateWindow(w, h, t, (GLFWmonitor*)(fsMode == TRUE ? m_monitor = glfwGetPrimaryMonitor() : FALSE), (window == NULL ? NULL : window));
	m_width = w;
	m_height = h;
	PlatformContextVersion();
	PlatformProfile();
	PlatformGLContext();
	LoadGLAD();
	if (m_gladFlag)
		SetViewPort();
}

bool Platform::LoadGLAD() const
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "LOG::GLAD::ERROR::GLAD HAS NOT BEEN INCLUDED SUCCESSFULLY::" << std::endl;
		m_gladFlag = false;
		return false;
	}
	else
	{
		std::cerr << "LOG::GLAD::INFO::GLAD HAS BEEN INCLUDED SUCCESSFULLY::" << std::endl;
		m_gladFlag = true;
		return true; 
	}
}

void Platform::PollPlatformWindow()
{
	glfwPollEvents();
}

void Platform::PresentPlatformWindow()
{
	glfwSwapBuffers(m_Window);
}

void Platform::SetViewPort()
{
	glViewport(0, 0, m_width, m_height);
}

void Platform::PlatformContextVersion()
{

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_cMajor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_cMinor);
}

void Platform::PlatformProfile()
{
	glfwWindowHint(GLFW_OPENGL_PROFILE, (m_profile == "CORE" ? GLFW_OPENGL_CORE_PROFILE : GLFW_OPENGL_COMPAT_PROFILE));
}

void Platform::PlatformGLContext()
{
	if (m_Window == NULL)
	{
		std::cerr << "LOG::CONTEXT GL::GLFW::ERROR::WINDOW CREATION HAS BEEN FAILED::" << std::endl;
		glfwTerminate();
	}
	else
	{
		std::cerr << "LOG::CONTEXT GL::GLFW::WINDOW HAS BEEN CREATED SUCCESSFULLY::" << std::endl;
		glfwMakeContextCurrent(m_Window);
		glfwSetFramebufferSizeCallback(m_Window, ProcessInput::FrameBufferCallback);
		m_CurrentContextFlag = true;
	}
}

void Platform::DestoryWindow()
{
	std::cerr << "~LOG::CONTEXT GL::DESTORY WINDOW HAS BEEN INVOKED::" << std::endl;
	glfwDestroyWindow(m_Window);
}

Platform::~Platform()
{
	std::cerr << "~LOG::CONTEXT GL::DESTRUCOR HAS BEEN INVOKED::" << std::endl;
	glfwTerminate();
}
*/