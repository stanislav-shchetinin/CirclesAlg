#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

	std::cout << argv[1];
	std::ifstream in(argv[1]);
	
	if (in.is_open()) {
		std::cout << "Open!\n";
	}
	else {
		std::cout << "Not Open\n";
	}

	return 0;
}