#ifndef MAINSCENE_
#define MAINSCENE_

#include "Vector.h"
#include "Input.h"
#include "Window.h"
#include "Engine.h"
#include <Scene.h>

using namespace core;

namespace scene {
	class Scene;
}

class MainScene : public scene::Scene {

private:
	std::vector<scene::GameObject*> gameObjects;

	int windowWidth;
	int windowHeight;

	Window* window;
	Input* input;

public:
	MainScene();
	virtual ~MainScene();

	void Init() override;
	void Update() override;
	void Draw() const override;
	bool Shutdown() override;

};
#endif // !MAINSCENE_




