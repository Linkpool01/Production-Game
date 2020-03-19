#include "Collider.h"
#include "VMath.h"

using namespace MATH;
bool Collider::SphereSphereCollision(const Body& body1, const Body& body2)
{
	float distance = VMath::distance(body1.pos, body2.pos);

	if (distance < body1.radius + body2.radius) return true;

	return false;
}

void Collider::SphereSphereCollisionResponse(Body& body1, Body& body2)
{
	float e = 1.0f;
	Vec3 lineOfAction = body1.pos - body2.pos;
	Vec3 normalizeLineOfAction = VMath::normalize(lineOfAction);
	float v1p = VMath::dot(body1.vel, normalizeLineOfAction);
	float v2p = VMath::dot(body2.vel, normalizeLineOfAction);

	float v1pnew = (((body1.mass - e * body2.mass) * v1p) + ((1.0f + e) * body2.mass * v2p)) / (body1.mass + body2.mass);
	float v2pnew = (((body2.mass - e * body1.mass) * v2p) + ((1.0f + e) * body1.mass * v1p)) / (body1.mass + body2.mass);

	if (v1p - v2p > 0.0f) return;

	body1.vel += (v1pnew - v1p) * normalizeLineOfAction;

	body2.vel += (v2pnew - v2p) * normalizeLineOfAction;
	return;
}
