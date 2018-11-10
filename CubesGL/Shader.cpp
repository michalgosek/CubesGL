#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Shader.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm.hpp"
#include "gtc/type_ptr.hpp"


Shader::Shader(): m_ShaderID(0)
{
	std::cout << "LOG::SHADER CONSTRUCTOR::HAS BEEN INVOKED::" << std::endl;
}

Shader::~Shader()
{
	std::cout << "~LOG::SHADER DESTRUCTOR::HAS BEEN INVOKED::" << std::endl;
	glDeleteShader(m_ShaderID);
}

void Shader::BindShader() const
{ 
	//.... to-do cerr message
	glUseProgram(m_ShaderID);
}

void Shader::UnbindShader() const
{
	std::cout << "LOG::SHADER:: SHADER HAS BEEN UNBINDED::" << std::endl;
	glUseProgram(0);
}
 
int Shader::CreateShader(const std::string &vsPath, const std::string &fsPath)
{
	std::cout << "LOG::SHADER:: SHADER HAS BEEN CREATED::" << std::endl;
	m_ShaderID = glCreateProgram();
	unsigned int vShader = CompileShader(GL_VERTEX_SHADER, vsPath);
	unsigned int fShader = CompileShader(GL_FRAGMENT_SHADER, fsPath);

	glAttachShader(m_ShaderID, vShader);
	glAttachShader(m_ShaderID, fShader);
	glLinkProgram(m_ShaderID);
	glValidateProgram(m_ShaderID);

	glDeleteShader(vShader);
	glDeleteShader(fShader);
	return m_ShaderID;
}

ShaderCode Shader::LoadShader(const std::string& sPath) 
{
	std::ifstream file(sPath); 
 
	std::string line; 
	std::stringstream sstream[2];
	ShaderMode mode = ShaderMode::NONE;

		std::cout << "LOG::SHADER:: ATTEMPTING TO INVOKE LOAD SHADER:: " << std::endl;
		if (!file.is_open())
			std::perror("LOG::SHADER::ERROR:: SHADER FILE HAS NOT BEEN LOADED SUCCESSFULY::");
		else
			std::perror("LOG::SHADER:: LOAD SHADER HAS BEEN LOADED SUCCESSFULY::");

			while (getline(file, line))
			{ 
				if (line.find("#shader") != std::string::npos)
				{
					if (line.find("vertex") != std::string::npos)
						mode = ShaderMode::VERTEX;
					else if (line.find("fragment") != std::string::npos)
						mode = ShaderMode::FRAGMENT;
				}
				else
					sstream[(int)mode] << line << '\n';
			}

			if (file.bad())
				std::perror("LOG::SHADER::ERROR:: SHADER FILE ERROR WHILE READING FILE::");
			
			file.close();
			 
	return { sstream[0].str(), sstream[1].str() };
}

int Shader::CompileShader(unsigned int shaderType, const std::string &sPath)
{ 
	int cState, logLength;
	unsigned int program = glCreateShader(shaderType);
	const char *source = (const char*)sPath.c_str();
	glShaderSource(program, 1, &source, 0);
	glCompileShader(program);
	glGetShaderiv(program, GL_COMPILE_STATUS, &cState);

	if (cState != GL_TRUE)
	{
		glGetShaderiv(program, GL_INFO_LOG_LENGTH, &logLength);
		std::vector<char> infoLog(logLength);
		glGetShaderInfoLog(program, logLength, nullptr, infoLog.data());
		std::cerr << "LOG::SHADER:::" << (shaderType == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "_SHADER HAS BEEN COMPILED UNSUCCESSFULLY::" << std::endl;
		return -1;
	}
	else
		std::cout << "LOG::SHADER::" << (shaderType == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "_SHADER HAS BEEN COMPILED SUCCESSFULLY::" << std::endl;

	return program;
}

void Shader::SetUniform1f(const std::string& name, const float& value) const
{
	std::cout << "LOG::SHADER:: UNIFORM_1F VALUE HAS BEEN SET TO:" << value << std::endl;
	glUniform1f(glGetUniformLocation(m_ShaderID, name.c_str()), value);
}
void Shader::SetUniform1i(const std::string& name, const int& value) const
{
	std::cout << "LOG::SHADER:: UNIFORM_1I VALUE HAS BEEN SET TO:" << value << std::endl;
	glUniform1i(glGetUniformLocation(m_ShaderID, name.c_str()), value);
}

void Shader::SetUniform4f(const std::string &name, const float& v1, const float& v2, const float& v3, const float& v4) const
{
	std::cout << "LOG::SHADER:: UNIFORM_4F VALUES HAS BEEN SET TO:" << v1 << ", " << v2 << ", " << v3 << ", " << v4 << std::endl;
	glUniform4f(glGetUniformLocation(m_ShaderID, name.c_str()), v1, v2, v3, v4);
}

void Shader::SetUniformMatrix4fv(const std::string& name, const glm::mat4& matrix) const
{
	//.... to-do cerr message
	glUniformMatrix4fv(glGetUniformLocation(m_ShaderID, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}
 
 
