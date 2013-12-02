#pragma once
/*
 * position2d
 * 2d position and orientation structures
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
};

typedef Vec2f Point2d;

struct Position2d {
	Point2d pt;
	float angle;

	Position2d();
	Position2d(const Point2d &pt, float angle);
};

struct AxisAlignedRectangle {
	Point2d min;
	Point2d max;

	AxisAlignedRectangle(float x, float y, float w, float h);
	AxisAlignedRectangle(const Point2d &min, const Point2d &max);
	void operator+=(const Vec2f &v);
	void operator-=(const Vec2f &v);
	float width() const { return max.x - min.x; }
	float height() const { return max.y - min.y; }
};
typedef AxisAlignedRectangle AAR;
typedef AxisAlignedRectangle Rect;

class Position2dHolder {
public:
	virtual const Position2d &getPosition() const = 0;
	virtual void moveBy(const Vec2f &shift) = 0;
};
