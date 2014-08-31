#pragma once

#include <string>
#include <iosfwd>

class Vector3f
{
public:
	Vector3f(float x, float y, float z);
	~Vector3f();
	float length() const;
	float dot(const Vector3f& r) const;
	Vector3f cross(const Vector3f& r) const;
	void normalize();
	Vector3f rotate(float angle) const;
	friend Vector3f operator+ (const Vector3f& a, const Vector3f& b);
	friend Vector3f operator+ (const Vector3f& a, int b);
	friend Vector3f operator+ (int a, const Vector3f& b);
	friend Vector3f operator- (const Vector3f& a, const Vector3f& b);
	friend Vector3f operator- (const Vector3f& a, int b);
	friend Vector3f operator- (int a, const Vector3f& b);
	friend Vector3f operator* (const Vector3f& a, const Vector3f& b);
	friend Vector3f operator* (const Vector3f& a, int b);
	friend Vector3f operator* (int a, const Vector3f& b);
	friend Vector3f operator/ (const Vector3f& a, const Vector3f& b);
	friend Vector3f operator/ (const Vector3f& a, int b);
	friend Vector3f operator/ (int a, const Vector3f& b);
	friend std::ostream& operator<< (std::ostream&, const Vector3f& v);
	std::string toString() const;
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	float getZ() const;
	void setZ(float z);

private:
	float x;
	float y;
	float z;
};

