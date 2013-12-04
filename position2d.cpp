/*
 * position2d
 * Method definitions
 */
#include "position2d.h"

/*
 * Vec2f
 */
Vec2f::Vec2f() {
	x = y = 0.f;
}

Vec2f::Vec2f(float x, float y) {
	this->x = x;
	this->y = y;
}

void
Vec2f::operator+=(const Vec2f &v) {
	x += v.x;
	y += v.y;
}

void
Vec2f::operator-=(const Vec2f &v) {
	x -= v.x;
	y -= v.y;
}

void
Vec2f::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
}
void
Vec2f::operator/=(float scalar) {
	x /= scalar;
	y /= scalar;
}


/*
 * Position2d
 */
Position2d::Position2d() : pt() {
	angle = 0.f;
}

Position2d::Position2d(const Point2d &pt, float angle) : pt(pt) {
	this->angle = angle;
}

/*
 * AxisAlignedBoundingRectangle
 */
AxisAlignedBoundingRectangle::AxisAlignedBoundingRectangle(float x, float y, float w, float h) :
	min(x, y),
	max(x + w, y + h)
{
}

AxisAlignedBoundingRectangle::AxisAlignedBoundingRectangle(const Point2d &min, const Point2d &max) : min(min), max(max) {
}

void
AxisAlignedBoundingRectangle::operator+=(const Vec2f &v) {
	min += v;
	max += v;
}

void
AxisAlignedBoundingRectangle::operator-=(const Vec2f &v) {
	min -= v;
	max -= v;
}
