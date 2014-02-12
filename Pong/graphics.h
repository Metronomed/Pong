#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <string>

struct SDL_Surface;
struct SDL_Rect;

// General graphics class for blitting to screen and storing images
class Graphics{
public:
	Graphics();
	~Graphics();

	void blitScreen(SDL_Surface* source,
		SDL_Rect* source_rect,
		SDL_Rect* destination_rect);

	SDL_Surface* loadImage(const std::string& filepath, bool black_transparency = false);

	void clear();
	void flip();
private:
	SDL_Surface* screen_;
};
#endif // GRAPHICS_H_