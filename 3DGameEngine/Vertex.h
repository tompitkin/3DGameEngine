#pragma once

#include "Vector3f.h"

class Vertex
{
public:
	Vertex(const Vector3f& pos);
	~Vertex();
	const Vector3f& getPos() const;
	void setPos(Vector3f pos);
	static const unsigned int SIZE = 3;

private:
	Vector3f pos;
};

