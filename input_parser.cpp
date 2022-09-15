//
// Created by Pedro Soares on 9/14/22.
//

#include "input_parser.hpp"
InputParser::InputParser(int &argc, char **argv) {
	for(int i = 1; i < argc; ++i) tokens.emplace_back(argv[i]);
}

const std::string &InputParser::getCmdOption(const std::string &option) const {
	static const std::string empty_string;

	auto itr = std::find(tokens.begin(), tokens.end(), option);
	if(itr != tokens.end() && ++itr != tokens.end()) return *itr;
	return empty_string;
}
bool InputParser::cmdOptionExists(const std::string &option) const {
	return std::find(tokens.begin(), tokens.end(), option) != tokens.end();
}
