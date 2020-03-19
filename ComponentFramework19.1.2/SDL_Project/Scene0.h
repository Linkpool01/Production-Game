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
	Body* ball1;
	Body* ball2;
	SDL_Surface* ballImage1;
	SDL_Surface* ballImage2;
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

