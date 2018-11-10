#include "VertexBuffer.h"
#include "glad/glad.h"
 
VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_vertexBufferID);
}

void VertexBuffer::BindVertexBuffer() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
}

void VertexBuffer::UnbindVertexBuffer() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

