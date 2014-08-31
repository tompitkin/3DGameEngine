#include "ResourceLoader.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <fcntl.h>
#include <io.h>
#include "Mesh.h"
#include "Vertex.h"

ResourceLoader::ResourceLoader()
{
}

ResourceLoader::~ResourceLoader()
{
}

std::string ResourceLoader::loadShader(const std::string& fileName)
{
	std::string shaderSource;
	std::ifstream fileIn;
	std::ostringstream filePath;

	filePath << "./res/shaders/" << fileName;
	fileIn.open(filePath.str());
	
	if (fileIn.is_open())
	{
		std::string line;
		while (std::getline(fileIn, line))
		{
			shaderSource.append(line);
			shaderSource.append("\n");
		}
		fileIn.close();
	}

	return shaderSource;
}

int ResourceLoader::loadMesh(const std::string& fileName, Mesh& mesh)
{
	std::string ext(fileName.substr(fileName.find_last_of('.') + 1));

	if (ext != "obj")
	{
		std::cerr << "ERROR: File format not supported for mesh data: " << ext << '\n';
		return 1;
	}

	std::ostringstream filePath;
	filePath << "./res/models/" << fileName;

	static const int BUFFER_SIZE = 16 * 1024;
	int fd = -1;
	_sopen_s(&fd, filePath.str().c_str(), _O_RDONLY, _SH_DENYNO, 0);

	if (fd == -1)
	{
		std::cerr << "ERROR: Could not open file for mesh data: " << fileName << '\n';
		return 1;
	}

	OBJ data;
	char buf[BUFFER_SIZE+1];
	while (size_t bytes_read = _read(fd, buf, BUFFER_SIZE))
	{
		if (bytes_read == (size_t)-1)
		{
			std::cerr << "ERROR: Could not read file for mesh data: " << fileName << '\n';
			return 1;
		}
		if (!bytes_read)
			break;

		buf[bytes_read] = '\0';

		char *line = buf;
		for (char *end = (char*)memchr(buf, '\n', bytes_read); end && (end = (char*)memchr(end, '\n', (buf + bytes_read) - end)); ++end)
		{
			*end = '\0';
			parseObjLine(&line, data);
			line = end+1;
		}
		
		if (bytes_read == BUFFER_SIZE)
			_lseek(fd, (line - buf) - BUFFER_SIZE, SEEK_CUR);
		else
			parseObjLine(&line, data);
	}

	_close(fd);

	mesh.addVertices(data.vertices, data.indices);

	return 0;
}

void ResourceLoader::parseObjLine(char **line, OBJ& data)
{
	char *nextToken;
	char *token = strtok_s(*line, " ", &nextToken);

	if (token)
	{
		if (!strcmp(token, "v"))
		{
			float vals[3];
			vals[0] = (float)atof(strtok_s(NULL, " ", &nextToken));
			vals[1] = (float)atof(strtok_s(NULL, " ", &nextToken));
			vals[2] = (float)atof(strtok_s(NULL, " ", &nextToken));
			data.vertices.push_back(Vertex(Vector3f(vals[0], vals[1], vals[2])));
		}
		else if (!strcmp(token, "f"))
		{
			data.indices.push_back(atoi(strtok_s(NULL, " ", &nextToken)) - 1);
			data.indices.push_back(atoi(strtok_s(NULL, " ", &nextToken)) - 1);
			data.indices.push_back(atoi(strtok_s(NULL, " ", &nextToken)) - 1);
		}
	}
}