#include <iostream>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Render.h"
#include "glm.hpp" 
#include "gtc/matrix_transform.hpp"


Render::Render(const Shader& shader)
	: model(1.0f), shader(shader)
{
	std::cout << "LOG::RENDER:: DEPTH TEST HAS BEEN ENABLED BY DEFAULT ::" << std::endl;
	glEnable(GL_DEPTH_TEST);
}

void Render::DrawCubes(const std::vector<glm::vec3>& c, const std::vector<float>& v)
{
	for (std::size_t it = 0; it < c.size(); ++it)
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, c[it]);
		model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(it + 0.5f, it - 0.3f, it - 0.3f));
		shader.SetUniformMatrix4fv("u_Model", model);
		glDrawElements(GL_TRIANGLES, v.size(), GL_UNSIGNED_INT, 0);
	}
}

void Render::ClearScreen(const float& v1, const float& v2, const float& v3, const float& v4) const
{
	glClearColor(v1, v2, v3, v4);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

Render::~Render()
{
	std::cout << "~LOG::RENDER:: DESTRUCTOR HAS BEEN INVOKED ::" << std::endl;
}

