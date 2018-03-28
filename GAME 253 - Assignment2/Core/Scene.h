#ifndef SCENE_
#define SCENE_

#include <vector>
#include "GameObject.h"

namespace scene {

	class Scene {

	private:
		std::vector<GameObject*> gameObjects;

	public:
		Scene();
		virtual ~Scene();

		virtual void Init();
		virtual void Update();
		virtual void Draw() const;
		virtual bool Shutdown();
	};

}
#endif // !SCENE_
