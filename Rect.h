#pragma once
#include "Window.h"
#include<SDL_image.h>
#include "Input.h"
class Rect
{
public:
//	Rect(int h, int w, int x, int y, int red, int green, int blue, int alpha);
	Rect(int h, int w, int x, int y, const string	&image_path);
	~Rect();
	
	void draw();
	void pollEvents(Window& window,SDL_Event& event);
	bool end = 0;
	bool check = 0;
	bool QUIT = false;
private:
	int _positionClick_X = 0;
	int _positionClick_Y = 0;
	int _w, _h;
	int _x, _y;
	int _red, _green, _blue, _alpha;
	SDL_Texture* _tennis_texture=nullptr;
};

