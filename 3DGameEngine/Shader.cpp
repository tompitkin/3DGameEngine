#include "Shader.h"

#include <iostream>
#include "Vector3f.h"
#include "Matrix4f.h"

Shader::Shader()
{
	program = glCreateProgram();

	if (!program)
		std::cerr << "Program creation failed.\n";
}

Shader::~Shader()
{
}

void Shader::addVertexShader(const std::string& data)
{
	addProgram(data, GL_VERTEX_SHADER);
}

void Shader::addGeometryShader(const std::string& data)
{
	addProgram(data, GL_GEOMETRY_SHADER);
}

void Shader::addFragmentShader(const std::string& data)
{
	addProgram(data, GL_FRAGMENT_SHADER);
}

int Shader::compile()
{
	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);

	if (!status)
	{
		GLint infoLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLength);

		GLchar* infoLog = new GLchar[infoLength + 1];
		glGetProgramInfoLog(program, infoLength, NULL, infoLog);
		std::cerr << infoLog;
		delete[] infoLog;

		return 1;
	}

	glValidateProgram(program);

	glGetProgramiv(program, GL_VALIDATE_STATUS, &status);

	if (!status)
	{
		GLint infoLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLength);

		GLchar* infoLog = new GLchar[infoLength + 1];
		glGetProgramInfoLog(program, infoLength, NULL, infoLog);
		std::cerr << (infoLog);
		delete[] infoLog;

		return 1;
	}

	return 0;
}

int Shader::addUniform(const std::string& uniformName)
{
	GLint uniformLocation = glGetUniformLocation(program, uniformName.c_str());

	if (uniformLocation == -1)
	{
		std::cerr << "ERROR: Could not find uniform: " << uniformName << '\n';
		return 1;
	}

	uniforms[uniformName] = uniformLocation;

	return 0;
}

void Shader::bind()
{
	glUseProgram(program);
}

int Shader::addProgram(const std::string& data, GLenum type)
{
	GLuint shader = glCreateShader(type);

	if (!shader)
	{
		std::cerr << "Shader creation failed.\n";
		return 1;
	}

	const GLchar *shaderData = data.c_str();
	glShaderSource(shader, 1, &shaderData, NULL);
	glCompileShader(shader);

	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

	if (!status)
	{
		GLint infoLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLength);
		
		GLchar* infoLog = new GLchar[infoLength + 1];
		glGetShaderInfoLog(shader, infoLength, NULL, infoLog);
		std::cerr << infoLog;
		delete[] infoLog;
		
		return 1;
	}

	glAttachShader(program, shader);

	return 0;
}

void Shader::setUniformi(const std::string& uniformName, int value)
{
	glUniform1i(uniforms[uniformName], value);
}

void Shader::setUniformf(const std::string& uniformName, float value)
{
	glUniform1f(uniforms[uniformName], value);
}

void Shader::setUniform(const std::string& uniformName, const Vector3f& value)
{
	glUniform3f(uniforms[uniformName], value.getX(), value.getY(), value.getZ());
}

void Shader::setUniform(const std::string& uniformName, const Matrix4f& value)
{
	glUniformMatrix4fv(uniforms[uniformName], 1, GL_TRUE, &value.getM()[0]);
}