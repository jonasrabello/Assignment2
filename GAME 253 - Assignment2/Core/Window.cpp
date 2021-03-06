#include <iostream>
#include "Window.h"

namespace core {

	// Set m_instance nullptr
	std::unique_ptr<Window> Window::m_instance = nullptr;

	Window::Window() : System(SystemType::WINDOW) {  // initialize System because it needs ads base class
	}


	Window::~Window() {

		// Cleaning
		window = nullptr;
		delete window;

		screenSurface = nullptr;
		delete screenSurface;
	}

	int Window::Init() {

		//Create window
		window = SDL_CreateWindow("Assignment 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {

			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return WINDOW_INIT_ERROR;
		}
		else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);
		}

		return 0;
	}

	SDL_Window * Window::GetWindow() {
		return window;
	}
}