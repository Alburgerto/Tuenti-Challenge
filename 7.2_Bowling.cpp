#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

/*int main() {
	std::ifstream input("Files/testInput_bowling.txt");
	std::ofstream output("Files/testOutput_bowling.txt");

	int caseNumber, rollNumber, frameCount = 1, frameScore = 0, first, second, third;
	std::string line;
	input >> caseNumber;
	for (int i = 1; i <= caseNumber; ++i) {
		std::vector<int> caseScores;
		input >> rollNumber;

		std::getline(input, line);
		std::stringstream sstream(line);
		sstream >> first;
		sstream >> second;
		sstream >> third;
		output << rollNumber << std::endl;
		for (int j = 0; j < rollNumber; ) {
			output << first << second << third << std::endl;
			if (first == 10) {
				frameScore = first + second + third;
				first = second;
				second = third;
				sstream >> third;
				++j;
			} else if ((first + second) == 10) {
				frameScore = first + second + third;
				first = third;
				sstream >> second;
				sstream >> third;
				j += 2;
			} else {
				frameScore = first + second;
				j += 2;
			}
			caseScores.push_back(frameScore);
			++frameCount;
			if (frameCount > 10) { break; }
		}
		output << "Case #" << i << ": ";
		for (auto itr = caseScores.begin(); itr != caseScores.end(); ++itr) {
			output << *itr << " ";
		}
		output << std::endl;
	}
} */