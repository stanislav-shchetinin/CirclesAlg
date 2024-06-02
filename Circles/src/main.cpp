#include <iostream>
#include <fstream>

#include "parser_xml.h"

void argc_check(int argc) {
	if (argc != 4) {
		throw std::invalid_argument("The arguments for running the program should look like:\n"
			"Circles <input-file.xml> <result.xml> <out.bmp>\n");
	}
}

int main(int argc, char* argv[]) {

	Field field;
	std::vector <Circle> circles;

	try {
		argc_check(argc);
		auto [field, circles] = parse_xml(argv[1]);
	}
	catch (const std::exception e) {
		std::cerr << e.what();
		return 1;
	}



	return 0;
}