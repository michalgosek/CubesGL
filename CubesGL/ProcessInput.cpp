#include "ProcessInput.h"
#include "Camera.h"

#include <iostream>
#include <vector>

//....Static definitions:
float ProcessInput::m_lastXpos = 400.0f;
float ProcessInput::m_lastYpos = 300.0f;
float ProcessInput::m_xOffset = 0.0f;
float ProcessInput::m_yOffset = 0.0f;
float ProcessInput::m_mSpeed = 0.0f;
float ProcessInput::m_yValue = 0.0f;
float ProcessInput::m_pValue = 0.0f;
bool  ProcessInput::m_aJump = true;

void ProcessInput::FrameBufferCallback(PLATFORM_WINDOW window, const int sWidth, const int sHeight)
{
	std::cout << "LOG::PROCESS_INPUT:: FRAMEBUFFER RESIZED WINDOW RESOULTION TO: " << sWidth << "X" << sHeight << std::endl;
	glViewport(0, 0, sWidth, sHeight);
}

void ProcessInput::MouseCallback(PLATFORM_WINDOW window, double x, double y)
{
	if (m_aJump)
	{
		m_lastXpos = (float)x;
		m_lastYpos = (float)y;
		m_aJump = false;
	}

	m_xOffset = (float)x - m_lastXpos;
	m_yOffset = m_lastYpos - (float)y;

	m_lastXpos = (float)x;
	m_lastYpos = (float)y;

	m_xOffset *= m_mSpeed;
	m_yOffset *= m_mSpeed;

	m_pValue += m_yOffset;
	m_yValue += m_xOffset;

	if (m_pValue > 89.0f)
		m_pValue = 89.0f;
	if (m_pValue < -89.0f)
		m_pValue = -89.0f;

	std::cout << "LOG::PROCESS_INPUT:: X OFFSET: " << m_xOffset << std::endl;
	std::cout << "LOG::PROCESS_INPUT:: Y OFFSET: " << m_yOffset << std::endl;
}

bool ProcessInput::WindowStateController(PLATFORM_WINDOW window)
{
	if (glfwWindowShouldClose(window) != false)
	{
		std::cout << "LOG::PROCESS_INPUT:: WINDOW HAS BEEN IMMEDIATELY TERMINATED::" << std::endl;
		glfwTerminate();
		return false;
	}
	return true;
}


void ProcessInput::KeyboardMouseController(PLATFORM_WINDOW window,  Camera& camera)
{
	//ESC KEY
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	//CAMERA:
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) //..front
	{
		camera.m_cDirection += camera.m_kSpeed * camera.m_cOrigin;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) //..back
	{
		camera.m_cDirection -= camera.m_kSpeed * camera.m_cOrigin;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) //..left
	{
		camera.m_cDirection -= glm::normalize(glm::cross(camera.m_cOrigin, camera.m_cUpAxis)) * camera.m_kSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) //..right
	{
		camera.m_cDirection += glm::normalize(glm::cross(camera.m_cOrigin, camera.m_cUpAxis)) * camera.m_kSpeed;
	}

	//MOUSE:
	m_mSpeed = camera.m_mSpeed;
	camera.CameraMouseMovement(m_pValue, m_yValue);
}


 

 
 
