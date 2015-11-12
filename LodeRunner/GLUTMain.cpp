// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "Globals.h"
#include "cGame.h"

//Delete console
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

cGame *Game = &(cGame::getInstance());

/**
@w asdfasdf
@h asdfasdf
asdfasdfsadf
*/
void AppReshape(int w, int h)
{
	Game->Reshape(w, h);
}
void AppRender()
{
	Game->Render();
}
void AppKeyboard(unsigned char key, int x, int y)
{
	Game->ReadKeyboard(key, x, y, true);
}
void AppKeyboardUp(unsigned char key, int x, int y)
{
	Game->ReadKeyboard(key, x, y, false);
}
void AppSpecialKeys(int key, int x, int y)
{
	Game->ReadSpecialKeyboard(key, x, y, true);
}
void AppSpecialKeysUp(int key, int x, int y)
{
	Game->ReadSpecialKeyboard(key, x, y, false);
}
void AppMouse(int button, int state, int x, int y)
{
	Game->ReadMouse(button, state, x, y);
}
void AppIdle()
{
	if (!Game->Loop()) exit(0);
}

void main(int argc, char** argv)
{

	int res_x, res_y, pos_x, pos_y;

	//GLUT initialization
	glutInit(&argc, argv);

	//RGBA with double buffer
	glutInitDisplayMode(GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH);

	//Create centered window
	res_x = glutGet(GLUT_SCREEN_WIDTH);
	res_y = glutGet(GLUT_SCREEN_HEIGHT);
	pos_x = (res_x / 2) - (GAME_WIDTH /2);
	pos_y = (res_y / 2) - (GAME_HEIGHT /2);

	glutInitWindowPosition(pos_x, pos_y);
	glutInitWindowSize(GAME_WIDTH, GAME_HEIGHT);
	glutCreateWindow("2DGame");

	/*glutGameModeString("800x600:32");
	glutEnterGameMode();*/

	//Make the default cursor disappear
	//glutSetCursor(GLUT_CURSOR_NONE);

	//Register callback functions
	glutReshapeFunc(AppReshape);
	glutDisplayFunc(AppRender);
	glutKeyboardFunc(AppKeyboard);
	glutKeyboardUpFunc(AppKeyboardUp);
	glutSpecialFunc(AppSpecialKeys);
	glutSpecialUpFunc(AppSpecialKeysUp);
	glutMouseFunc(AppMouse);
	glutIdleFunc(AppIdle);

	//GLEW initialization
	GLint GlewInitResult = glewInit();
	if (GLEW_OK != GlewInitResult)
	{
		printf("ERROR: %s\n", glewGetErrorString(GlewInitResult));
		exit(EXIT_FAILURE);
	}

	//Game initializations
	Game->Init();

	//Application loop
	glutMainLoop();
}
