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

struct Fat {
	long long value1;
	long long value2;
	long long value3;
	long long value4;
	long long value5;
	long long value6;
	long long value7;
	long long value8;
	long long value9;
	long long value10;
	long long value11;
	long long value12;
	long long value13;
	long long value14;
	long long value15;
	long long value16;
	long long value17;
	long long value18;
};

void print_fat_size(Fat fat_p) {
	std::cout << "Size of fat_p: " << sizeof(fat_p) << '\n';
	fat_p.value1 = 1;
	std::cout << "Size of fat_p: " << sizeof(fat_p) << '\n';
	std::cout << "fat_p.value1: " << fat_p.value1 << '\n';
	std::cout << "&fat_p: " << &fat_p << "\n\n";
}

void print_fat_size_ptr(Fat *fat_ptr) {
	std::cout << "size of fat_ptr: " << sizeof(fat_ptr) << '\n';
	fat_ptr->value1 = 1;
	std::cout << "fat_ptr: " << fat_ptr << '\n';
	std::cout << "&fat: " << &fat_ptr << "\n\n";
}

void print_int(int i) {
	std::cout << "in print_int" << '\n';
	std::cout << "i: " << i << '\n';
	std::cout << "&i: " << &i << "\n\n";
}

void print_int_ptr(int *i_ptr) {
	std::cout << "in print_int_ptr" << '\n';
	std::cout << "i_ptr: " << i_ptr << '\n';
	std::cout << "&i_ptr: " << &i_ptr << '\n';
	std::cout << "*i_ptr: " << *i_ptr << "\n\n";
}

void print_bill(const Bill &bill) {
	std::cout << "Bill: $" << bill.value << '\n';
	std::cout << "People: " << bill.peopleAmount << '\n';
	std::cout << "Tip: $" << bill.value * 0.15 << '\n';
	std::cout << "Total: $" << bill.value * 1.15 << '\n';
	std::cout << "Per person: $" << (bill.value * 1.15) / bill.peopleAmount << '\n';
}

bool add_to_bill(Bill &bill, Bill &other) {
	if(other.value == 0 || other.peopleAmount == 0) return false;
	bill.value += other.value;
	bill.peopleAmount += other.peopleAmount;
	return true;
}

int main(int argc, char *argv[]) {
	using namespace constants;
	std::cout << "Hello, World!" << '\n';



	//	std::cout << "argc: " << argc << '\n';
	//	for(int i = 0; i < argc; i++) {
	//		std::cout << "argv num: " << i << " - " << argv[i] << '\n';
	//	}

	//	auto bill1 = new Bill{100, 2};
	//	auto bill2 = new Bill{200, 4};

	//	add_to_bill(*bill1, *bill2);

	//	int x = 1;
	//	std::cout << "x: " << x << '\n';
	//	std::cout << "&x: " << &x << '\n';
	//	print_int(x);
	//	print_int_ptr(&x);

	Fat fatoso{};
	std::cout << "&fatoso: " << &fatoso << '\n';
	std::cout << "sizeof(fatoso): " << sizeof(fatoso) << "\n\n";
	print_fat_size(fatoso);
	std::cout << "fatoso.value1: " << fatoso.value1 << '\n';
	print_fat_size_ptr(&fatoso);
	std::cout << "fatoso.value1: " << fatoso.value1 << '\n';


	exit(EXIT_SUCCESS);

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
