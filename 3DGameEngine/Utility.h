#pragma once

#include <vector>

class Vertex;

#define PI 3.1415926535897932385

namespace Utils
{
	void createFloatBuffer(const std::vector<Vertex>& vertices, std::vector<float>& buffer);

	template <typename T> inline T clamp(const T& value, const T& lower, const T&upper)
	{
		return max(lower, min(value, upper));
	}

	inline float toRadians(float degrees)
	{
		return degrees * (float)PI / 180.0f;
	}
}