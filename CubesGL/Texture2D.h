#pragma once
#include <string>

class Texture2D
{
private:
	unsigned int m_Texture2D_ID;
	unsigned char* m_texturePath;
	int m_textureWidth;
	int m_textureHeight;
	int m_nChannels;

public:
	explicit Texture2D(const std::string &tPath, const unsigned int &format);
	~Texture2D();
	void BindTexutre2D(unsigned int slot = 0) const;
	void UnbindTexture2D() const;
};

