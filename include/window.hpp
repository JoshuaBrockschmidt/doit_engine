#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL2/SDL.h>

namespace DOIT {
class Window {
public:
	const Uint32 flags = SDL_WINDOW_OPENGL;

	Window(unsigned int w, unsigned int h, std::string _title);
	~Window();

	/**
	   Cleanup and close.
	*/
	void close();

	/**
	   Render everything OpenGL has drawn.
	*/
	void render();

	/**
	   Sets the size of a window.

	   @param w New width of window.
	   @param h New height of window.
	*/
	void setSize(unsigned int w, unsigned int h);

	/**
	   Sets the title of a window.

	   @param newTitle New title of window.
	*/
	void setTitle(std::string newTitle);

	/**
	   Returns the width of a window
	*/
	unsigned int getWidth();

	/**
	   Returns the width of a window
	*/
	unsigned int getHeight();

	/**
	   Returns the title of a window
	*/
	std::string getTitle();

private:
        SDL_Window* win;
	unsigned int width;
	unsigned int height;
	std::string title;
};
}

#endif
