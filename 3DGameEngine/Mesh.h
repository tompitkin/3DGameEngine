#pragma once

#include <gl\glew.h>
#include <vector>

class Vertex;

class Mesh
{
public:
	Mesh();
	~Mesh();
	void addVertices(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
	void draw() const;

private:
	GLuint vbo;
	GLuint ibo;
	GLsizeiptr size;
};

