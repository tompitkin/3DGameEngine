#include <Windows.h>
#include "GameEngine.h"

#ifdef _DEBUG
	#include <crtdbg.h>
	#ifndef DBG_NEW
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
		#define new DBG_NEW
	#endif
#endif

int main()
{
	#ifdef _DEBUG
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif

	GameEngine game;
	game.start(800, 600, "3DGameEngine");

	return 0;
}