#pragma once

#include "Point.h"

struct Circle {
	const int inner_rad;
	const int outter_rad;
	const Point center;

	Circle() = default;
	Circle(int inner_rad, int outter_rad): inner_rad(inner_rad), outter_rad(outter_rad){}
	Circle(int inner_rad, int outter_rad, const Point& center): inner_rad(inner_rad), outter_rad(outter_rad), center(center){}

};