#pragma once
#include <iostream>
#include <vector>

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray
{
private:
	unsigned int m_VertexArrayID;
	unsigned int m_stride;
	unsigned int m_offset;
 
public:
	explicit VertexArray();
	~VertexArray();

	void BindVertexArray() const;
	void UnbindVertexArray() const;
	void EnableAttribsLayout(const VertexBuffer& vbo, const VertexBufferLayout& vbl);

	template<class T>
	void EnableAttribsLayout(const VertexBuffer& vbo, const VertexBufferLayout& vbl)
	{
		//....
	}

	template<>
	void EnableAttribsLayout<float>(const VertexBuffer& vbo, const VertexBufferLayout& vbl)
	{
		vbo.BindVertexBuffer();
		auto &elements = vbl.GetVertexAttribsElements();

		for (std::size_t it = 0; it < elements.size(); ++it)
		{
			const auto& element = elements[it];
			m_stride = element.rowLength * sizeof(float);
			glEnableVertexAttribArray(it);
			glVertexAttribPointer(it, element.size, GL_FLOAT, GL_FALSE, m_stride, (void*)m_offset);
			std::cout << it << " : m_stride: " << m_stride << "   m_offset: " << m_offset << std::endl;
			m_offset += element.size * sizeof(float);
		}
	}

	template<>
	void EnableAttribsLayout<int>(const VertexBuffer& vbo, const VertexBufferLayout& vbl)
	{
		vbo.BindVertexBuffer();
		const auto& elements = vbl.GetVertexAttribsElements();
		for (std::size_t it = 0; it < elements.size(); ++it)
		{
			const auto& element = elements[it];
			m_stride = element.rowLength * sizeof(int);
			glEnableVertexAttribArray(it);
			glVertexAttribPointer(it, element.size, GL_INT, GL_FALSE, m_stride, (void*)m_offset);
			m_offset += m_offset * sizeof(int);
		}
	}
};

 