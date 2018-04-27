#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	int cases, vertical, horizontal, holes;
	std::string line;
	std::ifstream input("Files/testInput_waffles.txt");
	std::ofstream output("Files/testOutput_waffles.txt");
	input >> cases;
	input.ignore();
	for (int i = 1; i <= cases; ++i) {
		std::getline(input, line);
		std::stringstream sstream(line);
		sstream >> vertical >> horizontal;
		holes = (vertical - 1) * (horizontal - 1);
		output << "Case #" << i << ": " << holes << std::endl;
	}
	return 0;
}
