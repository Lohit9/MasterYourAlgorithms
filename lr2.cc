#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <sstream>

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elements;
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elements.push_back(item);
	}
	return elements;
}

int main() {
	std::vector<std::string> rules;
	std::map<std::string, std::string> actions;

	std::string current_line;

	// skip symbol lists
	for (int i = 0; i < 2; ++i) {
		int skips;
		std::getline(std::cin, current_line);
		skips = atoi(current_line.c_str());
		while (skips-- > 0) {
			std::getline(std::cin, current_line);
		}
	}

	// skip start symbol
	std::getline(std::cin, current_line);

	// load rule vector
	int n;
	std::getline(std::cin, current_line);
	n = atoi(current_line.c_str());
	while (n-- > 0) {
		std::getline(std::cin, current_line);
		rules.push_back(current_line);
	}

	// load action map
	int dfa_states;
	std::getline(std::cin, current_line);
	dfa_states = atoi(current_line.c_str());

	std::getline(std::cin, current_line);
	n = atoi(current_line.c_str());

	while (n-- > 0) {
		std::getline(std::cin, current_line);
		std::vector<std::string> line_parts = split(current_line, ' ');
		std::string key = line_parts[0] + " " + line_parts[1];
		std::string value = line_parts[2] + " ";
		value += (value == "shift ") ? line_parts[3] : rules[atoi(line_parts[3].c_str())];
		actions[key] = value;
	}

	// run on input
	while (std::getline(std::cin, current_line)) {
		std::cout << ((actions.count(current_line)) ? actions[current_line] : "error") << std::endl;
	}

	return 0;
}
