#ifndef BALL_H
#define BALL_H
#include "GameObject.h"
#include "Body.h"
#include <SDL.h>
class Ball : public Body, public GameObject
{
public:
	Ball();
	~Ball();
	bool OnCreate();
	void OnDestroy();
	void Render()const;
	void HandleEvents(const SDL_Event& sdlEvent);
	void Update(const float deltaTime);
};

#endif