#include "Scene0.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Ball.h"
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 30.0, 0.0, 20.0, 0.0, 1.0);
	projection = ndc * ortho;

	ball1 = new Ball();
	ballImage1 = IMG_Load("Ball.jpg");
	if (ball1 == nullptr || ballImage1 == nullptr) {

		return false;
	}  

	ball2 = new Ball();
	ballImage2 = IMG_Load("Ball.jpg");
	if (ball2 == nullptr || ballImage2 == nullptr) {

		return false;
	}

	return true;
}

void Scene0::OnDestroy() {
}

void Scene0::Update(const float time) {
	ball1->Update(time);
}

void Scene0::Render() {
	Vec3 pos1 = ball1->GetPos();
	Vec3 pos2 = ball2->GetPos();
	Vec3 screenPos1 = projection * pos1;
	Vec3 screenPos2 = projection * pos2;
	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos1.x);
	dstrect.y = static_cast<int>(screenPos1.y);
	dstrect.x = static_cast<int>(screenPos2.x);
	dstrect.y = static_cast<int>(screenPos2.y);
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
	SDL_BlitSurface(ballImage1, nullptr, screenSurface, &dstrect);
	SDL_BlitSurface(ballImage2, nullptr, screenSurface, &dstrect);
	SDL_UpdateWindowSurface(window);
}

void Scene0::HandleEvents(const SDL_Event& event) {

}