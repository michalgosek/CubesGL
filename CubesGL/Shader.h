#pragma once
#include <string>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

struct ShaderCode
{
	std::string vsCode;
	std::string fsCode;
};

class Shader
{
private:
	unsigned int m_ShaderID;
	int CompileShader(unsigned int shaderType, const std::string& dataPath);

	enum class ShaderMode { VERTEX = 0, FRAGMENT = 1, NONE = -1 };
	static ShaderMode mode;

public:
	explicit Shader();
	~Shader();

    ShaderCode LoadShader(const std::string& sPath);
	int CreateShader(const std::string& vsPath, const std::string& fsPath);
   
	void BindShader() const;
	void UnbindShader() const; 

	//Uniforms:
	void SetUniform1f(const std::string& name, const float& value) const;
	void SetUniform1i(const std::string& name, const int& value) const;
	void SetUniform4f(const std::string &name, const float& v1, const float& v2, const float& v3, const float& v4) const;
	void SetUniformMatrix4fv(const std::string& name, const glm::mat4& matrix) const;
};

 
 
