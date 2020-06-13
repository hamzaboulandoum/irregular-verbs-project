#include "Rect.h"
Rect::Rect(int h, int w, int x, int y, const string& image_path)
	: _w(w), _h(h), _x(x - w / 2), _y(y - h / 2),end(0)
{
	
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {

		cerr << "failed to create surface:" << endl;
	}
	_tennis_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);

	if (!_tennis_texture) {
		cerr << "failed to initialize Texture" << endl;
	}
	SDL_FreeSurface(surface);
}
Rect::~Rect() {
	end = 0;
	SDL_DestroyTexture(_tennis_texture);
}
void Rect::draw() {
	SDL_Rect rect = { _x,_y,_w,_h };
	if (_tennis_texture) {
		SDL_RenderCopy(Window::renderer, _tennis_texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Window::renderer, _red, _green, _blue, _alpha);
		SDL_RenderFillRect(Window::renderer, &rect);
	}
}
void Rect::pollEvents(Window& window, SDL_Event& event) {
	switch (event.type) {
	case SDL_MOUSEBUTTONUP:
		if (event.button.button == SDL_BUTTON_LEFT) {
			//on recupere les donnee du curseur
			//_positionClick_X = event.button.x;
			//_positionClick_Y = event.button.y;
			bool cal = event.button.x > (_x) && event.button.x < (_x + _w) && event.button.y>(_y) && event.button.y < (_y + (_h));
			if (cal) {
				end = 1;
			}
			else {
				end = 0;
			}

		}
		else {
			end = 0;
		}
		break;
	}

}