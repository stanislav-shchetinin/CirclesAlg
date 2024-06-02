#pragma once

#include <vector>
#include "Rectangle.h"

struct Field {
	const Rectangle main;
	const std::vector<Rectangle> alarms;
};