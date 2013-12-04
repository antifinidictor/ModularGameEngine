#pragma once
/**
 * @file position2d
 * @author Nathan Heisey
 * @date 12/3/2013
 *
 * 2d position and orientation structures and classes
 */

/** @struct Vec2f
 * Structure defining a 2D vector or a 2D point.
 * @see Point2d
 */
struct Vec2f {
	float x;
	float y;

	//Operations
	Vec2f();
	Vec2f(float x, float y);

	void operator+=(const Vec2f &v);
	void operator-=(const Vec2f &v);
	void operator*=(float scalar);
	void operator/=(float scalar);
};

/** @typedef Point2d
 * Name for a position, as opposed to a movement vector, in 2D
 * @see Vec2f
 */
typedef Vec2f Point2d;

/** @struct Position2d
 * Structure holding a position and an orientation.
 * @see Vec2f
 */
struct Position2d {
	Point2d pt;
	float angle;

	Position2d();
	Position2d(const Point2d &pt, float angle);
};

/** @struct AxisAlignedBoundingRectangle
 * Structure defining an axis-aligned rectangle
 * @see Vec2f
 * @see AABR
 * @see Rect
 */
struct AxisAlignedBoundingRectangle {
	Point2d min;
	Point2d max;

	AxisAlignedBoundingRectangle(float x, float y, float w, float h);
	AxisAlignedBoundingRectangle(const Point2d &min, const Point2d &max);
	void operator+=(const Vec2f &v);
	void operator-=(const Vec2f &v);
	float width() const { return max.x - min.x; }
	float height() const { return max.y - min.y; }
};

/** @typedef AABR
 * Short name for an axis aligned bounding rectangle
 * @see AxisAlignedBoundingRectangle
 * @see Rect
 */
typedef AxisAlignedBoundingRectangle AABR;

/** @typedef Rect
 * Common name for an axis aligned bounding rectangle
 * @see AxisAlignedBoundingRectangle
 * @see AABR
 */
typedef AxisAlignedBoundingRectangle Rect;

/** @class Position2dHolder
 * Abstract class for objects that have a 2D position
 * @see Position2d
 * @see Vec2f
 */
class Position2dHolder {
public:
	virtual const Position2d &getPosition() const = 0;
	virtual void moveBy(const Vec2f &shift) = 0;
	virtual void moveTo(const Vec2f &pos) = 0;
	virtual void rotateBy(float angle) = 0;
	virtual void rotateTo(float angle) = 0;
};
