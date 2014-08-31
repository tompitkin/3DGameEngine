#pragma once

#include <gl/glew.h>
#include <string>
#include <map>

class Vector3f;
class Matrix4f;

class Shader
{
public:
	Shader();
	~Shader();

	void addVertexShader(const std::string& data);
	void addGeometryShader(const std::string& data);
	void addFragmentShader(const std::string& data);
	int addUniform(const std::string& uniformName);
	int compile();
	void bind();
	void setUniformi(const std::string& uniformName, int value);
	void setUniformf(const std::string& uniformName, float value);
	void setUniform(const std::string& uniformName, const Vector3f& value);
	void setUniform(const std::string& uniformName, const Matrix4f& value);

private:
	int addProgram(const std::string& data, GLenum type);
	GLuint program;
	std::map<std::string, int> uniforms;
};