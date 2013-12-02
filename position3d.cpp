/*
 * position3d
 * Method definitions for 3d position information
 */
#include "position3d.h"

/*
 * Vec3f
 */
Vec3f::Vec3f() {
	x = y = 0.f;
}

Vec3f::Vec3f(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void
Vec3f::operator+=(const Vec3f &v) {
	x += v.x;
	y += v.y;
	z += v.z;
}

void
Vec3f::operator-=(const Vec3f &v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

void
Vec3f::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

float
Vec3f::dot(const Vec3f &v) const {
	return x * v.x + y * v.y + z * v.z;
}

void
Vec3f::cross(const Vec3f &v) {
	//TODO
}

/*
 * Quaternion
 */
Quaternion::Quaternion() {
	//TODO
}

Quaternion::Quaternion(const Vec3f &axis, float angle) {
	//TODO
}

/*
 * AxisAlignedBoundingBox
 */
AxisAlignedBoundingBox::AxisAlignedBoundingBox() : min(), max() {
}

AxisAlignedBoundingBox::AxisAlignedBoundingBox(float x, float y, float z, float w, float h, float l) :
	min(x, y, z),
	max(x + w, y + h, z + l)
{
}

AxisAlignedBoundingBox::AxisAlignedBoundingBox(const Point3d &min, const Point3d &max) : min(min), max(max) {
}

void
AxisAlignedBoundingBox::operator+=(const Vec3f &v) {
	min += v;
	max += v;
}

void
AxisAlignedBoundingBox::operator-=(const Vec3f &v) {
	min -= v;
	max -= v;
}


/*
 * Position3d
 */
Position3d::Position3d() : pt(), ori() {
}

Position3d::Position3d(const Point3d &pt, const Quaternion &ori) : pt(pt), ori(ori) {
}
