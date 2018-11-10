#pragma once
#include <vector>

#include "glm.hpp"
#include "Shader.h"
#include "ProcessInput.h"

class Camera
{
private:
	glm::mat4 m_View;
	glm::mat4 m_Pojection;

	glm::vec3 m_cDirection;
	glm::vec3 m_cOrigin;
	glm::vec3 m_cUpAxis;

    float m_Fov;
    float m_Ratio;
    float m_nPlane;
    float m_fPlane;
    float m_kSpeed;  
	float m_mSpeed;  

	void CameraMouseMovement(const float& pValue, const float& yValue); 

public:
	explicit Camera(const glm::vec3& direction, const glm::vec3& origin, const glm::vec3& upAxis);
	
	void CameraKeyboardSpeed(const float& kSpeed);
	void CameraMouseSpeed(const float& mSpeed);
	void SetFieldOfView(const float& fov);
	void SetCameraDirection(const glm::vec3& direction);
	void SetCameraOrigin(const glm::vec3& origin);
	void SetCameraUpAxis(const glm::vec3& upAxis);

	void SetUnfiromProjection(const Shader& s);
	void SetUnfiromView(const Shader& s);
	~Camera();

	friend void ProcessInput::KeyboardMouseController(PLATFORM_WINDOW window, Camera& camera);
};

 
 
