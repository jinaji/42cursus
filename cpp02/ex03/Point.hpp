#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{

private:
Fixed	const	x;
Fixed	const	y;

public:
	Point();
	Point(float x, float y);
	Point(const Point& point);
	Point(Fixed x, Fixed y);
	int	operator=(const Point& point);
	~Point();

	bool	compareVertex(Point const a, Point const b, Point const c, Point const point);
	Fixed	getX(void);
	Fixed	getY(void);
};

#endif