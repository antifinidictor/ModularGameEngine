#pragma once
/**
 * @file position3d
 * @author Nathan Heisey
 * @date 12/3/2013
 *
 * 3d position and orientation structures
 */

/** @struct Vec3f
 * Structure defining a 3D vector
 * @see Point3d
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

/** @typedef Point3d
 * Name for a position, as opposed to a movement vector, in 3D
 * @see Vec3f
 */
typedef Vec3f Point3d;

/** @struct Quaternion
 * Structure defining a quaternion, which will be used for all 3D rotations
 * As of version 0.0, it is largely unimplemented
 */
struct Quaternion {
	float x;
	float y;
	float z;
	float w;

	Quaternion();
	Quaternion(const Vec3f &axis, float angle);

	//TODO Finish implementing!
};

/** @struct AxisAlignedBoundingBox
 * Structure defining an axis-aligned rectangular prism
 * @see Vec3f
 * @see Box
 * @see AABB
 */
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

/** @typedef AABB
 * Short name for an axis aligned bounding box
 * @see AxisAlignedBoundingBox
 * @see Box
 */
typedef AxisAlignedBoundingBox AABB;

/** @typedef Box
 * Common name for an axis aligned bounding box
 * @see AxisAlignedBoundingBox
 * @see AABB
 */
typedef AxisAlignedBoundingBox Box;

/** @struct Position3d
 * Structure containing position and orientation information for 3D objects
 * @see Vec3f
 * @see Quaternion
 */
struct Position3d {
	Point3d pt;
	Quaternion ori;

	Position3d();
	Position3d(const Point3d &pt, const Quaternion &ori);
};

/** @class Position3dHolder
 * Abstract class for objects that have a 3D position
 * @see Position3d
 * @see Vec3f
 * @see Quaternion
 */
class Position3dHolder {
public:
	virtual const Position3d &getPosition() const = 0;
	virtual void moveBy(const Vec3f &shift) = 0;
	virtual void moveTo(const Vec3f &pos) = 0;
	virtual void rotateBy(const Quaternion &rot) = 0;
	virtual void rotateTo(const Quaternion &ori) = 0;
};
