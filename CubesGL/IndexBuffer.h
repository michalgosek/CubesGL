#pragma once
#include <iostream>
#include <vector>

#include "glad/glad.h"

class IndexBuffer
{
private:
	unsigned int m_IndexBufferID;

public:
    explicit IndexBuffer() : m_IndexBufferID(0) {};
	~IndexBuffer();

	void BindIndexBuffer() const;
	void UnbindIndexBuffer() const;

	template <class T>
	void CreateIndexBuffer(const std::vector<T>& vec)
	{
		std::cout << "LOG::INDEX_BUFFER:: HAS BEEN CREATED AND BINDED::" << std::endl;
		glGenBuffers(1, &m_IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, vec.size() * sizeof(vec), &vec.front(), GL_STATIC_DRAW);
	}
};


