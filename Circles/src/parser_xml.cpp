#include "parser_xml.h"
#include <iostream>

static Rectangle parse_main(const pugi::xml_node& rect) {
	return Rectangle{
		Point{
			rect.child("min_point").attribute("x").as_int(),
			rect.child("min_point").attribute("y").as_int()
		},
		Point{
			rect.child("max_point").attribute("x").as_int(),
			rect.child("max_point").attribute("y").as_int()
		}
	};
}

static std::vector <Rectangle> parse_alarms(const pugi::xml_node& alarms) {
	std::vector <Rectangle> res_alarms;
	for (const pugi::xml_node& tool : alarms.children("alarms")) {
		res_alarms.emplace_back(
			Point {
				tool.child("min_point").attribute("x").as_int(),
				tool.child("min_point").attribute("y").as_int()
			},
			Point {
				tool.child("max_point").attribute("x").as_int(),
				tool.child("max_point").attribute("y").as_int()
			}
		);
	}
	return res_alarms;
}

static Field parse_field(const pugi::xml_document& doc) {
	const pugi::xml_node& placement_zone = doc.child("data").child("placement_zone");
	const pugi::xml_node& rect = placement_zone.child("rect");
	const pugi::xml_node& alarms = placement_zone.child("alarms");

	Rectangle main = parse_main(rect);
	std::vector <Rectangle> vec_alarms = parse_alarms(alarms);

	return Field{ std::move(main), std::move(vec_alarms) };
}

static std::vector <Circle> parse_circles(const pugi::xml_document& doc) {

	std::vector <Circle> res_circles;
	const pugi::xml_node& circles = doc.child("data").child("circles");

	for (const pugi::xml_node& tool : circles.children("circle")) {
		res_circles.emplace_back(
			tool.attribute("inner_rad").as_int(),
			tool.attribute("outter_rad").as_int()
		);
	}
	return res_circles;
}

std::pair <Field, std::vector <Circle>> parse_xml(const std::string& file_name) {

	pugi::xml_document doc;
	const pugi::xml_parse_result& result = doc.load_file(file_name.c_str());

	if (!result) {
		throw std::invalid_argument("Error loading the XML file");
	}

	Field field = parse_field(doc);
	std::vector <Circle> circles = parse_circles(doc);

	return { std::move(field), std::move(circles) };
}