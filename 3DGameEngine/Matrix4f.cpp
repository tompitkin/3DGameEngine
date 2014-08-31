#include "Matrix4f.h"

#include "Utility.h"

Matrix4f::Matrix4f() : m(16, 0)
{
}

Matrix4f::~Matrix4f()
{
}

const Matrix4f& Matrix4f::initIdentity()
{
	m[0] = 1;	m[1] = 0;	 m[2] = 0;	m[3] = 0;
	m[4] = 0;	m[5] = 1;	 m[6] = 0;	m[7] = 0;
	m[8] = 0;	m[9] = 0;	 m[10] = 1;	m[11] = 0;
	m[12] = 0;	m[13] = 0;	 m[14] = 0;	m[15] = 1;

	return *this;
}

const Matrix4f& Matrix4f::initTranslation(float x, float y, float z)
{
	m[0] = 1;	m[1] = 0;	 m[2] = 0;	m[3] = x;
	m[4] = 0;	m[5] = 1;	 m[6] = 0;	m[7] = y;
	m[8] = 0;	m[9] = 0;	 m[10] = 1;	m[11] = z;
	m[12] = 0;	m[13] = 0;	 m[14] = 0;	m[15] = 1;

	return *this;
}

const Matrix4f& Matrix4f::initRotation(float x, float y, float z)
{
	Matrix4f rotX;
	Matrix4f rotY;
	Matrix4f rotZ;

	x = Utils::toRadians(x);
	y = Utils::toRadians(y);
	z = Utils::toRadians(z);

	rotX.m[0] = 1;				rotX.m[1] = 0;				rotX.m[2] = 0;				rotX.m[3] = 0;
	rotX.m[4] = 0;				rotX.m[5] = std::cos(x);	rotX.m[6] = -std::sin(x);	rotX.m[7] = 0;
	rotX.m[8] = 0;				rotX.m[9] = std::sin(x);	rotX.m[10] = std::cos(x);	rotX.m[11] = 0;
	rotX.m[12] = 0;				rotX.m[13] = 0;				rotX.m[14] = 0;				rotX.m[15] = 1;

	rotY.m[0] = std::cos(y);	rotY.m[1] = 0;				rotY.m[2] = -std::sin(y);	rotY.m[3] = 0;
	rotY.m[4] = 0;				rotY.m[5] = 1;				rotY.m[6] = 0;				rotY.m[7] = 0;
	rotY.m[8] = std::sin(y);	rotY.m[9] = 0;				rotY.m[10] = std::cos(y);	rotY.m[11] = 0;
	rotY.m[12] = 0;				rotY.m[13] = 0;				rotY.m[14] = 0;				rotY.m[15] = 1;

	rotZ.m[0] = std::cos(z);	rotZ.m[1] = -std::sin(z);	rotZ.m[2] = 0;				rotZ.m[3] = 0;
	rotZ.m[4] = std::sin(z);	rotZ.m[5] = std::cos(z);	rotZ.m[6] = 0;				rotZ.m[7] = 0;
	rotZ.m[8] = 0;				rotZ.m[9] = 0;				rotZ.m[10] = 1;				rotZ.m[11] = 0;
	rotZ.m[12] = 0;				rotZ.m[13] = 0;				rotZ.m[14] = 0;				rotZ.m[15] = 1;

	m = (rotZ * rotY * rotX).getM();

	return *this;
}

const Matrix4f& Matrix4f::initScale(float x, float y, float z)
{
	m[0] = x;	m[1] = 0;	 m[2] = 0;	m[3] = 0;
	m[4] = 0;	m[5] = y;	 m[6] = 0;	m[7] = 0;
	m[8] = 0;	m[9] = 0;	 m[10] = z;	m[11] = 0;
	m[12] = 0;	m[13] = 0;	 m[14] = 0;	m[15] = 1;

	return *this;
}

const Matrix4f& Matrix4f::initProjection(float fov, float width, float height, float zNear, float zFar)
{
	float ar = width / height;
	float tanHalfFOV = std::tan(Utils::toRadians(fov / 2.0f));
	float zRange = zNear - zFar;

	m[0] = 1.0f / (tanHalfFOV * ar);	m[1] = 0;							m[2] = 0;							m[3] = 0;
	m[4] = 0;							m[5] = 1.0f / tanHalfFOV;	m[6] = 0;							m[7] = 0;
	m[8] = 0;							m[9] = 0;							m[10] = (-zNear - zFar) / zRange;	m[11] = 2 * zFar * zNear / zRange;
	m[12] = 0;							m[13] = 0;							m[14] = 1;							m[15] = 0;

	return *this;
}

Matrix4f operator* (const Matrix4f& a, const Matrix4f& b)
{
	Matrix4f res;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			res.m[i * 4 + j] =	a.m[i * 4 + 0] * b.m[0 * 4 + j] +
								a.m[i * 4 + 1] * b.m[1 * 4 + j] +
								a.m[i * 4 + 2] * b.m[2 * 4 + j] +
								a.m[i * 4 + 3] * b.m[3 * 4 + j];
		}
	}

	return res;
}

float Matrix4f::operator()(unsigned int col, unsigned int row) const
{
	return m[col * 4 + row];
}

float& Matrix4f::operator()(unsigned int col, unsigned int row)
{
	return m[col * 4 + row];
}

const std::vector<float>& Matrix4f::getM() const
{
	return m;
}

void Matrix4f::setM(const std::vector<float>& m)
{
	this->m.assign(m.begin(), m.end());
}