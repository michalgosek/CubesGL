#include "VertexArray.h"
#include "VertexBufferLayout.h"

VertexArray::VertexArray() : m_VertexArrayID(0), m_offset(0), m_stride(0)
{
	glGenVertexArrays(1, &m_VertexArrayID);
	glBindVertexArray(m_VertexArrayID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_VertexArrayID);
}

void VertexArray::BindVertexArray() const
{
	glBindVertexArray(m_VertexArrayID);
}

void VertexArray::UnbindVertexArray() const
{
	glBindVertexArray(0);
}