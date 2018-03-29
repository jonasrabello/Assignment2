#include <iostream>
#include <thread>
#include "SystemManager.h"
#include "MainScene.h"

#define SDL_SRCCOLORKEY	0x00001000

MainScene::MainScene() {
}

MainScene::~MainScene() {
}

void MainScene::Init() {

	// Get singleton of input and window
	input = static_cast<Input*>(core::SystemManager::GetInstance()->GetSystem(core::SystemType::INPUT));
	window = static_cast<Window*>(core::SystemManager::GetInstance()->GetSystem(core::SystemType::WINDOW));

	// Get window and get its width and height
	SDL_GetWindowSize(window->GetWindow(), &windowWidth, &windowHeight); // Get Window size in pixels

	// Insert one game object in the scene
	gameObjects.push_back(new scene::GameObject());

	// Set initial position and image to the game object
	gameObjects[0]->SetPosition(Vec3(0,0,0));
	gameObjects[0]->SetImage("Images/CLogo.bmp");
}

void MainScene::Update() {

	// Initialize game object coordenates
	int x = 0;
	int y = 0;
	int z = 0;

	for (int i = 0; i < gameObjects.size(); i++) {

		// Initialize the axis position
		x = 0;
		y = 0;
		z = 0;

		// Get size of the object and current position
		SDL_Rect rect = gameObjects[i]->GetRec();

		if (input->IsLeftPressed()) {
			if (rect.x > 0) {		// Check left border 
				x = -1;
			}
		}
		else if (input->IsrightKeyPressed()) {
			if ((rect.w + rect.x) < windowWidth) {	// Check right border
				x = 1;
			}
		}
		else if (input->IsupKeyPressed()) {
			if (rect.y > 0) {		// Check up border 
				y = -1;
			}
		}
		else if (input->IsdownKeyPressed()) {
			if ((rect.y + rect.h) < windowHeight) {	// Check bottom boarder
				y = 1;
			}
		}

		// Update game object position
		gameObjects[i]->Update(Vec3(x, y, z));
	}
}

void MainScene::Draw() const {

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window->GetWindow());

	//Fill the surface white
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0x66, 0x66));

	for (int i = 0; i < gameObjects.size(); i++) {

		// Get image from the object to be blited
		SDL_Surface* image = gameObjects[i]->GetImage();

		// Map the color key that will set as transparent
		Uint32 colorkey = SDL_MapRGB(image->format, 0xFF, 0x00, 0x00);

		// Set all pixels of color 0xFF, 0x00, 0x00 to be transparent
		SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);

		// Get the size and new position to be blited
		SDL_Rect rect = gameObjects[i]->GetRec();

		// Draw the game object image to the window
		SDL_BlitSurface(image, NULL, screenSurface, &rect);		// blit it to screen
	}

	//Update the surface
	SDL_UpdateWindowSurface(window->GetWindow());
}

bool MainScene::Shutdown() {

	//Destroy window
	SDL_DestroyWindow(window->GetWindow());

	return true;
}
