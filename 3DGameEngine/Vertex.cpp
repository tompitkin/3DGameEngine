#include "Vertex.h"

Vertex::Vertex(const Vector3f& pos) : pos(pos)
{
}

Vertex::~Vertex()
{
}

const Vector3f& Vertex::getPos() const
{
	return pos;
}

void Vertex::setPos(Vector3f pos)
{
	this->pos = pos;
}