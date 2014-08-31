#pragma once

#include "Mesh.h"
#include "Shader.h"
#include "Transform.h"

class Input;

class Game
{
public:
	Game();
	~Game();
	void input(const Input &input);
	void update();
	void render();

private:
	Mesh mesh;
	Shader shader;
	Transform trans;
	float timePassed = 0.0f;
};

