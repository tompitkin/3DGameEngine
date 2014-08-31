#pragma once

#include <vector>

//Column-major order
class Matrix4f
{
public:
	Matrix4f();
	~Matrix4f();
	const Matrix4f& initIdentity();
	const Matrix4f& initTranslation(float x, float y, float z);
	const Matrix4f& initRotation(float x, float y, float z);
	const Matrix4f& initScale(float x, float y, float z);
	const Matrix4f& initProjection(float fov, float width, float height, float zNear, float zFar);
	friend Matrix4f operator* (const Matrix4f& a, const Matrix4f& b);
	float operator()(unsigned int col, unsigned int row) const;
	float& operator()(unsigned int col, unsigned int row);
	const std::vector<float>& getM() const;
	void setM(const std::vector<float>& m);

private:
	std::vector<float> m;
};

