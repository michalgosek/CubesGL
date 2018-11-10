#pragma once
#include <vector>

#include "glm.hpp"
#include "Shader.h"

class Render
{
private:
	Shader shader;
	glm::mat4 model;

public:
	Render(const Shader& shader);
	void DrawCubes(const std::vector<glm::vec3>& c, const std::vector<float>& v);
	void ClearScreen(const float& v1 = 0.4f, const float& v2 = 0.5f, const float& v3 = 0.8f, const float& v4 = 1.0f) const;
	~Render();
};

 
 