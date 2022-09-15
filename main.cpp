#include "input_parser.hpp"
#include <iostream>

struct Bill {
	int value;
	int peopleAmount;
};

int main(int argc, char *argv[]) {
	std::cout << "Hello, World!" << '\n';

	std::cout << "argc: " << argc << '\n';
	for(int i = 0; i < argc; i++) {
		std::cout << "argv num: " << i << " - " << argv[i] << '\n';
	}

	InputParser input(argc, argv);

	if(input.cmdOptionExists("-h", "--help")) {
		std::cout << "Aux Bills Help" << '\n';
		std::cout << "Usage: aux-bill [options]" << '\n';
		std::cout << "Options:" << '\n';
		std::cout << "  -h, --help\t\t\tShow this help message and exit" << '\n';
		std::cout << "  -v, --version\t\t\tShow program's version number and exit"
				  << '\n';
	}

	return 0;
}
