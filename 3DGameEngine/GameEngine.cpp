#include "GameEngine.h"

#include <iostream>
#include "GLWindow.h"
#include "Time.h"
#include "Game.h"
#include "Input.h"
#include "RenderUtil.h"

GameEngine::GameEngine()
{
	isRunning = false;
	window = NULL;
}

GameEngine::~GameEngine()
{
	cleanUp();
}

void GameEngine::start(int width, int height, char* title)
{
	if (isRunning)
		return;

	Transform::setProjection(70.0f, (float)width, (float)height, 0.1f, 1000.0f);

	window = new GLWindow(width, height, title);

	#ifdef _DEBUG
		std::cout << "GLEW Version: " << (char*)glewGetString(GLEW_VERSION) << '\n';
		std::cout << "OpenGL Version: " << RenderUtil::getOpenGLVersion() << '\n';
	#endif

	RenderUtil::initGraphics();

	game = new Game();

	run();
}

void GameEngine::stop()
{
	if (!isRunning)
		return;

	isRunning = false;
}

void GameEngine::run()
{
	Time::startTime();

	#ifdef _DEBUG
		unsigned _int32 frames = 0;
		long frameCounter = 0;
	#endif

	isRunning = true;

	const double frameTime = 1.0 / FRAME_CAP;

	_int64 lastTime = Time::getTime();
	double unprocessedTime = 0;

	while (isRunning)
	{
		bool frameUpdated = false;

		_int64 startTime = Time::getTime();
		double passedTime = Time::getTimePassedNano(startTime, lastTime);
		lastTime = startTime;

		unprocessedTime += passedTime / (double)Time::SECOND;

		#ifdef _DEBUG
			frameCounter += (long)passedTime;
		#endif

		while (unprocessedTime > frameTime)
		{
			frameUpdated = true;

			unprocessedTime -= frameTime;

			Time::setDelta(frameTime);

			window->update();

			if (window->isCloseRequested())
				stop();

			game->input(window->getInput());
			game->update();

			#ifdef _DEBUG
				if (frameCounter >= Time::SECOND)
				{
					std::cout << frames << '\n';
					frames = 0;
					frameCounter = 0;
				}
			#endif
		}
		if (frameUpdated)
		{
			render();

			#ifdef _DEBUG
				frames++;
			#endif
		}
		else
			Sleep(1);
	}

	cleanUp();
}

void GameEngine::render()
{
	RenderUtil::clearScreen();
	game->render();
	window->render();
}

void GameEngine::cleanUp()
{
	delete game;
	game = NULL;

	if (window)
	{
		delete window;
		window = NULL;
	}
}
