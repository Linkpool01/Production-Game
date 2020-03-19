#include "Scene1.h"
#include <SDL.h>
#include <SDL_image.h>
Scene1::Scene1(SDL_Window* sdlWindow_){
	window = sdlWindow_;
}

Scene1::~Scene1(){
}

bool Scene1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0, 30.0, 0.0, 10.0, 0.0, 1.0);
	projection = ndc * ortho;


	jetSki = new Body(Vec3(0.0f, 1.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 328.0f);
	jetSkiImage = IMG_Load("JetSki.png");
	if (jetSki == nullptr || jetSkiImage == nullptr) {
		return false;
	}
	return true;
}

void Scene1::OnDestroy() {}

void Scene1::Update(const float time) {
	jetSki->Update(time);
}

void Scene1::Render() {
	Vec3 pos = jetSki->GetPos();
	Vec3 screenPos = projection * pos;
	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = static_cast<int>(screenPos.y);
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 100, 255));
	SDL_BlitSurface(jetSkiImage, nullptr, screenSurface, &dstrect);
	SDL_UpdateWindowSurface(window);
}

void Scene1::HandleEvents(const SDL_Event& event) {

}