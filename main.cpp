#include "input_parser.hpp"
#include <iostream>

/// \brief constants for command line options and program VERSION
namespace constants {
	constexpr auto HELP = "--help";
	constexpr auto HELP_SHORT = "-h";
	constexpr auto VERSION = "--version";
	constexpr auto VERSION_SHORT = "-v";

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

	if(input.cmdOptionExists(HELP, HELP_SHORT)) {
		std::cout << "Aux Bills Help" << '\n';
		std::cout << "Usage: aux-bill [options]" << '\n';
		std::cout << "Options:" << '\n';
		std::cout << "  -h, --help\t\t\tShow this HELP message and exit" << '\n';
		std::cout << "  -v, --version\t\t\tShow program's VERSION number and exit"
				  << '\n';
		exit(EXIT_SUCCESS);
	}

	if(input.cmdOptionExists(VERSION, VERSION_SHORT)) {
		std::cout << "Aux Bills Version: " << VERSION_MAJOR << "." << VERSION_MINOR << "."
				  << VERSION_PATCH << '\n';
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_SUCCESS);
}
