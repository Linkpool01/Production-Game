#include "Ball.h"

Ball::Ball()
{

}

Ball::~Ball() 
{

}

bool Ball::OnCreate()
{
	return true;
}

void Ball:: OnDestroy() 
{

}

void Ball::Render()const
{

}

void Ball::HandleEvents(const SDL_Event& sdlEvent) 
{

}

void Ball::Update(const float deltaTime)
{
	Body::Update(deltaTime);
}