#include "Quaternion.h"

#include <cmath>
#include "Vector3f.h"

Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Quaternion::~Quaternion()
{
}

float Quaternion::length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

void Quaternion::normalize()
{
	float length = Quaternion::length();

	x /= length;
	y /= length;
	z /= length;
	w /= length;
}

Quaternion Quaternion::conjugate() const
{
	return Quaternion(-x, -y, -z, w);
}

Quaternion operator* (const Quaternion& a, const Quaternion& b)
{
	float newW = a.w * b.w - a.x * b.x - a.y * b.y - a.z * b.z;
	float newX = a.x * b.w + a.w * b.x + a.y * b.z - a.z * b.y;
	float newY = a.y * b.w + a.w * b.y + a.z * b.x - a.x * b.z;
	float newZ = a.z * b.w + a.w * b.z + a.x * b.y - a.y * b.x;

	return Quaternion(newX, newY, newZ, newW);
}

Quaternion operator* (const Quaternion& a, const Vector3f& b)
{
	float newW = -a.x * b.getX() - a.y * b.getY() - a.z * b.getZ();
	float newX =  a.w * b.getX() + a.y * b.getZ() - a.z * b.getY();
	float newY =  a.w * b.getY() + a.z * b.getX() - a.x * b.getZ();
	float newZ =  a.w * b.getZ() + a.x * b.getY() - a.y * b.getX();

	return Quaternion(newX, newY, newZ, newW);
}

Quaternion operator* (const Vector3f& a, const Quaternion& b)
{
	float newW = -b.x * a.getX() - b.y * a.getY() - b.z * a.getZ();
	float newX =  b.w * a.getX() + b.y * a.getZ() - b.z * a.getY();
	float newY =  b.w * a.getY() + b.z * a.getX() - b.x * a.getZ();
	float newZ =  b.w * a.getZ() + b.x * a.getY() - b.y * a.getX();

	return Quaternion(newX, newY, newZ, newW);
}

float Quaternion::getX() const
{
	return x;
}

void Quaternion::setX(float x)
{
	this->x = x;
}

float Quaternion::getY() const
{
	return y;
}

void Quaternion::setY(float y)
{
	this->y = y;
}

float Quaternion::getZ() const
{
	return z;
}

void Quaternion::setZ(float z)
{
	this->z = z;
}

float Quaternion::getW() const
{
	return w;
}

void Quaternion::setW(float w)
{
	this->w = w;
}