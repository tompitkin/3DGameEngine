#include "Vector2f.h"

#include <sstream>
#include "Utility.h"

Vector2f::Vector2f(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2f::~Vector2f()
{
}

float Vector2f::length() const
{
	return sqrtf(x * x + y * y);
}

float Vector2f::dot(const Vector2f& r) const
{
	return x * r.x + y * r.y;
}

void Vector2f::normalize()
{
	float length = Vector2f::length();

	x /= length;
	y /= length;
}

Vector2f Vector2f::rotate(float angle) const
{
	double rad = Utils::toRadians(angle);
	double cos = std::cos(rad);
	double sin = std::sin(rad);

	return Vector2f((float)(x * cos - y * sin), (float)(x * sin + y * cos));
}

Vector2f operator+ (const Vector2f& a, const Vector2f& b)
{
	return Vector2f(a.x + b.x, a.y + b.y);
}

Vector2f operator+ (const Vector2f& a, int b)
{
	return Vector2f(a.x + b, a.y + b);
}

Vector2f operator+ (int a, const Vector2f& b)
{
	return Vector2f(a + b.x, a + b.y);
}

Vector2f operator- (const Vector2f& a, const Vector2f& b)
{
	return Vector2f(a.x - b.x, a.y - b.y);
}

Vector2f operator- (const Vector2f& a, int b)
{
	return Vector2f(a.x - b, a.y - b);
}

Vector2f operator- (int a, const Vector2f& b)
{
	return Vector2f(a - b.x, a - b.y);
}

Vector2f operator* (const Vector2f& a, const Vector2f& b)
{
	return Vector2f(a.x * b.x, a.y * b.y);
}

Vector2f operator* (const Vector2f& a, int b)
{
	return Vector2f(a.x * b, a.y * b);
}

Vector2f operator* (int a, const Vector2f& b)
{
	return Vector2f(a * b.x, a * b.y);
}

Vector2f operator/ (const Vector2f& a, const Vector2f& b)
{
	return Vector2f(a.x / b.x, a.y / b.y);
}

Vector2f operator/ (const Vector2f& a, int b)
{
	return Vector2f(a.x / b, a.y / b);
}

Vector2f operator/ (int a, const Vector2f& b)
{
	return Vector2f(a / b.x, a / b.y);
}

std::ostream& operator<< (std::ostream& s, const Vector2f& v)
{
	return s << "(" << v.x << ", " << v.y << ")";
}

std::string Vector2f::toString() const
{
	std::ostringstream ss;
	ss << *this;
	return ss.str();
}

float Vector2f::getX() const
{
	return x;
}

void Vector2f::setX(float x)
{
	this->x = x;
}

float Vector2f::getY() const
{
	return y;
}

void Vector2f::setY(float y)
{
	this->y = y;
}