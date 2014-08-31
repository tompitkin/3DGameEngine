#include "Game.h"

#include <vector>
#include <iostream>
#include <string>
#include "Vector3f.h"
#include "Vector2f.h"
#include "Vertex.h"
#include "Input.h"
#include "ResourceLoader.h"
#include "Time.h"
#include "Matrix4f.h"


Game::Game()
{
	/*const Vertex dataV[] = { Vertex(Vector3f(-1, -1, 0)), Vertex(Vector3f(0, 1, 0)), Vertex(Vector3f(1, -1, 0)), Vertex(Vector3f(0, -1, 1)) };
	std::vector<Vertex> verts(dataV, dataV + sizeof(dataV) / sizeof(dataV[0]));

	const unsigned int dataI[] = { 0, 1, 3, 3, 1, 2, 2, 1, 0, 0, 2, 3};
	std::vector<unsigned int> indices(dataI, dataI + sizeof(dataI) / sizeof(dataI[0]));

	mesh.addVertices(verts, indices);*/

	ResourceLoader::loadMesh("bigmonkey.obj", mesh);

	shader.addVertexShader(ResourceLoader::loadShader("basicVert.vs"));
	shader.addFragmentShader(ResourceLoader::loadShader("basicFrag.fs"));
	shader.compile();

	shader.addUniform("transform");
}

Game::~Game()
{
}

void Game::input(const Input &input)
{
	if (input.getKeyDown(input.KEY_UP))
		std::cout << "We've just pressed up!\n";
	if (input.getKeyUp(input.KEY_UP))
		std::cout << "We've just released up!\n";
	if (input.getMouseDown(input.MOUSE_BUTTON_LEFT))
		std::cout << "We've just pressed the left mouse button at " << input.getMousePosition() << "!\n";
	if (input.getMouseUp(input.MOUSE_BUTTON_LEFT))
		std::cout << "We've just released the left mouse button!\n";
	if (input.getMouseDown(input.MOUSE_BUTTON_RIGHT))
		std::cout << "We've just pressed the right mouse button!\n";
	if (input.getMouseUp(input.MOUSE_BUTTON_RIGHT))
		std::cout << "We've just released the right mouse button!\n";
	if (input.getMouseDown(input.MOUSE_BUTTON_MIDDLE))
		std::cout << "We've just pressed the middle mouse button!\n";
	if (input.getMouseUp(input.MOUSE_BUTTON_MIDDLE))
		std::cout << "We've just released the middle mouse button!\n";
	if (input.getMouseDown(input.MOUSE_BUTTON_X1))
		std::cout << "We've just pressed the 4th mouse button!\n";
	if (input.getMouseUp(input.MOUSE_BUTTON_X1))
		std::cout << "We've just released the 4th mouse button!\n";
	if (input.getMouseDown(input.MOUSE_BUTTON_X2))
		std::cout << "We've just pressed the 5th mouse button!\n";
	if (input.getMouseUp(input.MOUSE_BUTTON_X2))
		std::cout << "We've just released the 5th mouse button!\n";
}

void Game::update()
{
	timePassed += (float)Time::getDelta();

	float sinWave = std::sin(timePassed);

	trans.setTranslation(sinWave, 0, 5);
	trans.setRotation(0, sinWave * 180, 0);
	//trans.setScale(0.5f, 0.5f, 0.5f);
}

void Game::render()
{
	shader.bind();
	shader.setUniform("transform", trans.getProjectedTransformation());
	mesh.draw();
}