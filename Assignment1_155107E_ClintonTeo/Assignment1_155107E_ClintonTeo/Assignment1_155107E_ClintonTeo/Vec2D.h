#ifndef VEC2D_H
#define VEC2D_H

struct Vec2D
{
public:
	Vec2D();
	Vec2D(double xAxis, double yAxis);
	~Vec2D();
	double x;
	double y;
};

#endif