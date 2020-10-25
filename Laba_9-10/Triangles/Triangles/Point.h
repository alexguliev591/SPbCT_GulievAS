#pragma once
#ifndef POINT_H 
#define POINT_H


enum ORIENT
{
	LEFT, RIGHT, AHEAD, BEHIND, BETWEEN
};

class Triangle; 

class Point
{
public:
	Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
	void Show() const;
	void operator +=(const Point&);
	Point operator +(const Point&);
	Point operator -(const Point&);
	double Length() const; // определяет длину вектора точки в полярной системе координат
	ORIENT Classify(const Point&, const Point&)const; // определяет положение точки относительно вектора, заданного двумя точками
	bool InTriangle(const Triangle&) const; // определяет, находится ли точка внутри треугольника
public:
	double x, y;
};
#endif //POINT_H
