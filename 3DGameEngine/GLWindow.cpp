#include "GLWindow.h"

#include <GL\glew.h>
#include <iostream>
#include "Transform.h"

#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")

GLWindow::GLWindow(int width, int height, const std::string& title) : input(this)
{
	this->width = width;
	this->height = height;
	this->title = title;
	close = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		std::cerr << "SDL initialization failed.\n";

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	glContext = SDL_GL_CreateContext(window);

	SDL_GL_SetSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cerr << "GLEW initialization failed.\n";
}

GLWindow::~GLWindow()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GLWindow::update()
{
	input.clearKeyUpDown();
	input.clearMouseUpDown();

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_WINDOWEVENT)
		{
			switch (e.window.event)
			{
			case SDL_WINDOWEVENT_RESIZED:
				Transform::setProjectionWindow((float)e.window.data1, e.window.data2 == 0 ? 1.0f : (float)e.window.data2);
				glViewport(0, 0, (GLsizei)e.window.data1, e.window.data2 == 0 ? 1 : (GLsizei)e.window.data2);
				break;
			case SDL_WINDOWEVENT_CLOSE:
				close = true;
				break;
			default:
				break;
			}
		}
		else if (e.type == SDL_MOUSEMOTION)
		{
			input.setMouseX(e.motion.x);
			input.setMouseY(e.motion.y);
		}
		else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
		{
			int value = e.key.keysym.scancode;
			input.setKey(value, true);
			input.setKeyDown(value, true);
		}
		else if (e.type == SDL_KEYUP && e.key.repeat == 0)
		{
			int value = e.key.keysym.scancode;
			input.setKey(value, false);
			input.setKeyUp(value, true);
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int value = e.button.button;
			input.setMouse(value, true);
			input.setMouseDown(value, true);
		}
		else if (e.type == SDL_MOUSEBUTTONUP)
		{
			int value = e.button.button;
			input.setMouse(value, false);
			input.setMouseUp(value, true);
		}
	}
}

void GLWindow::render()
{
	SDL_GL_SwapWindow(window);
}
