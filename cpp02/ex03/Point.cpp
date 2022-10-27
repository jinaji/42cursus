#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << x << std::endl;
	std::cout << y << std::endl;
}

Point::Point(float x, float y) : x(Fixed(x)), y(Fixed(y))
{
	std::cout << x << std::endl;
	std::cout << y << std::endl;
}

Point::Point(const Point& point)
{
	*this = point;
}

int Point::operator=(const Point& point)
{
	(void)point;
	return (0);
}

Point::~Point()
{
}

/*
• a, b, c: The vertices of our beloved triangle.
• point: The point to check.
• Returns: True if the point is inside the triangle. False otherwise.
	Thus, if the point is a vertex or on edge, it will return False.
*/

Fixed	Point::getX(void)
{
	Fixed	tmp;

	tmp = this->x;
	return (tmp);
}

Fixed	Point::getY(void)
{
	Fixed	tmp;

	tmp = this->y;
	return (tmp);
}

bool	Point::compareVertex(Point const a, Point const b, Point const c, Point const point)
{
	if (a.getX() == point.getX())
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	return (1);
}