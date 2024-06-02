#pragma once

#include <string>
#include <stdexcept>
#include "Field.h"
#include "Circle.h"
#include "Rectangle.h"
#include "pugixml/pugixml.hpp"

std::pair <Field, std::vector <Circle>> parse_xml(const std::string&);