#include "input_parser.hpp"
#include <iostream>

/// \brief constants for command line options and program version
namespace constants {
	constexpr auto help = "--help";
	constexpr auto help_short = "-h";
	constexpr auto version = "--version";
	constexpr auto version_short = "-v";

	constexpr uint VERSION_MAJOR = 0;
	constexpr uint VERSION_MINOR = 1;
	constexpr uint VERSION_PATCH = 0;
}// namespace constants

struct Bill {
	int value;
	int peopleAmount;
};

int main(int argc, char *argv[]) {
	using namespace constants;
	std::cout << "Hello, World!" << '\n';

	std::cout << "argc: " << argc << '\n';
	for(int i = 0; i < argc; i++) {
		std::cout << "argv num: " << i << " - " << argv[i] << '\n';
	}

	InputParser input(argc, argv);

	if(input.cmdOptionExists(help_short, help)) {
		std::cout << "Aux Bills Help" << '\n';
		std::cout << "Usage: aux-bill [options]" << '\n';
		std::cout << "Options:" << '\n';
		std::cout << "  -h, --help\t\t\tShow this help message and exit" << '\n';
		std::cout << "  -v, --version\t\t\tShow program's version number and exit"
				  << '\n';
		exit(EXIT_SUCCESS);
	}

	if(input.cmdOptionExists(version_short, version)) {
		std::cout << "Aux Bills Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "."
				  << VERSION_PATCH << '\n';
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_SUCCESS);
}
