#include "Vector3f.h"

#include <sstream>

Vector3f::Vector3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f::~Vector3f()
{
}

float Vector3f::length() const
{
	return sqrtf(x * x + y * y + z * z);
}

float Vector3f::dot(const Vector3f& r) const
{
	return x * r.x + y * r.y + z * r.z;
}

Vector3f Vector3f::cross(const Vector3f& r) const
{
	float newX = y * r.z - z * r.y;
	float newY = z * r.x - x * r.z;
	float newZ = x * r.y - y * r.x;

	return Vector3f(newX, newY, newZ);
}

void Vector3f::normalize()
{
	float length = Vector3f::length();

	x /= length;
	y /= length;
	z /= length;
}

Vector3f Vector3f::rotate(float angle) const
{
	return Vector3f(0, 0, 0);
}

Vector3f operator+ (const Vector3f& a, const Vector3f& b)
{
	return Vector3f(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector3f operator+ (const Vector3f& a, int b)
{
	return Vector3f(a.x + b, a.y + b, a.z + b);
}

Vector3f operator+ (int a, const Vector3f& b)
{
	return Vector3f(a + b.x, a + b.y, a + b.z);
}

Vector3f operator- (const Vector3f& a, const Vector3f& b)
{
	return Vector3f(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector3f operator- (const Vector3f& a, int b)
{
	return Vector3f(a.x - b, a.y - b, a.z - b);
}

Vector3f operator- (int a, const Vector3f& b)
{
	return Vector3f(a - b.x, a - b.y, a - b.z);
}

Vector3f operator* (const Vector3f& a, const Vector3f& b)
{
	return Vector3f(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector3f operator* (const Vector3f& a, int b)
{
	return Vector3f(a.x * b, a.y * b, a.z * b);
}

Vector3f operator* (int a, const Vector3f& b)
{
	return Vector3f(a * b.x, a * b.y, a * b.z);
}

Vector3f operator/ (const Vector3f& a, const Vector3f& b)
{
	return Vector3f(a.x / b.x, a.y / b.y, a.z / b.z);
}

Vector3f operator/ (const Vector3f& a, int b)
{
	return Vector3f(a.x / b, a.y / b, a.z / b);
}

Vector3f operator/ (int a, const Vector3f& b)
{
	return Vector3f(a / b.x, a / b.y, a / b.z);
}

std::ostream& operator<< (std::ostream& s, const Vector3f& v)
{
	return s << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

std::string Vector3f::toString() const
{
	std::ostringstream ss;
	ss << *this;
	return ss.str();
}

float Vector3f::getX() const
{
	return x;
}

void Vector3f::setX(float x)
{
	this->x = x;
}

float Vector3f::getY() const
{
	return y;
}

void Vector3f::setY(float y)
{
	this->y = y;
}

float Vector3f::getZ() const
{
	return z;
}

void Vector3f::setZ(float z)
{
	this->z = z;
}