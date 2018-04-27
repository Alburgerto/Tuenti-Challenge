#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/multiprecision/cpp_int.hpp>

int main() {
	std::ifstream input("Files/testInput_SecretNumbers.txt.");
	std::ofstream output("Files/testOutput_SecretNumbers.txt");
	int k = 1, cases, base;
	boost::multiprecision::uint1024_t minValue, maxValue;
//	unsigned long long minValue, maxValue;
	std::string line;
	input >> cases;
	input.ignore();
	for (int i = 1; i <= cases; ++i) {
		std::getline(input, line);
		base = line.length(); // base == number of chars in string
		minValue = (int)pow(base, base - 1); 
		maxValue = 0;
		for (int k = 0, j = base - 1; j >= 0; --j, ++k) {
			maxValue += j * (int)pow(base, j);
		}

		for (int k = 2; k < base; ++k) {
			minValue += k * (int)pow(base, base - k - 1);
		}
		output << "Case #" << i << ": " << maxValue - minValue << std::endl;
	}
}