#pragma once

class Game;
class GLWindow;

class GameEngine
{
public:
	GameEngine();
	~GameEngine();
	void start(int width, int height, char* title);
	void stop();
	const double FRAME_CAP = 60;

private:
	void run();
	void render();
	void cleanUp();
	bool isRunning;
	Game *game;
	GLWindow *window;
};

