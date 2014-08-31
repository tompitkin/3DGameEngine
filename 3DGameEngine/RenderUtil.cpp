#include "RenderUtil.h"

#include <GL\glew.h>
#include <sstream>

void RenderUtil::clearScreen()
{
	//TODO Stencil Buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderUtil::initGraphics()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);

	//TODO Depth Clamp

	glEnable(GL_FRAMEBUFFER_SRGB);
}

std::string RenderUtil::getOpenGLVersion()
{
	GLint glVersion[2];
	glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);

	std::ostringstream sstr;
	sstr << glVersion[0] << "." << glVersion[1];
	
	return sstr.str();
}