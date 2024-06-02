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

	argc_check(argc);
	

	return 0;
}