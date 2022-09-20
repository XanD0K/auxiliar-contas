#include "input_parser.hpp"
#include <iostream>

/// \brief constants for command line options and program VERSION
namespace constants {
	const std::string HELP = "--help";
	const std::string HELP_SHORT = "-h";
	const std::string VERSION = "--version";
	const std::string VERSION_SHORT = "-v";

	constexpr uint VERSION_MAJOR = 0;
	constexpr uint VERSION_MINOR = 1;
	constexpr uint VERSION_PATCH = 0;

	const int flag_none = 1;
	const int flag_help = 1 << 1;
	const int flag_version = 1 << 2;
	const int flag_error = 1 << 3;
	const int flag_invalid = 1 << 4;

}// namespace constants

struct Bill {
	int value;
	int peopleAmount;
};

int main(int argc, char *argv[]) {
	using namespace constants;
	std::cout << "Hello, World!" << '\n';

	std::cout << "argc: " << argc << '\n';
	for(int i = 0; i < argc; ++i) {
		std::cout << "argv num: " << i << " - " << argv[i] << '\n';
	}

	bool help = false;
	int flag = 0;


	for(int i = 0; i < argc; ++i) {
		if(argv[i] == HELP || argv[i] == HELP_SHORT) {
			help = true;
			flag |= flag_help;
			break;
		}
	}

	for(int i = 0; i < argc; ++i) {
		if(argv[i] == VERSION || argv[i] == VERSION_SHORT) {
			flag |= flag_version;
			break;
		}
	}

	if(help) {
		std::cout << "Aux Bills Help" << '\n';
		std::cout << "Usage: aux-bill [options]" << '\n';
		std::cout << "Options:" << '\n';
		std::cout << "  -h, --help\t\t\tShow this HELP message and exit" << '\n';
		std::cout << "  -v, --version\t\t\tShow program's VERSION number and exit"
				  << '\n';
		exit(EXIT_SUCCESS);
	}

	if(flag & flag_version) {
		std::cout << "Aux Bills Version " << VERSION_MAJOR << '.' << VERSION_MINOR
				  << '.' << VERSION_PATCH << '\n';
		exit(EXIT_SUCCESS);
	}


	exit(EXIT_SUCCESS);
}
