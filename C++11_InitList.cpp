#include <iostream>
#include <vector>
#include <map>
#include <list>

int main() {
	// Initialize a Map of string & int using initializer_list
	std::map<std::string, int> mapOfMarks = { { "Riti", 2 }, { "Jack", 4 } };

	for (auto entry : mapOfMarks)
		std::cout << entry.first << " :: " << entry.second << std::endl;

	std::cout << std::endl;

	// Initialize a Map of string & vector of int using initializer_list
	std::map<std::string, std::vector<int> > mapOfOccur = 	{
		{ "Riti", { 3, 4, 5, 6 } },
		{ "Jack", { 1, 2, 3, 5 } }
	};

	// Iterating over the map
	for (auto entry : mapOfOccur) {
		std::cout << entry.first << " :: ";
		for (int i : entry.second)
			std::cout << i << " , ";
		std::cout << std::endl;
	}
	return 0;
}
