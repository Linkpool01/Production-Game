#ifndef BODY_H
#define BODY_H
#include "Vector.h"

using namespace MATH;
	class Body {
		friend class Collider;
	protected:
		Vec3 pos;
		Vec3 vel;
		Vec3 accel;
		float mass;
		float radius = 1.0f;

	public:
		Body();
		Body(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
		~Body();
		void Update(const float deltaTime);
		void ApplyForce(Vec3 force);
		Vec3 GetPos();
	};

#endif