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
	Matrix4 ortho = MMath::orthographic(-10.0, 30.0, -10.0, 50.0, 0.0, 1.0);
	projection = ndc * ortho;

	star1 = new Ball();
	star1->mass = 100.0f;
	star1->pos = Vec3(5.0f, 10.0f, 0.0f);
	starImage1 = IMG_Load("Star.jpg");
	if (star1 == nullptr || starImage1 == nullptr) {

		return false;
	}

	star2 = new Ball();
	star2->mass = 150.0f;
	star2->pos = Vec3(15.0f, 25.0f, 0.0f);
	starImage2 = IMG_Load("Star.jpg");
	if (star2 == nullptr || starImage2 == nullptr) {

		return false;
	}

	planet = new Ball();
	planet->mass = 1.0f;
	planet->pos = Vec3(10.0f, 20.0f, 0.0f);
	planet->vel = Vec3(-1.8f, 5.0f, 0.0f);
	planet->accel = Vec3(1.0);
	planetImage = IMG_Load("Planet.jpg");
	if (planet == nullptr || planetImage == nullptr) {

		return false;
	}

	return true;
}

void Scene0::OnDestroy() {
}

void Scene0::Update(const float time) {
	Vec3 PS1vec = star1->pos - planet->pos;
	float r1 = sqrt((PS1vec.x * PS1vec.x) + (PS1vec.y * PS1vec.y));
	float Fg1mag = (1.0f * planet->mass * star1->mass) / (r1 * r1);
	Vec3 PS1norm = PS1vec / r1;
	Vec3 Fg1vec = Fg1mag * PS1norm;
	
	Vec3 PS2vec = star2->pos - planet->pos;
	float r2 = sqrt((PS2vec.x * PS2vec.x) + (PS2vec.y * PS2vec.y));
	float Fg2mag = (1.0f * planet->mass * star2->mass) / (r2 * r2);
	Vec3 PS2norm = PS2vec / r2;
	Vec3 Fg2vec = Fg2mag * PS2norm;

	Vec3 Fnet = Fg1vec + Fg2vec;

	planet->ApplyForce(Fnet);

	planet->Update(time);
}

void Scene0::Render() {
	Vec3 pos1 = star1->GetPos();
	Vec3 pos2 = star2->GetPos();
	Vec3 pos3 = planet->GetPos();
	Vec3 screenPos1 = projection * pos1;
	Vec3 screenPos2 = projection * pos2;
	Vec3 screenPos3 = projection * pos3;
	SDL_Rect dstrect1;
	SDL_Rect dstrect2;
	SDL_Rect dstrect3;
	dstrect1.x = static_cast<int>(screenPos1.x);
	dstrect1.y = static_cast<int>(screenPos1.y);
	dstrect2.x = static_cast<int>(screenPos2.x);
	dstrect2.y = static_cast<int>(screenPos2.y);
	dstrect3.x = static_cast<int>(screenPos3.x);
	dstrect3.y = static_cast<int>(screenPos3.y);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));
	SDL_BlitSurface(starImage1, nullptr, screenSurface, &dstrect1);
	SDL_BlitSurface(starImage2, nullptr, screenSurface, &dstrect2);
	SDL_BlitSurface(planetImage, nullptr, screenSurface, &dstrect3);
	SDL_UpdateWindowSurface(window);
}

void Scene0::HandleEvents(const SDL_Event& event) {

}