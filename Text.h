#pragma once
#include<SDL_ttf.h>
#include<SDL.h>
#include<string>
#include<iostream>
using namespace std;

class Text{
public:
	Text(SDL_Renderer* renderer,const string& font_path, int font_size, string message_text, const SDL_Color color);
	void display(int x, int y, SDL_Renderer* renderer)const;
	static SDL_Texture* loadFont(SDL_Renderer* renderer,const string& font_path, int font_size,  string message_text, const SDL_Color color);

private:
	SDL_Texture* _text_texture = nullptr;
	mutable SDL_Rect _text_rect;
};