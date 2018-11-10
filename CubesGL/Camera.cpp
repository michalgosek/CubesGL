#define GLM_ENABLE_EXPERIMENTAL
#include <iostream>

#include "Camera.h"
#include "gtx/string_cast.hpp"

Camera::Camera(const glm::vec3& direction, const glm::vec3& origin, const glm::vec3& upAxis) 

	: m_View(1.0f), m_Pojection(1.0f), m_cDirection(direction), m_cOrigin(origin), 
	  m_cUpAxis(upAxis), m_Fov(45.0f), m_Ratio((float)800/(float)600), m_nPlane(0.1f), 
	  m_fPlane(100.0f), m_kSpeed(0.0f), m_mSpeed(0.0f)
{
	m_Pojection = glm::perspective(glm::radians(m_Fov), m_Ratio, m_nPlane, m_fPlane);
	m_View = glm::lookAt(direction, origin, upAxis);

	std::cout << "LOG::CAMERA:: CONSTRUCTOR HAS BEEN INVOKED ::" << std::endl;
}

void Camera::CameraMouseMovement(const float& pValue, const float& yValue)
{
	m_cOrigin.x = cos(glm::radians(pValue)) * cos(glm::radians(yValue));
	m_cOrigin.y = sin(glm::radians(pValue));
	m_cOrigin.z = cos(glm::radians(pValue)) * sin(glm::radians(yValue));
	m_cOrigin = glm::normalize(m_cOrigin);
}

void Camera::CameraKeyboardSpeed(const float& kSpeed)
{
	m_kSpeed = kSpeed;
	m_View = glm::lookAt(m_cDirection, m_cDirection + m_cOrigin, m_cUpAxis);
}

void Camera::CameraMouseSpeed(const float& mSpeed)
{
	m_mSpeed = mSpeed;
}

void Camera::SetFieldOfView(const float& fov)
{
	m_Fov = fov;
	std::cout << "LOG::CAMERA:: FOV HAS BEEN SET TO:: " << fov << std::endl;
}

void Camera::SetCameraDirection(const glm::vec3& direction)
{
	m_cDirection = direction;
	std::cout << "LOG::CAMERA:: DIRECTION HAS BEEN SET TO:: "<< glm::to_string(m_cDirection) << std::endl;
}

void Camera::SetCameraOrigin(const glm::vec3& origin)
{
	m_cOrigin = origin;
	std::cout << "LOG::CAMERA:: ORIGIN HAS BEEN SET TO:: " << glm::to_string(m_cOrigin)<< std::endl;
}

void Camera::SetCameraUpAxis(const glm::vec3& upAxis)
{
	m_cUpAxis = upAxis;
	std::cout << "LOG::CAMERA:: UP AXIS HAS BEEN SET TO:: " << glm::to_string(m_cUpAxis) << std::endl;
}

void Camera::SetUnfiromProjection(const Shader & s)
{
	s.SetUniformMatrix4fv("u_Projection", m_Pojection);
}

void Camera::SetUnfiromView(const Shader & s)
{
	s.SetUniformMatrix4fv("u_View", m_View);
 
}

Camera::~Camera()
{
	std::cout << "LOG::CAMERA:: CAMERA CLASS HAS BEEN TERMINATED::" << std::endl;
}
