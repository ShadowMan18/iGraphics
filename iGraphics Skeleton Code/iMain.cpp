#include <bits/stdc++.h>
#include <iGraphics.h>
#include <windows.h>
using namespace std;

int screen_width, screen_height, soundcount = 0, max_sound = 50;

void getScreenDimension(int &width, int &height)
{
	RECT screen;
	GetWindowRect(GetDesktopWindow(), &screen);
	width = screen.right;
	height = screen.bottom;
}

void playsound(char filename[])
{
	char command[256];
	sprintf(command, "close sound%d", soundcount);
	mciSendString(command, NULL, 0, NULL);
	sprintf(command, "open \"%s\" type waveaudio alias sound%d", filename, soundcount);
	mciSendString(command, NULL, 0, NULL);
	sprintf(command, "play sound%d", soundcount);
	mciSendString(command, NULL, 0, NULL);
	soundcount = (soundcount + 1) % max_sound;
}

void iDraw()
{
	iClear();
}

void iMouse(int button, int state, int mx, int my)
{
}

void iMouseMove(int mx, int my)
{
}

void iPassiveMouseMove(int mx, int my)
{
}

void iKeyboard(unsigned char k)
{
}

void iSpecialKeyboard(unsigned char k)
{
}

int main()
{
	getScreenDimension(screen_width, screen_height);
	iInitialize(screen_width - 20, screen_height, "iGraphics");
	return 0;
}