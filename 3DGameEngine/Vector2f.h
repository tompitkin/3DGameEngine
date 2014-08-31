#pragma once

#include <string>
#include <iosfwd>

class Vector2f
{
public:
	Vector2f(float x, float y);
	~Vector2f();
	float length() const;
	float dot(const Vector2f& r) const;
	void normalize();
	Vector2f rotate(float angle) const;
	friend Vector2f operator+ (const Vector2f& a, const Vector2f& b);
	friend Vector2f operator+ (const Vector2f& a, int b);
	friend Vector2f operator+ (int a, const Vector2f& b);
	friend Vector2f operator- (const Vector2f& a, const Vector2f& b);
	friend Vector2f operator- (const Vector2f& a, int b);
	friend Vector2f operator- (int a, const Vector2f& b);
	friend Vector2f operator* (const Vector2f& a, const Vector2f& b);
	friend Vector2f operator* (const Vector2f& a, int b);
	friend Vector2f operator* (int a, const Vector2f& b);
	friend Vector2f operator/ (const Vector2f& a, const Vector2f& b);
	friend Vector2f operator/ (const Vector2f& a, int b);
	friend Vector2f operator/ (int a, const Vector2f& b);
	friend std::ostream& operator<< (std::ostream&, const Vector2f& v);
	std::string toString() const;
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);

private:
	float x;
	float y;
};

