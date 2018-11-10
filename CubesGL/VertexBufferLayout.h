#pragma once
#include <vector>

#include "glad/glad.h"

struct VertexDataElements
{
	const std::size_t size;
	const std::size_t dataType;
	const unsigned char rowLength;
};

class VertexBufferLayout
{
private:
    std::vector<VertexDataElements> m_VertexAttributes;
	unsigned int m_Index;
	
public:
	explicit VertexBufferLayout() : m_Index(0) {};
	~VertexBufferLayout();

	inline const std::vector<VertexDataElements>& GetVertexAttribsElements() const
	{
		return m_VertexAttributes;
	}

    template <typename T>
    inline void AddVertexAttribs(const std::size_t&size, const unsigned char& rowLength)
	{
		m_VertexAttributes.push_back({size, GL_UNSIGNED_BYTE, rowLength });
	}

	template<>
	inline void AddVertexAttribs<int>(const std::size_t &size, const unsigned char& rowLength)
	{
		m_VertexAttributes.push_back({ size, GL_INT, rowLength });
	}

	template<>
	inline void AddVertexAttribs<float>(const std::size_t& size, const unsigned char& rowLength)
	{
		m_VertexAttributes.push_back({ size, GL_FLOAT, rowLength });
	}
};

