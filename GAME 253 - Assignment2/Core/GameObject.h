#ifndef GAMEOBJECT_
#define GAMEOBJECT_

#include "SDL.H"
#include "Vector.h"

namespace scene {

	class GameObject {

	private:
		Vec3 gameObjectPos;
		SDL_Rect gameObjectRect;
		SDL_Surface* gameObjectImage;

	public:
		GameObject();
		~GameObject();

		void Init();
		void Update(const Vec3 gameObjectPos_);
		void Draw() const;
		bool Shutdown();

		void SetPosition(Vec3 gameObjectPos_);		
		void SetImage(const char *gameObjectImage_);
		SDL_Surface* GetImage();
		SDL_Rect GetRec();
	};

}
#endif // GAMEOBJECT_
