#pragma warning(disable:4996)
#include "cGame.h"

cGame::cGame(void)
{
}

cGame::~cGame(void)
{
}

bool cGame::Init(int lvl)
{
	time = 1.0f;
	level = 1;

	//Graphics initialization
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	visible_area.left = 0;
	visible_area.right = 180;
	visible_area.bottom = 0;
	visible_area.top = 600;

	glOrtho(visible_area.left, visible_area.right, visible_area.bottom, visible_area.top, 3, -100);
	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_ALPHA_TEST);
	glEnable(GL_DEPTH_TEST);

	//Texture initialization
	if (!Data.Load())printf("Some image may missing");

	int tex_w, tex_h;
	Data.GetSize(IMG_TILESET, &tex_w, &tex_h);
	Scene.LoadLevel(1, tex_w, tex_h);

	//Sound initialization
	Sound.Load();
	if (lvl == 1) Sound.Play(SOUND_AMBIENT1);

	//Shader initialization
	Shader.Load();

	return true;
}

bool cGame::LoadDynamicLayer(int lvl)
{

	return true;
}

bool cGame::Loop()
{
	bool res = true;

	res = Process();
	if (res) Render();

	return true;
}

void cGame::Finalize()
{
}

//Input
void cGame::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
}

void cGame::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{

}

void cGame::ReadMouse(int button, int state, int x, int y)
{
}

//Process
bool cGame::Process()
{
	return true;
}

void cGame::UpdateCamera(int h1, int h2)
{

}

void cGame::Reshape(int w, int h) {

}

//Output
void cGame::Render()
{
	int tex_w, tex_h;
	int tex_w2, tex_h2;
	bool run = true;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	//Activacion de shaders
	if (time > 0.0f)
	{
		glActiveTexture(GL_TEXTURE0);
		Shader.Attach(SHADER_FADE_F);
		Shader.Activate();
		Shader.SetUniform("time", time);
		Shader.SetUniform("tex", 0);
		Shader.SetUniform("flatcolor", 0);
	}

	//Pintado
	Data.GetSize(IMG_TILESET, &tex_w, &tex_h);
	Scene.Draw(Data.GetID(IMG_TILESET), tex_w, tex_h, run);

	glEnable(GL_BLEND);			   // Turn Blending On
								   //glDisable(GL_DEPTH_TEST);    // Turn Depth Testing Off
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	


	glDisable(GL_BLEND);          // Turn Blending Off
								  //glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glAlphaFunc(GL_GREATER, 0.05f);

	if (time > 0.0f)
	{
		Shader.Detach(SHADER_FADE_F); 
		time -= 0.01f;
		Shader.Deactivate();
	}

	glutSwapBuffers();
}
