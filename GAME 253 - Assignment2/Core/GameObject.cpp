#include "GameObject.h"

namespace scene {

	GameObject::GameObject() {
	
	}

	GameObject::~GameObject() {
		// Cleaning
		gameObjectImage = nullptr;
		delete gameObjectImage;
	}

	void GameObject::Init() {

	}

	void GameObject::Update(const Vec3 gameObjectPos_) {
		// Update game object position
		gameObjectPos += gameObjectPos_;
	}

	void GameObject::Draw() const {

	}

	bool GameObject::Shutdown() {
		return true;
	}

	void GameObject::SetPosition(Vec3 gameObjectPos_) {
		// Set game object position
		gameObjectPos = gameObjectPos_;
	}

	void GameObject::SetImage(const char *gameObjectImage_) {
		// Load image in game object
		gameObjectImage = SDL_LoadBMP(gameObjectImage_);
	}

	SDL_Surface * GameObject::GetImage() {
		return gameObjectImage;
	}

	SDL_Rect GameObject::GetRec() {
		// Set information to the rect of the game object and return to it
		gameObjectRect.h = gameObjectImage->h;
		gameObjectRect.w = gameObjectImage->w;
		gameObjectRect.x = gameObjectPos.x;
		gameObjectRect.y = gameObjectPos.y;

		return gameObjectRect;
	}
}
