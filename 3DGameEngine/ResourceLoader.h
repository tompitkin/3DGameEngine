#pragma once

#include <string>
#include <vector>

class Mesh;
class Vertex;

class ResourceLoader
{
public:
	ResourceLoader();
	~ResourceLoader();
	static std::string loadShader(const std::string& fileName);
	static int loadMesh(const std::string& fileName, Mesh& mesh);

private:
	struct OBJ
	{
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
	};

	static void parseObjLine(char **line, OBJ& data);
};