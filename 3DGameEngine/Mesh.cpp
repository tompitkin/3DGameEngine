#include "Mesh.h"

#include "Vertex.h"
#include "Utility.h"

Mesh::Mesh()
{
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);
	size = 0;
}

Mesh::~Mesh()
{
}

void Mesh::addVertices(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
{
	size = indices.size();

	std::vector<GLfloat> verts;
	verts.reserve(size);
	Utils::createFloatBuffer(vertices, verts);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(verts[0]), &verts[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), &indices[0], GL_STATIC_DRAW);
}

void Mesh::draw() const
{
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, Vertex::SIZE * 4, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
}