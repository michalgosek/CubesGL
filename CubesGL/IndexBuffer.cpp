#include "IndexBuffer.h"
#include "glad/glad.h"

IndexBuffer::~IndexBuffer()
{
	std::cout << "LOG::INDEX_BUFFER:: INDEX BUFFER HAS BEEN DELETED::" << std::endl;
	glDeleteBuffers(1, &m_IndexBufferID);
}

void IndexBuffer::BindIndexBuffer() const
{
	std::cout << "LOG::INDEX_BUFFER:: INDEX BUFFER HAS BEEN BINDED::" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
}

void IndexBuffer::UnbindIndexBuffer() const
{
	std::cout << "LOG::INDEX_BUFFER:: INDEX BUFFER HAS BEEN UNBINDED::" << std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

 
 