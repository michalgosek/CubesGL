#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "stb_image.h"
#include "Texture2D.h"

#include <iostream>

Texture2D::Texture2D(const std::string &tPath, const unsigned int &format): 
	m_Texture2D_ID(0), m_texturePath(nullptr), m_textureWidth(0), m_textureHeight(0), m_nChannels(0)
{
	std::cout << "LOG::TEXTURE_2D:: TEXTURE HAS BEEN GENERATED AND BINDED::" << std::endl;
	glGenTextures(1, &m_Texture2D_ID);
	glBindTexture(GL_TEXTURE_2D, m_Texture2D_ID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	m_texturePath = stbi_load(tPath.c_str(), &m_textureWidth, &m_textureHeight, &m_nChannels, 0);
	if (m_texturePath)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_textureWidth, m_textureHeight, 0, (format == 0 ? GL_RGB : GL_RGBA), GL_UNSIGNED_BYTE, m_texturePath);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
		std::cout << "LOG::TEXTURE_2D:: TEXTURE HAS BEEN LOADED::" << std::endl;
	}
	else
		std::cerr << "LOG::TEXTURE_2D:: TEXTURE FILE OPENING HAS BEEN FAILED::" << std::endl;

	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(m_texturePath);
}

Texture2D::~Texture2D()
{
	std::cout << "LOG::TEXTURE_2D:: TEXTURE HAS BEEN DELETED::" << std::endl;
	glDeleteTextures(1, &m_Texture2D_ID);
}

void Texture2D::BindTexutre2D(unsigned int slot) const
{
	std::cout << "LOG::TEXTURE_2D:: TEXTURE SLOT: " << slot << " HAS BEEN BINDED::" << std::endl;
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_Texture2D_ID);
}

void Texture2D::UnbindTexture2D() const
{
	std::cout << "LOG::TEXTURE_2D:: TEXTURE HAS BEEN UNBINDED::" << std::endl;
	glBindTexture(GL_TEXTURE_2D, 0);
}

 


