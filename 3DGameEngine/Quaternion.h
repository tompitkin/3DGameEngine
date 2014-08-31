#pragma once

class Vector3f;

class Quaternion
{
public:
	Quaternion(float x, float y, float z, float w);
	~Quaternion();
	float length() const;
	void normalize();
	Quaternion conjugate() const;
	friend Quaternion operator* (const Quaternion& a, const Quaternion& b);
	friend Quaternion operator* (const Quaternion& a, const Vector3f& b);
	friend Quaternion operator* (const Vector3f& a, const Quaternion& b);
	float getX() const;
	void setX(float x);
	float getY() const;
	void setY(float y);
	float getZ() const;
	void setZ(float z);
	float getW() const;
	void setW(float w);

private:
	float x;
	float y;
	float z;
	float w;
};

