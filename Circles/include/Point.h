#pragma once

struct Point {
	const int x{};
	const int y{};

	Point() = default;
	Point(int x, int y): x(x), y(y){}
};