#pragma once
#include <vector>
#include <iostream>

#include "glad/glad.h"

class VertexBuffer
{
private:
	unsigned int m_vertexBufferID;

public:
	explicit VertexBuffer(): m_vertexBufferID(0) {}
	~VertexBuffer();

	void BindVertexBuffer() const;
	void UnbindVertexBuffer() const;

	template <class T>
	void CreateVertexBuffer(const std::vector<T>& vec)
	{
		std::cout << "LOG::VERTEX_BUFFER:: HAS BEEN CREATED AND BINDED::" << std::endl;
		glGenBuffers(1, &m_vertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID); 
		glBufferData(GL_ARRAY_BUFFER, vec.size() * sizeof(vec), &vec.front(), GL_STATIC_DRAW);
	}
};
