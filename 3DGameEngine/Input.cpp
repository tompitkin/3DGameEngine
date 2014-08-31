#include "Input.h"

#include <Windows.h>
#include "GLWindow.h"

Input::Input(const GLWindow *window)
{
	this->window = window;
	mouseX = 0;
	mouseY = 0;

	memset(input, false, NUM_KEYS * sizeof(bool));
	memset(downKey, false, NUM_KEYS * sizeof(bool));
	memset(upKey, false, NUM_KEYS * sizeof(bool));
	memset(mouseInput, false, NUM_MOUSEBUTTONS * sizeof(bool));
	memset(downMouse, false, NUM_MOUSEBUTTONS * sizeof(bool));
	memset(upMouse, false, NUM_MOUSEBUTTONS * sizeof(bool));
}

Input::~Input()
{
}

void Input::SetCursor(bool visible) const
{
	SDL_ShowCursor(visible);
}

void Input::clearKeyUpDown()
{
	memset(downKey, false, NUM_KEYS * sizeof(bool));
	memset(upKey, false, NUM_KEYS * sizeof(bool));
}

void Input::clearMouseUpDown()
{
	memset(downMouse, false, NUM_MOUSEBUTTONS * sizeof(bool));
	memset(upMouse, false, NUM_MOUSEBUTTONS * sizeof(bool));
}