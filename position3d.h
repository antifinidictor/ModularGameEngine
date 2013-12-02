#pragma once
/*
 * position3d
 * 3d position and orientation structures
 */

struct Vec3f {
	float x;
	float y;
	float z;

	Vec3f();
	Vec3f(float x, float y, float z);
	void operator+=(const Vec3f &v);
	void operator-=(const Vec3f &v);
	void operator*=(float scalar);
	float dot(const Vec3f &v) const;
	void cross(const Vec3f &v);
};
typedef Vec3f Point3d;

struct Quaternion {
	float x;
	float y;
	float z;
	float w;

	Quaternion();
	Quaternion(const Vec3f &axis, float angle);

	//Other operations will be added later
};

struct AxisAlignedBoundingBox {
	Point3d min;
	Point3d max;

	AxisAlignedBoundingBox();
	AxisAlignedBoundingBox(float x, float y, float z, float w, float h, float l);
	AxisAlignedBoundingBox(const Point3d &min, const Point3d &max);
	void operator+=(const Vec3f &v);
	void operator-=(const Vec3f &v);
	float width() const { return max.x - min.x; }
	float height() const { return max.y - min.y; }
	float length() const { return max.z - min.z; }
};
typedef AxisAlignedBoundingBox AABB;
typedef AxisAlignedBoundingBox Box;

struct Position3d {
	Point3d pt;
	Quaternion ori;

	Position3d();
	Position3d(const Point3d &pt, const Quaternion &ori);
};

class Position3dHolder {
public:
	virtual const Position3d &getPosition() const = 0;
	virtual void moveBy(const Vec3f &shift) = 0;
};
