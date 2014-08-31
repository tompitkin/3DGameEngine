#pragma once

#include <SDL.h>
#include <string>
#include "Input.h"

#define GLEW_STATIC
#define NO_STDIO_REDIRECT

class GLWindow
{
public:
	GLWindow(int width, int height, const std::string& title);
	~GLWindow();
	void update();
	void render();

	inline bool isCloseRequested() const		{ return close; }
	inline int getWidth() const					{ return width; }
	inline int getHeight() const				{ return height; }
	inline std::string getTitle() const			{ return title; }
	inline const Input& getInput() const		{ return input; }

private:
	int width;
	int height;
	std::string title;
	bool close;
	Input input;
	SDL_Window* window;
	SDL_GLContext glContext;
};