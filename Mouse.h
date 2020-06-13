#pragma once
#include<SDL.h>
#include<iostream>
using namespace std;
class Mouse
{
private:
public:
	void pollevents(SDL_Event& event);
	bool end = 0;
	bool check=0;
private:
	int _positionClick_X = 0;
	int _positionClick_Y = 0;


};

