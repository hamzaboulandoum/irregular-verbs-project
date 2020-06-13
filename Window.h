#pragma once
#include<iostream>
#include<SDL.h>
#include<string>
#include<SDL_ttf.h>
#include<SDL_image.h>
using namespace std;
	class Window
	{
	public:
		Window(const string & title, int width, int height);
		~Window();
		inline bool isClosed()const {
			return _closed;
		}
		void pollEvents(SDL_Event& event);
		void clear()const;
		bool init();
		bool _closed = false;
	private:
		string _title;
		int _width=800;
		int _height=600;
		SDL_Window* _window=nullptr;
	public:
		static SDL_Renderer* renderer;
	};





