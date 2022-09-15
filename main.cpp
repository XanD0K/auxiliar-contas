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


	return 0;
}
