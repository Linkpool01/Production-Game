#ifndef SCENE0_H
#define SCENE0_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Body.h"

using namespace MATH;

class Scene0 : public Scene {
private:
	SDL_Window *window;
	Body* star1;
	Body* star2;
	Body* planet;
	SDL_Surface* starImage1;
	SDL_Surface* starImage2;
	SDL_Surface* planetImage;
	Matrix4 projection;
	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
};

#endif

