#pragma once

#include "Point.h"

struct Rectangle {
	const Point min_point{};
	const Point max_point{};

	Rectangle() = default;
	Rectangle(const Point& min_point, const Point& max_point):min_point(min_point), max_point(max_point){}

};