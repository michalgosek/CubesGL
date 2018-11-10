#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Headers:
#include "Platform.h"
#include "ProcessInput.h"
#include "Shader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "VertexBufferLayout.h"
#include "Texture2D.h"
#include "Cords.h"
#include "Camera.h"
#include "Render.h"
#include "glm.hpp" 

int main()
{
	PLATFORM_WINDOW window = platform::CreatePlatformWindow(800, 600, "CubesGL", FALSE, NULL, 3, 3, "CORE");
	Shader ShaderGL;
	ShaderCode sCode = ShaderGL.LoadShader("Resource Files/Shaders/Basic.shader");
	PROGRAM shaderProgram = ShaderGL.CreateShader(sCode.vsCode, sCode.fsCode);
	
	VertexBuffer VBO;
	VBO.CreateVertexBuffer(vertices);

	VertexArray VAO;
	VertexBufferLayout VBL;
	VBL.AddVertexAttribs<float>(3, rLength); //Vertex Cords
	VBL.AddVertexAttribs<float>(2, rLength); //Vertex TextureCords

	VAO.EnableAttribsLayout<float>(VBO, VBL);
	VAO.BindVertexArray();

	IndexBuffer IBO;
	IBO.CreateIndexBuffer(planes);

	Texture2D Texture("Resource Files/Textures/container.jpg", 0);
	Texture.BindTexutre2D();
	ShaderGL.BindShader();

	glm::vec3 cameraDirection = glm::vec3(-6.0f, 0.0f, -1.0f);
	glm::vec3 cameraOrigin = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUpAxis = glm::vec3(0.0f, 1.0f, 0.0f);

	Camera Camera(cameraDirection, cameraOrigin, cameraUpAxis);
	Camera.SetUnfiromProjection(ShaderGL);

	Render Render(ShaderGL);

	//rendering loop::
	while (ProcessInput::WindowStateController(window))
	{
		Render.ClearScreen();
		platform::EnableInputMode();
	    ShaderGL.BindShader();
		VAO.BindVertexArray();
		Camera.CameraKeyboardSpeed(0.02f);
		Camera.CameraMouseSpeed(0.3f);
		Camera.SetUnfiromView(ShaderGL);
		Render.DrawCubes(cubes, vertices);
		platform::PollPlatformWindow();
		platform::PresentPlatformWindow();
		ProcessInput::KeyboardMouseController(window, Camera);
	}

	platform::TerminatePlatform();
	return 0;
}