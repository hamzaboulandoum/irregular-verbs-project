#include "Window.h"
#include<SDL_image.h>
using namespace std;
SDL_Renderer*Window::renderer=nullptr;
Window::Window(const string& title, int width, int height)
	:_title(title), _width(width), _height(height)
{
	_closed = !init();
}
Window::~Window() {
	SDL_StopTextInput();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL INIT failed" << endl;
		return false;
	}
	if (IMG_Init(IMG_INIT_PNG)!= IMG_INIT_PNG) {
		cerr << "failed to initialize SDL_IMAGE:" << endl;
		return false;
	}

	if (TTF_Init() < 0) {
		cerr << "failed to initialize TTF:" << endl;
		return false;

	}
	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_width, _height,SDL_WINDOW_RESIZABLE);
	if (_window == NULL) {
		cerr << "failed to create window" << endl;
		return false;
	}

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
		cerr << "failed to create renderer" << endl;
		return false;
	}
	SDL_StartTextInput();

	return true;
}


void Window::pollEvents(SDL_Event &event)
{
	if (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			_closed = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				_closed = true;
				break;
			}
			break;
		default:
			break;
		}
	}
}


void Window::clear() const {
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

}


